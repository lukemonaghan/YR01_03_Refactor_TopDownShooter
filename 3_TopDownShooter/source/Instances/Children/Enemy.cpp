////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//Headers
#include "Instances/Children/Enemy.h"

cEnemy::cEnemy(){
	//Player
	ucOpacity = 0;
	fSpeedMax = 0.0f;
	fSpeed = fSpeedMax;
	Health = 100;
}
cEnemy::cEnemy(unsigned int id,int iX, int iY){
	ucOpacity = 0;
	Sprite.uiSprite = id;
	vect.x = (float)iX;
	vect.y = (float)iY;
	Health = 100;
	//Player
	fSpeedMax = 350.0f;
	fSpeed = fSpeedMax;
	Sprite.UVInc.u = 0.125f;
	Sprite.UVInc.v = 0.125f;
}
//Constructors
unsigned int cEnemy::Create(){
	return CreateSprite("./images/instances/zombie_topdown.png",64,64,true);
}
bool cEnemy::Update(cPlayer &plr,cMap1 *Map,float dt){
	if (ucOpacity < 255){
		ucOpacity+=5;
	}
	tvect = 0.0f;
	if (Health <= 0){
		return true;
	}else{
	//Animation
	if (Sprite.AniTimer>0.1f){
		if (Sprite.UV.u >= 1.0f-Sprite.UVInc.u){
			Sprite.UV.u = Sprite.UVInc.u;
		}else{
			Sprite.UV.u+=Sprite.UVInc.u;
		}
		Sprite.AniTimer = 0.0f;
	}else{
		Sprite.AniTimer+=dt;
	}
	//setup the vector for player to self
	tvect.x = plr.vect.x - vect.x; 
	tvect.y = plr.vect.y - vect.y;
	//check it against walls
	check = Map->MapCheck(vect.x,vect.y,vect.x+(tvect.x),vect.y+(tvect.y));
	//if (check){//if there is a wall between us
	//	Map->NodeCheck(vect,plr.vect,&tvect);//find a node
	//}
	//make sure player and self dont overlap causing void jumps
	if (tvect.Magnitude() <  32.0f){
		plr.fHealth-=0.5;
	}
	if (tvect.x > -1.0f && tvect.x < 1.0f){tvect.x = 1.0f;}
	if (tvect.y > -1.0f && tvect.y < 1.0f){tvect.y = 1.0f;}
	// normalize for movement
	tvect.Normalize();
	//add speed and deltatime
	tvect*=fSpeed*dt;
	//check if new position isnt in or jumping through a wall
	check = Map->MapCheck(vect.x,vect.y,vect.x+(tvect.x*10),vect.y+(tvect.y*10));
	if (!check){
		//move self
		vect.x += tvect.x;
		vect.y += tvect.y;
	}else{
		//move self back
		vect.x -= tvect.x;
		vect.y -= tvect.y;
	}
	//setup this image direction
	fRot = 180.0f + atan2( tvect.x, tvect.y )* 180.0f / PI;
	return false;
	}
}
void cEnemy::Shadow(){
	//make the images black with little opacity
	SetSpriteColour(Sprite.uiSprite,SColour(0,0,0,50));
	//Draw the multiimage Shadow
	Sprite.DrawTex(vect.x+6,vect.y+6,fRot);														
	//Reset the players colours back to white(default)
	SetSpriteColour(Sprite.uiSprite,SColour(255,255,255,255));	
}
void cEnemy::Draw(){
	Shadow();
	SetSpriteUVCoordinates(Sprite.uiSprite,Sprite.UV.u,Sprite.UV.v,Sprite.UV.u+Sprite.UVInc.u,Sprite.UV.v+Sprite.UVInc.v);
	SetSpriteColour(Sprite.uiSprite,SColour(255,255,255,ucOpacity));
	Sprite.DrawTex(vect.x,vect.y,fRot);
}