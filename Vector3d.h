#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d
{
public :

	static const Vector3d ZERO;
	static const Vector3d I;
	static const Vector3d J;
	static const Vector3d K;

	/*****************
	**    METHODES
	******************/

	//Constructors & destructors
	//==========================

	Vector3d();
	Vector3d(Vector3d const& source);
	Vector3d(float x, float y, float z);

	virtual ~Vector3d();


	//Assignement operators
	//=====================

	Vector3d & operator=(Vector3d const& source);
	Vector3d & operator+=(Vector3d const& source);
	Vector3d & operator-=(Vector3d const& source);
	Vector3d & operator*=(Vector3d const& source);
	Vector3d & operator*=(float source);
	Vector3d & operator/=(Vector3d const& source);
	Vector3d & operator/=(float source);


	//Comparison operators
	//====================

	friend bool operator==(Vector3d const& lhs, Vector3d const& rhs);
	friend bool operator!=(Vector3d const& lhs, Vector3d const& rhs);


	//Operation operators
	//===================

	friend Vector3d operator-(Vector3d const& rhs);
	friend Vector3d operator+(Vector3d const& lhs, Vector3d const& rhs);
	friend Vector3d operator-(Vector3d const& lhs, Vector3d const& rhs);
	friend Vector3d operator*(Vector3d const& lhs, Vector3d const& rhs);
	friend Vector3d operator*(float lhs, Vector3d const& rhs);
	friend Vector3d operator*(Vector3d const& lhs, float rhs);
	friend Vector3d operator/(Vector3d const& lhs, float f);
	friend Vector3d operator/(float lhs, Vector3d const& rhs);

	
	//Getters et setters
	//==================

	float getX() const;
	void setX(float x);

	float getY() const;
	void setY(float y);

	float getZ() const;
	void setZ(float z);

	void setXYZ(float x, float y, float z);

	//Other functions
	//===============

	float length() const;

	
private :

	float m_x;
	float m_y;
	float m_z;

	/*****************
	**   ATTRIBUTS
	******************/

};

#endif