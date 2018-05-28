#include "Point3d.h"
#include <cmath>

const Point3d Point3d::ZERO (0.0f,0.0f,0.0f);
const Point3d Point3d::I (1.0f,0.0f,0.0f);
const Point3d Point3d::J (0.0f,1.0f,0.0f);
const Point3d Point3d::K (0.0f,0.0f,1.0f);


//Constructors and destructors
//============================

Point3d::Point3d() :
	m_x(0.0f),
	m_y(0.0f),
	m_z(0.0f)
{}

Point3d::Point3d(Point3d const& source) :
	m_x(source.m_x),
	m_y(source.m_y),
	m_z(source.m_z)
{}

Point3d::Point3d(float x, float y, float z) :
	m_x(x),
	m_y(y),
	m_z(z)
{}

Point3d::Point3d(float f) :
	m_x(f),
	m_y(f),
	m_z(f)
{}

Point3d::~Point3d()
{}


//Assignement operators
//=====================

Point3d & Point3d::operator=(Point3d const& source)
{
	m_x = source.m_x;
	m_y = source.m_y;
	m_z = source.m_z;

	return *this;
}

Point3d & Point3d::operator+=(Point3d const& source)
{
	m_x += source.m_x;
	m_y += source.m_y;
	m_z += source.m_z;

	return *this;
}

Point3d & Point3d::operator-=(Point3d const& source)
{
	m_x -= source.m_x;
	m_y -= source.m_y;
	m_z -= source.m_z;

	return *this;
}

Point3d & Point3d::operator*=(Point3d const& source)
{
	m_x *= source.m_x;
	m_y *= source.m_y;
	m_z *= source.m_z;

	return *this;
}

Point3d & Point3d::operator/=(Point3d const& source)
{
	m_x /= source.m_x;
	m_y /= source.m_y;
	m_z /= source.m_z;

	return *this;
}


//Comparison operators
//=====================

bool operator==(Point3d const& lhs, Point3d const& rhs)
{
	return (lhs.m_x == rhs.m_x) &&
		   (lhs.m_y == rhs.m_y) &&
		   (lhs.m_z == rhs.m_z);
}

bool operator!=(Point3d const& lhs, Point3d const& rhs)
{
	return !(lhs == rhs);
}


//Operation operators
//===================

Point3d operator+(Point3d const& lhs, Point3d const& rhs)
{
	Point3d result(lhs);
	result += rhs;
	return result;
}

Point3d operator-(Point3d const& lhs, Point3d const& rhs)
{
	Point3d result(lhs);
	result -= rhs;
	return result;
}


//Getters and setters
//===================

float Point3d::getX() const
{
	return m_x;
}

void Point3d::setX(float x)
{
	m_x = x;
}

float Point3d::getY() const
{
	return m_y;
}

void Point3d::setY(float y)
{
	m_y = y;
}

float Point3d::getZ() const
{
	return m_z;
}

void Point3d::setZ(float z)
{
	m_z = z;
}

void Point3d::setXYZ(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}


//Other functions
//===============

float Point3d::distance(Point3d const& source)
{
	return sqrt(
				pow((source.m_x - m_x), 2) +
				pow((source.m_y - m_y), 2) +
				pow((source.m_z - m_z), 2));
}

Point3d Point3d::middle(Point3d const& source)
{
	return Point3d((m_x + source.m_x) / 2,
				   (m_y + source.m_y) / 2,
				   (m_z + source.m_z) / 2 );
}




