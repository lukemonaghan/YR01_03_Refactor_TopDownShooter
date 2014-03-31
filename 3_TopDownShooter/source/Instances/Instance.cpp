////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																			\\
//																			Date:		23/04/2013																				\\
//																			Brief:		Game Manager																			\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#include "Instances\Instance.h"

cInstance::cInstance(){
	//Setup Vars
	fRot = 0.0f;
	vect.x=0.0f;
	vect.y=0.0f;
}
cInstance::cInstance(float Rot,float fX, float fY, float U,float V,float Uinc,float Vinc){
	//Setup Vars
	fRot   = 0.0f;
	vect.x = fX;
	vect.y = fY;
}