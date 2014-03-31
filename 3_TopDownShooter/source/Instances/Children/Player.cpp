////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//Headers

#include "Instances/Children/Player.h"

using namespace std;

cPlayer::cPlayer(){
	//Player
	Cleanup();
}
void cPlayer::LoadPlayer(){
	Head.uiSprite = CreateSprite("./images/instances/Player/Heads.png",16,16,true);
	Head.UVInc.u = 0.125;
	Head.UVInc.v = 0.5;
	SetSpriteUVCoordinates(Head.uiSprite,Head.UV.u,Head.UV.v,Head.UVInc.u,Head.UVInc.v);
	Body.uiSprite = CreateSprite("./images/instances/Player/Bodys.png",64,64,true);
	Body.UVInc.u = 0.125;
	Body.UVInc.v = 0.5;
	SetSpriteUVCoordinates(Body.uiSprite,Body.UV.u,Body.UV.v,Body.UVInc.u,Body.UVInc.v);
	Legs.uiSprite = CreateSprite("./images/instances/Player/Legs.png",32,32,true);
	Legs.UVInc.u = 0.25;
	Legs.UVInc.v = 0.0625;
	SetSpriteUVCoordinates(Legs.uiSprite,Legs.UV.u,Legs.UV.v,Legs.UVInc.u,Legs.UVInc.v);
}
//Constructors
void cPlayer::Update(float fDeltaTime,unsigned int scrWidth, unsigned int scrHeight,cMap1 *Map){
	sVector = 0.0f;
	//Move Player
	GetMouseLocation( m_x, m_y );

	sVector.x = (m_x - (scrWidth*0.5f));
	sVector.y = (m_y - (scrHeight*0.5f));
    //player rotation
	fRot = -90 -atan2( sVector.y, sVector.x )* 180 / PI;
	sVector.Normalize();
	sVector*=fSpeed*fDeltaTime;
	if ( IsKeyDown(KEY_LSHIFT) && fEnergy >= 0.0f ){
		fEnergy-=0.5f;
		sVector*=1.5;
		Legs.AniTimer+=fDeltaTime*0.5f;
	}else if (fEnergy < fEnergyMax && !IsKeyDown(KEY_LSHIFT)){
		fEnergy+=0.55f;
	}
	if ( IsKeyDown('W') ){
		bool col = Map->MapCheck(vect.x,vect.y,vect.x+(sVector.x*10),vect.y+(sVector.y*10));
		if (!col){	
			vect.x += sVector.x;
			vect.y += sVector.y;
			Legs.AniTimer+=fDeltaTime;
		}else{
			vect.x -= sVector.x;
			vect.y -= sVector.y;
			Legs.AniTimer-=fDeltaTime;
		}
	}else if ( IsKeyDown('S')){
		sVector *= -1;
		bool col = Map->MapCheck(vect.x,vect.y,vect.x+(sVector.x*4),vect.y+(sVector.y*4));
		if (!col){
			vect.x += sVector.x;	
			vect.y += sVector.y;
			Legs.AniTimer-=fDeltaTime;
		}else{
			vect.x -= sVector.x;
			vect.y -= sVector.y;
			Legs.AniTimer+=fDeltaTime;
		}
	}if ( IsKeyDown('A') ){
		sVector.RotateDegree(-90);
		bool col = Map->MapCheck(vect.x,vect.y,vect.x+(sVector.x*4),vect.y+(sVector.y*4));
		if (!col){
			sVector/=2;
			vect.x += sVector.x;
			vect.y += sVector.y;
			Legs.AniTimer+=fDeltaTime;
		}else{
			vect.x -= sVector.x;
			vect.y -= sVector.y;
			Legs.AniTimer-=fDeltaTime;
		}
	}else if ( IsKeyDown('D') ){
		sVector.RotateDegree(90);
		bool col = Map->MapCheck(vect.x,vect.y,vect.x+(sVector.x*4),vect.y+(sVector.y*4));
		if (!col){
			sVector/=2;
			vect.x += sVector.x;	
			vect.y += sVector.y;
			Legs.AniTimer+=fDeltaTime;
		}else{
			vect.x -= sVector.x;
			vect.y -= sVector.y;
			Legs.AniTimer-=fDeltaTime;
		}
	}
	if (Legs.AniTimer > 0.1f){
		Legs.UV.u+=Legs.UVInc.u;
		if (Legs.UV.u>1.0f){Legs.UV.u = 0.0f;}
		Legs.AniTimer = 0.0f;
	}else if (Legs.AniTimer < -0.1f){
		Legs.UV.u-=Legs.UVInc.u;
		if (Legs.UV.u<0.0f){Legs.UV.u = 1.0f-Legs.UVInc.u;}
		Legs.AniTimer = 0.0f;
	}
	Draw();
	MoveCamera(vect.x-(scrWidth*0.5f),vect.y-(scrHeight*0.5f));
}

float cPlayer::GetMaxEnergy(){
	return fEnergyMax;
}
float cPlayer::GetEnergy(){
	return fEnergy;
}
void cPlayer::Shadow(){
	//make the images black with little opacity
	SetSpriteColour(Legs.uiSprite,SColour(0,0,0,50));
	SetSpriteColour(Body.uiSprite,SColour(0,0,0,50));
	SetSpriteColour(Head.uiSprite,SColour(0,0,0,50));
	//Draw the multiimage Shadow
	Legs.DrawTex(vect.x,vect.y,fRot);														
	Body.DrawTex(vect.x+3 ,vect.y+3 ,fRot);														
	Body.DrawTex(vect.x+6 ,vect.y+6 ,fRot);	
	Head.DrawTex(vect.x+9 ,vect.y+9 ,fRot);
	Head.DrawTex(vect.x+12,vect.y+12,fRot);
	//Reset the players colours back to white(default)
	SetSpriteColour(Legs.uiSprite,SColour(255,255,255,255));
	SetSpriteColour(Body.uiSprite,SColour(255,255,255,255));
	SetSpriteColour(Head.uiSprite,SColour(255,255,255,255));	
}
void cPlayer::Draw(){
	SetSpriteUVCoordinates(Legs.uiSprite,Legs.UV.u,Legs.UV.v,Legs.UV.u+Legs.UVInc.u,Legs.UV.v+Legs.UVInc.v);														
	Legs.DrawTex(vect.x,vect.y,fRot);														
	SetSpriteUVCoordinates(Body.uiSprite,Body.UV.u,Body.UV.v,Body.UV.u+Body.UVInc.u,Body.UV.v+Body.UVInc.v);
	Body.DrawTex(vect.x,vect.y-2,fRot);														
	Body.DrawTex(vect.x,vect.y-4,fRot);														
}
void cPlayer::DrawHead(){
	SetSpriteUVCoordinates(Head.uiSprite,Head.UV.u,Head.UV.v,Head.UV.u+Head.UVInc.u,Head.UV.v+Head.UVInc.v);
	Head.DrawTex(vect.x,vect.y-6,fRot);
	Head.DrawTex(vect.x,vect.y-8,fRot);
}

void cPlayer::Cleanup(){
	vect.x = 0;
	vect.y = 0;
	//Player
	fSpeedMax = 500.0f;
	fSpeed = fSpeedMax;
	fEnergyMax = 100;
	fEnergy = 100;
	fHealth = 100;
}
//EOF