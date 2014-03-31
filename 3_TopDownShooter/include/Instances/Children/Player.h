////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#ifndef _PLAYER
#define _PLAYER

#include "AIE.h"

#include "GraphicItems/Texture.h"
#include "Maths/Vector2.h"

#include "Instances/Instance.h"
#include "Maps/Map1.h"

#include <math.h>

class cPlayer: public cInstance {
public:
	//Variables
	float fHealth;
	float fEnergy;
	//Constuctor
	cPlayer();
	//Member Functions
	void LoadPlayer();
	void Update(float fDeltaTime,unsigned int scrWidth, unsigned int scrHeight,cMap1 *Map);
	void Shadow();
	void Draw();
	void DrawHead();
	float GetMaxEnergy();
	float GetEnergy();
	void Cleanup();
private:
	//Textures
	cTexture Head;
	cTexture Body;
	cTexture Legs;
	//Variables
	float fSpeedMax;
	float fSpeed;
	float fEnergyMax;
	int m_x, m_y;
	//Movement Vector
	Vector2 sVector;
};

#endif

