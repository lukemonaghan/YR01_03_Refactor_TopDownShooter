////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\
//																			Author:		Luke Monaghan																					\\
//																			Date:		06/05/2013																						\\
//																			Brief:		Map Parent																						\\
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\\

#include "Collisions.h"
#include "AIE.h"
#include <math.h>
//circle
bool CheckCircle(const Vector2 &v_1,const Vector2 &v_2,float rad){
	static Vector2 Check;
	Check.x = (v_1.x - v_2.x);
	Check.y = (v_1.y - v_2.y);
	if (Check.Magnitude() < rad){
		return true;
	}else{
		return false;
	}
}
//box's
bool CheckBox(const Vector2 &v_1,const Vector2 &v_2,float width,float height){
	if (v_1.x-width  < v_2.x+width  &&
		v_1.x+width  > v_2.x-width  &&
		v_1.y-height < v_2.y+height &&
		v_1.y+height > v_2.y-height){
		return true;
	}else{
		return false;
	}
}
int CheckBoxPoint(const float x1,const float y1,const float x2,const float y2,float px, float py){
////gets the middle of the box
	float mx = (x2 + x1)*0.5;
	float my = (y2 + y1)*0.5;
	float smx =abs((px - mx)) / (x2 - x1);
	float smy =abs((py - my)) / (y2 - y1);
////Move the instance
	if (py > y1 && py < y2 && px > x1 && px < x2){
		//the following finds out what side of the wall you are hitting
		if (px > x1 && px < mx && Maxf(smx,smy) == smx) {return 1;}
		if (px < x2 && px > mx && Maxf(smx,smy) == smx) {return 2;}
		if (py > y1 && py < my && Maxf(smx,smy) == smy) {return 3;}
		if (py < y2 && py > my && Maxf(smx,smy) == smy) {return 4;}
	}
////if no collisions have been hit, then return 0.
	return 0;
}
//http://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
//Gavin Dec 28 '09 at 7:16
float CheckLine(float p0_x, float p0_y, float p1_x, float p1_y,float p2_x, float p2_y, float p3_x, float p3_y){
    float s1_x, s1_y, s2_x, s2_y, s, t,returnx,returny;

    s1_x = p1_x - p0_x; s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x; s2_y = p3_y - p2_y;

	float denom  = (-s2_x * s1_y + s1_x * s2_y);
	float number1 = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y));
	float number2 = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x));
	
	s = number1 / denom;
    t = number2 / denom;

    if (s >= 0.0f && s <= 1.0f && t >= 0.0f && t <= 1.0f){
		returnx = p0_x + (t * s1_x);
		returny = p0_y + (t * s1_y);
		return (p2_x - returnx) * (p2_y - returny); // Collision hit at this point
    }
    return 0.0f;   // No collision
}
//same as above but with vector points
float CheckLine(const Vector2 &v_0,const Vector2 &v_1,const Vector2 &v_2,const Vector2 &v_3){
	
    float s1_x, s1_y, s2_x, s2_y, s, t,returnx,returny;

    s1_x = v_1.x - v_0.x; s1_y = v_1.y - v_0.y;
    s2_x = v_3.x - v_2.x; s2_y = v_3.y - v_2.y;

	float denom  = (-s2_x * s1_y + s1_x * s2_y);
	float number1 = -s1_y * (v_0.x - v_2.x) + s1_x * (v_0.y - v_2.y);
	float number2 =  s2_x * (v_0.y - v_2.y) - s2_y * (v_0.x - v_2.x);

    s = number1 / denom;
    t = number2 / denom;

    if (s >= 0.0f && s <= 1.0f && t >= 0.0f && t <= 1.0f){
		returnx = v_0.x + (t * s1_x);
		returny = v_0.y + (t * s1_y);
		return (v_2.x - returnx) * (v_2.y - returny); // Collision hit at this point
    }
    return -1.0f;   // No collision
}