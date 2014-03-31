#include "Maths/Matrix4.h"
#include <math.h>

//constructors
Matrix4::Matrix4(){
	Identity();//calls the identity setup
}
Matrix4::Matrix4(float fm00 ,float fm01,float fm02,float fm03,
				 float fm10, float fm11,float fm12,float fm13,
				 float fm20, float fm21,float fm22,float fm23,
				 float fm30, float fm31,float fm32,float fm33){
				 m00 = fm00; m01 = fm01; m02 =fm02; m02 =fm03;
				 m10 = fm10; m11 = fm11; m12 =fm12;	m12 =fm13;
				 m20 = fm20; m21 = fm21; m22 =fm22;	m22 =fm23;
				 m20 = fm30; m21 = fm31; m22 =fm32;	m22 =fm33;
}
//1D rots
void  Matrix4::RotateX (float angle){
	const float co = cosf(angle);
	const float si = sinf(angle);
	m00	= 1.0f; m01	= 0.0f; m02	= 0.0f; m03	= 0.0f;
	m10	= 0.0f;	m11	=   co;	m12	=   si;	m13	= 0.0f;
	m20	= 0.0f;	m21	=  -si;	m22	=   co;	m23	= 0.0f;
	m20	= 0.0f;	m21	= 0.0f;	m22	= 0.0f; m23	= 1.0f;
}
void  Matrix4::RotateY (float angle){
	const float co = cosf(angle);
	const float si = sinf(angle);
	m00	=   co; m01	= 0.0f; m02	=  -si; m03	= 0.0f;
	m10	= 0.0f;	m11	= 1.0f;	m12	= 0.0f;	m13	= 0.0f;
	m20	=   si;	m21	= 0.0f;	m22	=   co;	m23	= 0.0f;
	m20	= 0.0f;	m21	= 0.0f;	m22	= 0.0f;	m23	= 1.0f;
}
void  Matrix4::RotateZ (float angle){
	const float co = cosf(angle);
	const float si = sinf(angle);
	m00	=   co; m01	=   si; m02	= 0.0f; m03	= 0.0f;
	m10	=  -si;	m11	=   si;	m12	= 0.0f;	m13	= 0.0f;
	m20	= 0.0f;	m21	= 0.0f;	m22	= 1.0f;	m23	= 0.0f;
	m20	= 0.0f;	m21	= 0.0f;	m22	= 0.0f;	m23	= 1.0f;
}
//3D rots	  
void  Matrix4::RotateXYZ (Vector3 v3Angles){
	Matrix4 m3x, m3y, m3z;
	m3x.RotateX( v3Angles.x );
	m3y.RotateY( v3Angles.y );
	m3z.RotateZ( v3Angles.z );
	*this = m3x * m3y * m3z;
}
void  Matrix4::RotateYXZ (Vector3 v3Angles){
	Matrix4 m3x, m3y, m3z;
	m3x.RotateX( v3Angles.x );
	m3y.RotateY( v3Angles.y );
	m3z.RotateZ( v3Angles.z );
	*this = m3y * m3x * m3z;
}
void  Matrix4::RotateZXY (Vector3 v3Angles){
	Matrix4 m3x, m3y, m3z;
	m3x.RotateX( v3Angles.x );
	m3y.RotateY( v3Angles.y );
	m3z.RotateZ( v3Angles.z );
	*this = m3z * m3x * m3y;
}
void  Matrix4::RotateZYX (Vector3 v3Angles){
	Matrix4 m3x, m3y, m3z;
	m3x.RotateX( v3Angles.x );
	m3y.RotateY( v3Angles.y );
	m3z.RotateZ( v3Angles.z );
	*this = m3z * m3y * m3x;
}
//ortho
bool Matrix4::Ortho(float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar )
{
	float deltaX = fRight - fLeft;
	float deltaY = fTop - fBottom;
	float deltaZ = fFar - fNear;
	
	m00 =	2.0f/deltaX;			m01 = 0.0f;						m02 = 0.0f;						m03 = 0.0f;
	m10 =  0.0f;					m11 = 2.0f/deltaY;				m12 = 0.0f;						m13 = 0.0f;
	m20 =  0.0f;					m21 = 0.0f;						m22 = -2.0f/deltaZ;				m23 = 0.0f;
	m30 = -((fRight+fLeft)/deltaX);	m31 = -((fTop+fBottom)/deltaY);	m32 = -((fFar+fNear)/deltaZ);	m33 = 1.0f;
	return true;
}
void  Matrix4::OrthoNormalize(){
	Vector3 v3x(m00,m01,m02);
	Vector3 v3y(m10,m11,m12);
	Vector3 v3z(m20,m21,m22);

	v3y = v3y - (v3z * v3z.Dot(v3y));
	v3y.Normalize();
	v3x.Cross(v3y,v3z);
	v3x.Normalize();

	v3x.Normalize();
	v3y.Normalize();
	v3x.Normalize();

	m00 = v3x.x; m01 = v3x.y; m02 = v3x.z;
	m10 = v3y.x; m11 = v3y.y; m12 = v3y.z;
	m20 = v3z.x; m21 = v3z.y; m22 = v3z.z;
}
//scalars	  
void  Matrix4::Scale(Vector3 vect){
	m00 = vect.x; m01 =   0.0f; m02 =   0.0f; m03 = 0.0f;
	m10 =   0.0f; m11 = vect.y; m12 =   0.0f; m13 = 0.0f;
	m20 =   0.0f; m21 =   0.0f; m22 = vect.z; m23 = 0.0f;
	m30 =   0.0f; m31 =   0.0f; m32 =   0.0f; m33 = 1.0f;
}
void  Matrix4::Scale(float scalar){
	m00 = scalar; m01 =   0.0f; m02 =   0.0f; m03 = 0.0f;
	m10 =   0.0f; m11 = scalar; m12 =   0.0f; m13 = 0.0f;
	m20 =   0.0f; m21 =   0.0f; m22 = scalar; m23 = 0.0f;
	m30 =   0.0f; m31 =   0.0f; m32 =   0.0f; m33 = 1.0f;

}
//reseters		  
void  Matrix4::Identity(){
 m00 = 1.0f; m01 = 0.0f; m02 = 0.0f; m03 = 0.0f;
 m10 = 0.0f; m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
 m20 = 0.0f; m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
 m30 = 0.0f; m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}
