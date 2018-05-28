#ifndef POINT3D_H
#define POINT3D_H

class Point3d
{
public :

	static const Point3d ZERO;
	static const Point3d I;
	static const Point3d J;
	static const Point3d K;


	/*****************
	**    METHODES
	******************/

	//Constructors & destructors
	//==========================

	Point3d();
	Point3d(Point3d const& source);
	Point3d(float x, float y, float z);
	Point3d(float f);

	virtual ~Point3d();
	
	//Assignement Operators
	//=====================

	Point3d & operator=(Point3d const& source);
	Point3d & operator+=(Point3d const& source);
	Point3d & operator-=(Point3d const& source);
	Point3d & operator*=(Point3d const& source);
	Point3d & operator/=(Point3d const& source);



	//comparison operators
	//====================

	friend bool operator==(Point3d const& lhs, Point3d const& rhs);
	friend bool operator!=(Point3d const& lhs, Point3d const& rhs);


	//Operation operators
	//===================

	friend Point3d operator+(Point3d const& lhs, Point3d const& rhs);
	friend Point3d operator-(Point3d const& lhs, Point3d const& rhs);


	//Getters and setters
	//===================

	float getX() const;
	void setX(float x);

	float getY() const;
	void setY(float y);

	float getZ() const;
	void setZ(float z);

	void setXYZ(float x, float y, float z);


	//Other functions
	//===============

	float distance(Point3d const& source);
	Point3d middle(Point3d const& source);


private :

	/*****************
	**   ATTRIBUTS
	******************/

	float m_x;
	float m_y;
	float m_z;



};

#endif