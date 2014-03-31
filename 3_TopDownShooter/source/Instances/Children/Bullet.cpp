////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//Headers
#include "Instances/Children/Bullet.h"

cBullet::cBullet(){
	//Player
	fSpeed = 0.0f;
	iDamage = 25;
}
cBullet::cBullet(unsigned int id,int iX, int iY,float dir,int damage,float spd){
	vDir.degreeToVect(-dir - 90.0f);
	vect.x = iX;
	vect.y = iY;
	fRot  = dir;
	//Player
	fSpeed = spd;
	Sprite.uiSprite = id;
	Sprite.UVInc.u  = 0.09f;
	Sprite.UVInc.v  = 1.0f;
	Sprite.UV.u     = Sprite.UVInc.u;
	Sprite.UV.v     = 0.0f;
	Sprite.AniTimer = 0.0f;
	iDamage         = damage;
	
}
//Constructors
unsigned int cBullet::Create(){
	return CreateSprite("./images/instances/Bullets.png",16,16,true);
}
int cBullet::Update(const float &dt,cMap1 *ThisMap){
	if (Sprite.AniTimer > 1.0f || ThisMap->MapCheck(vect.x,vect.y,vect.x+(vDir.x*fSpeed*dt),vect.y+(vDir.y*fSpeed*dt))){
		return 2;
	}else{
		vect.x += vDir.x*fSpeed*dt;
		vect.y += vDir.y*fSpeed*dt;
		Sprite.AniTimer+=dt;
		return 0;
	}
}
void cBullet::Draw(){
	SetSpriteUVCoordinates(Sprite.uiSprite,Sprite.UV.u,Sprite.UV.v,Sprite.UV.u+Sprite.UVInc.u,Sprite.UV.v+Sprite.UVInc.v);
	Sprite.DrawTex(vect.x,vect.y,fRot);
}
//EOF