void  Matrix4::Zero(){
 m00 = 0.0f; m01 = 0.0f; m02 = 0.0f; m03 = 0.0f;
 m10 = 0.0f; m11 = 0.0f; m12 = 0.0f; m13 = 0.0f;
 m20 = 0.0f; m21 = 0.0f; m22 = 0.0f; m23 = 0.0f;
 m30 = 0.0f; m31 = 0.0f; m32 = 0.0f; m33 = 0.0f;
}
//overloads
//Comparitors
bool    Matrix4::operator   == (Matrix4  mat){
	if (m00 == mat.m00 && m01 == mat.m01 && m02 == mat.m02 && m03 == mat.m03 &&
	    m10 == mat.m10 && m11 == mat.m11 && m12 == mat.m12 && m13 == mat.m13 &&
	    m20 == mat.m20 && m21 == mat.m21 && m22 == mat.m22 && m23 == mat.m23 &&
	    m30 == mat.m30 && m31 == mat.m31 && m32 == mat.m32 && m33 == mat.m33) {return true;}
	return false;
}
bool    Matrix4::operator   != (Matrix4  mat){
	if (m00 != mat.m00 && m01 != mat.m01 && m02 != mat.m02 && m03 != mat.m03 &&
	    m10 != mat.m10 && m11 != mat.m11 && m12 != mat.m12 && m13 != mat.m13 &&
	    m20 != mat.m20 && m21 != mat.m21 && m22 != mat.m22 && m23 != mat.m23 &&
	    m30 != mat.m30 && m31 != mat.m31 && m32 != mat.m32 && m33 != mat.m33) {return true;}
	return false;
}
void    Matrix4::operator    = (Matrix4  mat){
	m00 = mat.m00;	m01 = mat.m01;	m02 = mat.m02;	m03 = mat.m03;
	m10 = mat.m10;	m11 = mat.m11;	m12 = mat.m12;	m13 = mat.m13;
	m20 = mat.m20;	m21 = mat.m21;	m22 = mat.m22;	m23 = mat.m23;
	m30 = mat.m30;	m31 = mat.m31;	m32 = mat.m32;	m33 = mat.m33;
}
void    Matrix4::operator    = (float scalar){
	m00 = scalar;	m01 = scalar;	m02 = scalar;	m03 = scalar;
	m10 = scalar;	m11 = scalar;	m12 = scalar;	m13 = scalar;
	m20 = scalar;	m21 = scalar;	m22 = scalar;	m23 = scalar;
	m30 = scalar;	m31 = scalar;	m32 = scalar;	m33 = scalar;
}
//negate		   				
Matrix4 Matrix4::operator   -  (            ){
	return Matrix4(-m00,-m01,-m02,-m03,
				   -m10,-m11,-m12,-m13,
				   -m20,-m21,-m22,-m23,
				   -m30,-m31,-m32,-m33);
}
//Addition		   							 
Matrix4 Matrix4::operator   ++ (            ){
	return Matrix4(++m00,++m01,++m02,++m03,
				   ++m10,++m11,++m12,++m13,
				   ++m20,++m21,++m22,++m23,
				   ++m30,++m31,++m32,++m33);
}
Matrix4 Matrix4::operator   +  (Matrix4  mat){
	return Matrix4(m00+mat.m00,m01+mat.m01,m02+mat.m02,m03+mat.m03,
				   m10+mat.m10,m11+mat.m11,m12+mat.m12,m13+mat.m13,
				   m20+mat.m20,m21+mat.m21,m22+mat.m22,m23+mat.m23,
				   m30+mat.m30,m31+mat.m31,m32+mat.m32,m33+mat.m33);
}
Matrix4 Matrix4::operator   += (Matrix4  mat){
	return ((*this) + mat);
}
//Subtraction	   							 
Matrix4 Matrix4::operator   -- (            ){
	return Matrix4(--m00,--m01,--m02,--m03,
				   --m10,--m11,--m12,--m13,
				   --m20,--m21,--m22,--m23,
				   --m30,--m31,--m32,--m33);
}
Matrix4 Matrix4::operator   -  (Matrix4  mat){
	return Matrix4(m00-mat.m00,m01-mat.m01,m02-mat.m02,m03-mat.m03,
				   m10-mat.m10,m11-mat.m11,m12-mat.m12,m13-mat.m13,
				   m20-mat.m20,m21-mat.m21,m22-mat.m22,m23-mat.m23,
				   m30-mat.m30,m31-mat.m31,m32-mat.m32,m33-mat.m33);
}
Matrix4 Matrix4::operator   -= (Matrix4  mat){
	return ((*this) - mat);
}
//Multiplication  							 
Matrix4 Matrix4::operator   *  (Matrix4  mat){
	return Matrix4( m00 * mat.m00 + m01 * mat.m10 + m02 * mat.m20 + m03 * mat.m30,
					m00 * mat.m01 + m01 * mat.m11 + m02 * mat.m21 + m03 * mat.m31,
					m00 * mat.m02 + m01 * mat.m12 + m02 * mat.m22 + m03 * mat.m32,
					m00 * mat.m03 + m01 * mat.m13 + m02 * mat.m23 + m03 * mat.m33,
						  			  				 		
					m10 * mat.m00 + m11 * mat.m10 + m12 * mat.m20 + m13 * mat.m30,
					m10 * mat.m01 + m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31,
					m10 * mat.m02 + m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32,
					m10 * mat.m03 + m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33,
						  			   				  		
					m20 * mat.m00 + m21 * mat.m10 + m22 * mat.m20 + m23 * mat.m30,
					m20 * mat.m01 + m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31,
					m20 * mat.m02 + m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32,
					m20 * mat.m03 + m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33,
					
					m30 * mat.m00 + m31 * mat.m10 + m32 * mat.m20 + m33 * mat.m30,
					m30 * mat.m01 + m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31,
					m30 * mat.m02 + m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32,
					m30 * mat.m03 + m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33);
}
Matrix4 Matrix4::operator   *= (Matrix4  mat){
	return (*this) * mat;
}

Vector4 Matrix4::operator   *  (Vector4 vect){
	return Vector4( m00 * vect.w + m01 * vect.x + m02 * vect.y + m03 * vect.z,
					m10 * vect.w + m11 * vect.x + m12 * vect.y + m13 * vect.z,
					m20 * vect.w + m21 * vect.x + m22 * vect.y + m23 * vect.z,
					m30 * vect.w + m31 * vect.x + m32 * vect.y + m33 * vect.z );
}
Vector4 Matrix4::operator   *= (Vector4 vect){
	return (*this) * vect;
}

Matrix4 Matrix4::operator   *  (float scalar){
	return Matrix4(m00*scalar,m01*scalar,m02*scalar,m03*scalar,
				   m10*scalar,m11*scalar,m12*scalar,m13*scalar,
				   m20*scalar,m21*scalar,m22*scalar,m23*scalar,
				   m30*scalar,m31*scalar,m32*scalar,m33*scalar);
}
Matrix4 Matrix4::operator   *= (float scalar){
	return (*this) *scalar;
}
//End Of File