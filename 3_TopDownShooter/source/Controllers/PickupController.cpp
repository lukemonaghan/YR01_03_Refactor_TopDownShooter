
#include "Controllers/PickupController.h"

void cPickupController::Setup(int Pickups){
	iPickups = Pickups;
	Health.uiSprite      = CreateSprite("./images/instances/Health.png"    , 16, 16, true );
	Health.UV.u    = 0.0f;
	Health.UV.v    = 0.0f;
	Health.UVInc.u = 0.25f;	
	Health.UVInc.v = 1.0f;
	FloorItems.uiSprite  = CreateSprite("./images/instances/FloorItems.png", 16, 16, true );
	FloorItems.UV.u    = 0.0f;	
	FloorItems.UV.v    = 0.0f;
	FloorItems.UVInc.u = 0.125f;
	FloorItems.UVInc.v = 1.0f;
	Ammo.uiSprite        = CreateSprite("./images/instances/Clips.png"     , 16, 16, true );
	Ammo.UV.u    = 0.0f;	
	Ammo.UV.v    = 0.0f;
	Ammo.UVInc.u = 0.09f;	
	Ammo.UVInc.v = 1.0f;
}
void cPickupController::GenPickup(){
	pickup = rand()%3+1;
	itemID = 1;
	switch(pickup){
	case 1:
		CurrentTex  = &Health;
		Health.UV.u =  Health.UVInc.u*(rand()%4);
		itemID      = (Health.UV.u*4)+1;
		break;
	case 2:
		CurrentTex       = &FloorItems;
		FloorItems.UV.u  =  FloorItems.UVInc.u*(rand()%8);
		itemID           = (FloorItems.UV.u*8)+4;
		break;
	case 3:
		CurrentTex = &Ammo;
		Ammo.UV.u  =  Ammo.UVInc.u*(rand()%11);
		itemID     = (Ammo.UV.u*11)+12;
		break;
	};
}
void cPickupController::CreatePickup(){
	GenPickup();
	vPickups.push_back(cPickup(*CurrentTex,(rand()%2048)-1024.0f,(rand()%2048)-1024.0f,itemID));
}
void cPickupController::CreatePickup(const Vector2 &Pos){	
	GenPickup();
	vPickups.push_back(cPickup(*CurrentTex,Pos.x,Pos.y,itemID));
}
unsigned int cPickupController::GetSize(){
	return vPickups.size();
}

void cPickupController::Update(cPlayer *plr,const cWeaponController *wepcon){
	if (GetSize() < iPickups){
		CreatePickup();
		if (iPickups > 0){iPickups--;}
	}
	std::vector<cPickup>::iterator i = vPickups.begin();
	while (i!=vPickups.end()) {
       cPickup bul = *i;
		int action = i->Check(plr->vect);
		if (action > 0){
			RunAction(plr,wepcon,action);
			i = vPickups.erase(i);
			if (iPickups > 0) {--iPickups;}
		}else{
		i++; 
		}
    }
}
void cPickupController::RunAction(cPlayer *plr,const cWeaponController *wepcon,int actionID){
	switch(actionID){
	////////////////health/speed
                case 1:
					plr->fHealth+=50;
                    break;
                case 2:
                    plr->fHealth+=25;
                    break;
                case 3:
                    plr->fEnergy+=50;
                    break;
				case 4:
					plr->fEnergy+=25;
					break;
////////////////flooritems(random risky food coins paper phones)
				case 5:
					plr->fHealth+=(rand()%10+1)-5;
					break;
				case 6:
					plr->fHealth+=(rand()%20+1)-10;
					break;
				case 7:
					plr->fHealth+=(rand()%15+1)-7;
					break;
				case 8:
					plr->fHealth+=(rand()%30+1)-15;
					break;
				case 9:
					plr->fHealth+=(rand()%25+1)-20;
					break;
				case 10:
					plr->fHealth+=(rand()%10+1)-5;
					break;
				case 11:
					plr->fHealth+=(rand()%50+1)-10;
					break;
				case 12:
					iPickups+=10;
					break;
////////////////ammo
				/*
				case 13:
					sGunLMG.iClips++;
					break;
				case 14:
					sGunAssult.iClips++;
					break;
				case 15:
					sGunLAW.iClips++;
					break;
				case 16:
					sGunSniper.iClips++;
					break;
				case 17:
					sGunSMG.iClips++;
					break;
				case 18:
					sGunRPG.iClips++;
					break;
				case 19:
					sGunLMG2.iClips++;
					break;
				case 20:
					sGunAKu.iClips++;
					break;
				case 21:
					sGunLMG3.iClips++;
					break;
				case 22:
					sGunAK.iClips++;
					break;
				case 23:
					sGunRPG2.iClips++;
					break;
					*/
				}
}
void cPickupController::Draw(){
	std::vector<cPickup>::iterator i = vPickups.begin();
	while (i!=vPickups.end()) {
		i->Draw();
		i++; 
    }
};

void cPickupController::Cleanup(){
	vPickups.clear();
}