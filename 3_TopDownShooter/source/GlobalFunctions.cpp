#include "AIE.h"
#include <string>

char buffer[60];

void DrawInt(int i,int w, int h){
	_itoa_s (i,buffer,10);
	DrawString(buffer, w, h );
}

int Choose(int a, int b, int c, int d){
	int temp = rand()%3+1;
	if (temp==0)return a;
	if (temp==1)return b;
	if (temp==2)return c;
	if (temp==3)return d;
	return 0;
}

float Choose(float a, float b, float c, float d){
	int temp = rand()%3+1;
	if (temp==0)return a;
	if (temp==1)return b;
	if (temp==2)return c;
	if (temp==3)return d;
	return 0;
}