#ifndef _MATRIX4
#define _MATRIX4

#include "Maths.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"

class Matrix4{
public:
	union{ //so we can use individual or array;
		struct{
			float m[4][4];
		};
		struct{
			float m00,m01,m02,m03,
				  m10,m11,m12,m13,
				  m20,m21,m22,m23,
				  m30,m31,m32,m33;
		};
	};
	Matrix4();
	Matrix4(float fm00,float fm01,float fm02,float fm03,
			float fm10,float fm11,float fm12,float fm13,
			float fm20,float fm21,float fm22,float fm23,
			float fm30,float fm31,float fm32,float fm33);
		  
	void  RotateX (float angle);
	void  RotateY (float angle);
	void  RotateZ (float angle);
		  
	void  RotateXYZ (Vector3 v3Angles);
	void  RotateYXZ (Vector3 v3Angles);
	void  RotateZXY (Vector3 v3Angles);
	void  RotateZYX (Vector3 v3Angles);

	bool  Ortho(float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar );
	void  OrthoNormalize();
		  
	void  Scale(Vector3 vect);
	void  Scale(float scalar);
		  
	void  Identity();
	void  Zero();

//overloads
	//Comparitors
	bool    operator   == (Matrix4  mat);
	bool    operator   != (Matrix4  mat);
	void    operator    = (Matrix4  mat);
	void    operator    = (float scalar);
	//negate		   					
	Matrix4 operator   -  (            );
	//Addition		   					
	Matrix4 operator   ++ (            );
	Matrix4 operator   +  (Matrix4  mat);
	Matrix4 operator   += (Matrix4  mat);
	//Subtraction	   					
	Matrix4 operator   -- (            );
	Matrix4 operator   -  (Matrix4  mat);
	Matrix4 operator   -= (Matrix4  mat);
	//Multiplication  				  
	Matrix4 operator   *  (Matrix4  mat);
	Matrix4 operator   *= (Matrix4  mat);

	Vector4 operator   *  (Vector4 vect);
	Vector4 operator   *= (Vector4 vect);

	Matrix4 operator   *  (float scalar);
	Matrix4 operator   *= (float scalar);
};
#endif
/*

o Transform Point
o Transform Vector

*/