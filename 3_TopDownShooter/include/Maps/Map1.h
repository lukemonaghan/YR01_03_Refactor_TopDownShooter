////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																					\\
//																			Date:		06/05/2013																						\\
//																			Brief:		Map Parent																						\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#ifndef _MAP1_H_
#define _MAP1_H_

#include "AIE.h"
#include "Collisions.h"
#include "Maths/Vector2.h"

#include <cmath>

class cMap1{
public:
	cMap1();
	void MapCreate();
	void Node(int &curl,int &curl2,float f1_x, float f1_y,const Vector2 &self,const Vector2 &other,Vector2 *pos);
	bool MapCheck(float fX, float fY,float fNX, float fNY);
	void NodeCheck(const Vector2 &self,const Vector2 &other,Vector2 *pos);
	void DrawLines();
	void MapDraw(const Vector2 &player,float rad);
private:
	Vector2 LengthCheck;
	int xoff,yoff;
	unsigned int uiMapTiles[14];
	int iX, iY;
};

#endif
/*
int Map[42][30];
*/