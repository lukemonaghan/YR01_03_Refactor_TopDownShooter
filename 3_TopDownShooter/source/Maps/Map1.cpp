////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																					\\
//																			Date:		06/05/2013																						\\
//																			Brief:		Map Parent																						\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#include "Maps/map1.h"

Vector2 check(0.0f,0.0f);
Vector2 check2(0.0f,0.0f);

unsigned int uiMapArray[30][42] =			{   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,3,3,3,3,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,2,2,2,2,2,2,2,2,2,2,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,5,5,5,2,2,2,2,5,5,5,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
												
												{0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,5,4,2,2,4,5,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,6,6,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,6,6,6,6,6,0,0,0,0,0},
												{0,0,0,0,0,6,0,0,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,0,0,6,0,0,0,0,0},
												{0,0,0,0,0,6,6,0,2,2,4,5,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,4,2,2,0,6,6,6,0,0,0,0},
												{0,0,0,0,0,6,6,0,2,2,4,5,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,4,2,2,0,6,6,6,0,0,0,0},
												{0,0,0,0,0,6,0,0,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,0,0,6,0,0,0,0,0},
												{0,0,0,0,0,6,6,6,6,6,6,6,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,6,6,6,6,6,6,6,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,5,4,2,2,4,5,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
												
												{0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,5,5,5,2,2,2,2,5,5,5,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,2,2,2,2,2,2,2,2,2,2,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,3,3,3,3,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
											};
																																					/*
unsigned int  uiMapArrayOverlay[30][42] =	{   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        
											    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        
											    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
											};
																																					*/
cMap1::cMap1(){
	iX = iY = 0;
}
void cMap1::MapCreate(){
	uiMapTiles[0]  = CreateSprite( "./images/maps/Tiles/Carpet.png"        , 128 , 128 , false );
	uiMapTiles[1]  = CreateSprite( "./images/maps/Tiles/Concrete.png"      , 128 , 128 , false );
	uiMapTiles[2]  = CreateSprite( "./images/maps/Tiles/concretestairs.png", 128 , 128 , false );
	uiMapTiles[3]  = CreateSprite( "./images/maps/Tiles/Dirt.png"          , 128 , 128 , false );
	uiMapTiles[4]  = CreateSprite( "./images/maps/Tiles/dirtcorner.png"    , 128 , 128 , false );
	uiMapTiles[5]  = CreateSprite( "./images/maps/Tiles/dirtend.png"       , 128 , 128 , false );
	uiMapTiles[6]  = CreateSprite( "./images/maps/Tiles/dirtstriaght.png"  , 128 , 128 , false );
	uiMapTiles[7]  = CreateSprite( "./images/maps/Tiles/Grass.png"         , 128 , 128 , false );
	uiMapTiles[8]  = CreateSprite( "./images/maps/Tiles/Paved.png"         , 128 , 128 , false );
	uiMapTiles[9]  = CreateSprite( "./images/maps/Tiles/Tiles.png"         , 128 , 128 , false );
	uiMapTiles[10] = CreateSprite( "./images/maps/Tiles/Wood.png"          , 128 , 128 , false );
	uiMapTiles[11] = CreateSprite( "./images/maps/Tiles/WoodStairs.png"    , 128 , 128 , false );
	uiMapTiles[12] = CreateSprite( "./images/maps/Tiles/map1_Walls.png"    , 5376, 3840, true );

	for (int r = 0; r < 30; r++){
		for (int c = 0; c < 42; c++){
			switch (uiMapArray[r][c]){
			case 0:uiMapArray[r][c] = uiMapTiles[7] ;break;
			case 1:uiMapArray[r][c] = uiMapTiles[1] ;break;
			case 2:uiMapArray[r][c] = uiMapTiles[0] ;break;
			case 3:uiMapArray[r][c] = uiMapTiles[9] ;break;
			case 4:uiMapArray[r][c] = uiMapTiles[11];break;
			case 5:uiMapArray[r][c] = uiMapTiles[10];break;
			case 6:uiMapArray[r][c] = uiMapTiles[8];break;
			}
																				/*
			switch (uiMapArrayOverlay[r][c]){
			case 1:uiMapArrayOverlay[r][c] = uiMapTiles[4];break;
			case 2:uiMapArrayOverlay[r][c] = uiMapTiles[5];break;
			case 3:uiMapArrayOverlay[r][c] = uiMapTiles[6];break;
			}
																				*/
		}
	}
}
void cMap1::Node(int &curl,int &curl2,float f1_x, float f1_y,const Vector2 &self,const Vector2 &other,Vector2 *pos){
	int l , l2 = 0;

	check.x  = f1_x - self.x;
	check.y  = f1_y - self.y;

	//check2.x = f1_x - other.x;
	//check2.y = f1_y - other.y;

	//DrawLine(f1_x-4,f1_y-4,f1_x+4,f1_y+4,SColour(0,255,0,50));
	//DrawLine(f1_x+4,f1_y-4,f1_x-4,f1_y+4,SColour(0,255,0,50));

	//DrawLine(self.x,self.y,f1_x,f1_y,SColour(255,0,0,50));

	l = (int)abs(check.Magnitude());
	//l2 = abs(check2.Magnitude());

	curl  = abs(curl );
	//curl2 = abs(curl2);

	if (curl>=l && l>=64){ 
		pos->x = check.x;
		pos->y = check.y;
		curl = l ;
	}
	//if (curl2>=l2 && l2>=64){ 
	//	pos->x =  check2.x;
	//	pos->y =  check2.y;
	//	curl2  = l2 ;
	//}
}

bool cMap1::MapCheck(float fX, float fY,float fNX, float fNY){
//top left stairs
	if (CheckLine( 128.0f,-640.0f, 256.0f,-640.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 256.0f,-768.0f, 256.0f,-640.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 256.0f,-768.0f, 640.0f,-768.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 640.0f,-768.0f, 640.0f,-512.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 640.0f,-512.0f, 768.0f,-512.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 384.0f,-640.0f, 640.0f,-640.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 384.0f,-640.0f, 384.0f,-512.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 128.0f,-512.0f, 384.0f,-512.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
//top left kitchen										  	  	  			  			    
	if (CheckLine( 896.0f,-512.0f,1024.0f,-512.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine(1024.0f,-896.0f,1024.0f,-512.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 768.0f,-640.0f,1024.0f,-640.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 768.0f,-896.0f,1024.0f,-896.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
	if (CheckLine( 768.0f,-768.0f, 768.0f,-640.0f, fX, fY, (float)fNX, (float)fNY)) {return true;}
//top room
	//left
	if (CheckLine(256,-1024,768,-1024,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(256,-1024,256,-896 ,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(256,-1280,256,-1160,fX,fY,(float)fNX,(float)fNY)){return true;}
	//middle
	if (CheckLine(-128,-896 ,+128,-896 ,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,-1280,+256,-1280,fX,fY,(float)fNX,(float)fNY)){return true;}
	//right
	if (CheckLine(-768,-1024,-256,-1024,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,-1024,-256,-896 ,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,-1280,-256,-1160,fX,fY,(float)fNX,(float)fNY)){return true;}
//top right stairs 
	if (CheckLine(-256,-640,-128,-640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,-768,-256,-640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-640,-768,-256,-768,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-640,-768,-640,-512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-768,-512,-640,-512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-640,-640,-384,-640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-384,-640,-384,-512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-384,-512,-128,-512,fX,fY,(float)fNX,(float)fNY)){return true;}
 //top right kitchen
	if (CheckLine(-1024,-512,-896 ,-512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1024,-896,-1024,-512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1024,-640,-768 ,-640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1024,-896,-768 ,-896,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-768 ,-768,-768 ,-640,fX,fY,(float)fNX,(float)fNY)){return true;}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////MIDDLE
//middle left room
	//top
	if (CheckLine(-1024,-256,-1024,-128,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1664,-256,-1024,-256,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1408,-128,-1152,-128,fX,fY,(float)fNX,(float)fNY)){return true;}
//middle
	if (CheckLine(-1152,-128,-1152,+128,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1664,-256,-1664,+256,fX,fY,(float)fNX,(float)fNY)){return true;}
//bottom
	if (CheckLine(-1024,+128,-1024,+256,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1664,+256,-1024,+256,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1408,+128,-1152,+128,fX,fY,(float)fNX,(float)fNY)){return true;}
//middle right room
//top
	if (CheckLine(+1024,-256,+1024,-128,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+1024,-256,+1664,-256,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+1152,-128,+1408,-128,fX,fY,(float)fNX,(float)fNY)){return true;}
//middle		   		  	
	if (CheckLine(+1152,-128,+1152,+128,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+1664,-256,+1664,+256,fX,fY,(float)fNX,(float)fNY)){return true;}
//bottom		   		  	
	if (CheckLine(+1024,+128,+1024,+256,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+1024,+256,+1664,+256,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+1152,+128,+1408,+128,fX,fY,(float)fNX,(float)fNY)){return true;}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////BOTTOM
//Bottom left stairs
	if (CheckLine(+128,+640,+256,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+256,+640,+256,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+256,+768,+640,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+640,+512,+640,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+640,+512,+768,+512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+384,+640,+640,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+384,+512,+384,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+128,+512,+384,+512,fX,fY,(float)fNX,(float)fNY)){return true;}
//Bottom left kitchen
	if (CheckLine(+896 ,+512,+1024,+512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+1024,+512,+1024,+896,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+768 ,+640,+1024,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+768 ,+896,+1024,+896,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+768 ,+640,+768 ,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
//Bottom room
//left
	if (CheckLine(+256,+1024,+768,+1024,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+256,+896 ,+256,+1024,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(+256,+1160,+256,+1280,fX,fY,(float)fNX,(float)fNY)){return true;}
//middle
	if (CheckLine(-128,+896 ,+128,+896 ,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,+1280,+256,+1280,fX,fY,(float)fNX,(float)fNY)){return true;}
//right
	if (CheckLine(-768,+1024,-256,+1024,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,+896 ,-256,+1024,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,+1160,-256,+1280,fX,fY,(float)fNX,(float)fNY)){return true;}
//Bottom right stairs
	if (CheckLine(-256,+640,-128,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-256,+640,-256,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-640,+768,-256,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-640,+512,-640,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-768,+512,-640,+512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-640,+640,-384,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-384,+512,-384,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-384,+512,-128,+512,fX,fY,(float)fNX,(float)fNY)){return true;}
 //Bottom right kitchen	
	if (CheckLine(-1024,+512,-896 ,+512,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1024,+512,-1024,+896,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1024,+640,-768 ,+640,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-1024,+896,-768 ,+896,fX,fY,(float)fNX,(float)fNY)){return true;}
	if (CheckLine(-768 ,+640,-768 ,+768,fX,fY,(float)fNX,(float)fNY)){return true;}
	return false;
}
void cMap1::NodeCheck(const Vector2 &self,const Vector2 &other,Vector2 *pos){
	int iCurlength , iCL2 = 99999999;
//////////////////////////////////////////////////////////////////////////////////Start LengthChecks
//top
	Node(iCurlength,iCL2,  128.0f, -576.0f,self,other,pos);
	Node(iCurlength,iCL2, -128.0f, -576.0f,self,other,pos);

	Node(iCurlength,iCL2,  192.0f, -900.0f,self,other,pos);
	Node(iCurlength,iCL2, -192.0f, -900.0f,self,other,pos);

	Node(iCurlength,iCL2,  768.0f, -960.0f,self,other,pos);
	Node(iCurlength,iCL2, -768.0f, -960.0f,self,other,pos);

	Node(iCurlength,iCL2,  832.0f, -512.0f,self,other,pos);
	Node(iCurlength,iCL2, -832.0f, -512.0f,self,other,pos);

	Node(iCurlength,iCL2,  256.0f,-1080.0f,self,other,pos);
	Node(iCurlength,iCL2, -256.0f,-1080.0f,self,other,pos);

	Node(iCurlength,iCL2,  320.0f,-1344.0f,self,other,pos);
	Node(iCurlength,iCL2, -320.0f,-1344.0f,self,other,pos);

//middle
	Node(iCurlength,iCL2, 1088.0f,-128.0f,self,other,pos);
	Node(iCurlength,iCL2,-1088.0f,-128.0f,self,other,pos);

	Node(iCurlength,iCL2, 1408.0f,    0.0f,self,other,pos);
	Node(iCurlength,iCL2,-1408.0f,    0.0f,self,other,pos);
//bottom
	Node(iCurlength,iCL2,  256.0f, 1080.0f,self,other,pos);
	Node(iCurlength,iCL2, -256.0f, 1080.0f,self,other,pos);

	Node(iCurlength,iCL2,  832.0f,  512.0f,self,other,pos);
	Node(iCurlength,iCL2, -832.0f,  512.0f,self,other,pos);

	Node(iCurlength,iCL2,  768.0f,  960.0f,self,other,pos);
	Node(iCurlength,iCL2, -768.0f,  960.0f,self,other,pos);

	Node(iCurlength,iCL2,  192.0f, 900.0f,self,other,pos);
	Node(iCurlength,iCL2, -192.0f, 900.0f,self,other,pos);

	Node(iCurlength,iCL2,  128.0f, 576.0f,self,other,pos);
	Node(iCurlength,iCL2, -128.0f, 576.0f,self,other,pos);
}

void cMap1::DrawLines(){
	//top left stairs
	DrawLine(128,-640, 256,-640);
	DrawLine(256,-768, 256,-640);
	DrawLine(256,-768, 640,-768);
	DrawLine(640,-768, 640,-512);
	DrawLine(640,-512, 768,-512);
	DrawLine(384,-640, 640,-640);
	DrawLine(384,-640, 384,-512);
	DrawLine(128,-512, 384,-512);							  	  	  			  			    
	DrawLine( 896,-512,1024,-512);
	DrawLine(1024,-896,1024,-512);
	DrawLine( 768,-640,1024,-640);
	DrawLine( 768,-896,1024,-896);
	DrawLine( 768,-768, 768,-640);
	DrawLine(256,-1024,768,-1024);
	DrawLine(256,-1024,256,-896 );
	DrawLine(256,-1280,256,-1160);
	DrawLine(-128,-896 ,+128,-896 );
	DrawLine(-256,-1280,+256,-1280);
	DrawLine(-768,-1024,-256,-1024);
	DrawLine(-256,-1024,-256,-896 );
	DrawLine(-256,-1280,-256,-1160);
	DrawLine(-256,-640,-128,-640);
	DrawLine(-256,-768,-256,-640);
	DrawLine(-640,-768,-256,-768);
	DrawLine(-640,-768,-640,-512);
	DrawLine(-768,-512,-640,-512);
	DrawLine(-640,-640,-384,-640);
	DrawLine(-384,-640,-384,-512);
	DrawLine(-384,-512,-128,-512);
	DrawLine(-1024,-512,-896 ,-512);
	DrawLine(-1024,-896,-1024,-512);
	DrawLine(-1024,-640,-768 ,-640);
	DrawLine(-1024,-896,-768 ,-896);
	DrawLine(-768 ,-768,-768 ,-640);
	DrawLine(-1024,-256,-1024,-128);
	DrawLine(-1664,-256,-1024,-256);
	DrawLine(-1408,-128,-1152,-128);
	DrawLine(-1152,-128,-1152,+128);
	DrawLine(-1664,-256,-1664,+256);
	DrawLine(-1024,+128,-1024,+256);
	DrawLine(-1664,+256,-1024,+256);
	DrawLine(-1408,+128,-1152,+128);
	DrawLine(+1024,-256,+1024,-128);
	DrawLine(+1024,-256,+1664,-256);
	DrawLine(+1152,-128,+1408,-128);		   		  	
	DrawLine(+1152,-128,+1152,+128);
	DrawLine(+1664,-256,+1664,+256);	   		  	
	DrawLine(+1024,+128,+1024,+256);
	DrawLine(+1024,+256,+1664,+256);
	DrawLine(+1152,+128,+1408,+128);
	DrawLine(+128,+640,+256,+640);
	DrawLine(+256,+640,+256,+768);
	DrawLine(+256,+768,+640,+768);
	DrawLine(+640,+512,+640,+768);
	DrawLine(+640,+512,+768,+512);
	DrawLine(+384,+640,+640,+640);
	DrawLine(+384,+512,+384,+640);
	DrawLine(+128,+512,+384,+512);
	DrawLine(+896 ,+512,+1024,+512);
	DrawLine(+1024,+512,+1024,+896);
	DrawLine(+768 ,+640,+1024,+640);
	DrawLine(+768 ,+896,+1024,+896);
	DrawLine(+768 ,+640,+768 ,+768);
	DrawLine(+256,+1024,+768,+1024);
	DrawLine(+256,+896 ,+256,+1024);
	DrawLine(+256,+1160,+256,+1280);
	DrawLine(-128,+896 ,+128,+896 );
	DrawLine(-256,+1280,+256,+1280);
	DrawLine(-768,+1024,-256,+1024);
	DrawLine(-256,+896 ,-256,+1024);
	DrawLine(-256,+1160,-256,+1280);
	DrawLine(-256,+640,-128,+640  );
	DrawLine(-256,+640,-256,+768  );
	DrawLine(-640,+768,-256,+768  );
	DrawLine(-640,+512,-640,+768  );
	DrawLine(-768,+512,-640,+512  );
	DrawLine(-640,+640,-384,+640  );
	DrawLine(-384,+512,-384,+640  );
	DrawLine(-384,+512,-128,+512  );
	DrawLine(-1024,+512,-896 ,+512);
	DrawLine(-1024,+512,-1024,+896);
	DrawLine(-1024,+640,-768 ,+640);
	DrawLine(-1024,+896,-768 ,+896);
	DrawLine(-768 ,+640,-768 ,+768);

}
void cMap1::MapDraw(const Vector2 &player,float rad){
	xoff = (42*128/2)-128;
	yoff = (30*128/2)-128;
	for (int r = 0; r < 30; r++){
		for (int c = 0; c < 42; c++){
			LengthCheck.x = player.x - (iX-(128*c)+(xoff));
			LengthCheck.y = player.y - (iY-(128*r)+(yoff));
			if (LengthCheck.Magnitude() < rad){
				MoveSprite  ( uiMapArray[r][c],(float)iX-(128*c)+(xoff), (float)iY-(128*r)+(yoff));
				DrawSprite  ( uiMapArray[r][c]);
																															/*
				if (uiMapArrayOverlay[r][c]!=0){
				MoveSprite  ( uiMapArrayOverlay[r][c],(float)iX-(128*c)+(xoff), (float)iY-(128*r)+(yoff));
				DrawSprite  ( uiMapArrayOverlay[r][c]);
				}
																															*/
			}
		}
	}
	MoveSprite( uiMapTiles[12], (float)iX, (float)iY);	DrawSprite( uiMapTiles[12]);
}