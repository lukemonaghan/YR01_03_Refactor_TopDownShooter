#ifndef _COLLISIONS_H_
#define _COLLISIONS_H_

#include "Maths\Vector2.h"
#include "maths\Maths.h"
bool  CheckCircle(const Vector2 &v_1,const Vector2 &v_2,float rad);

bool  CheckBox   (const Vector2 &v_1,const Vector2 &v_2,float width,float height);
int   CheckBoxPoint(const float x1,const float y1,const float x2,const float y2,float px, float py);

float CheckLine  (float p0_x, float p0_y, float p1_x, float p1_y,float p2_x, float p2_y, float p3_x, float p3_y);
float CheckLine  (const Vector2 &v_0,const Vector2 &v_1,const Vector2 &v_2,const Vector2 &v_3);

#endif