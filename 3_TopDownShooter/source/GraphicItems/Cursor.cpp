#include "GraphicItems/Cursor.h"

void cCursor::Load(){
	 Cursor.uiSprite = CreateSprite( "./images/cursor.png", 32, 32, true );	
}
void cCursor::Update(){
	GetMouseLocation(iX,iY);
}
void cCursor::GetPos(int &ix,int &iy){
	ix = iX;
	iy = iY;
}
void cCursor::Draw(float fx,float fy){
	Cursor.DrawTex(iX+fx,iY+fy);
}