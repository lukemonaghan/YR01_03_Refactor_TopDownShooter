#ifndef _PICKUPCON_H_
#define _PICKUPCON_H_

#include "AIE.h"

#include "Instances/Children/Pickup.h"
#include "Instances/Children/Player.h"
#include "GraphicItems/Texture.h"

#include "Controllers/WeaponController.h"
#include "GlobalFunctions.h"

#include <vector>

class cPickupController{
public:
	cPickupController(){};
	void Setup(int Pickups = 1);
	void GenPickup();
	void CreatePickup();
	void CreatePickup(const Vector2 &Pos);
	void Update(cPlayer *plr,const cWeaponController *wepcon);
	void RunAction(cPlayer *plr,const cWeaponController *wepcon,int actionID);
	void Draw();
	unsigned int GetSize();
	void Cleanup(); 
	unsigned int iPickups;
private:
	cTexture Health,Ammo,FloorItems,*CurrentTex;
	std::vector <cPickup> vPickups;
	int pickup,itemID;
};



#endif
