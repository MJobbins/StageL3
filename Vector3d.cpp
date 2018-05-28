#include "Vector3d.h"
#include <cmath>

const Vector3d Vector3d::ZERO (0.0f, 0.0f, 0.0f);
const Vector3d Vector3d::I 	 (1.0f, 0.0f, 0.0f);
const Vector3d Vector3d::J 	 (0.0f, 1.0f, 0.0f);
const Vector3d Vector3d::K 	 (0.0f, 0.0f, 1.0f);


//Constructors & destructors
//==========================

Vector3d::Vector3d() :
m_x(0.0f),
m_y(0.0f),
m_z(0.0f)
{}

Vector3d::Vector3d(Vector3d const& source) :
m_x(source.m_x),
m_y(source.m_y),
m_z(source.m_z)
{}

Vector3d::Vector3d(float x, float y, float z) :
m_x(x),
m_y(y),
m_z(z)
{}

Vector3d::~Vector3d()
{};


//Assignement operators
//=====================

Vector3d & Vector3d::operator=(Vector3d const& source)
{
	m_x = source.m_x;
	m_y = source.m_y;
	m_z = source.m_z;

	return *this;
}

Vector3d & Vector3d::operator+=(Vector3d const& source)
{
	m_x += source.m_x;
	m_y += source.m_y;
	m_z += source.m_z;

	return *this;
}

Vector3d & Vector3d::operator-=(Vector3d const& source)
{
	m_x -= source.m_x;
	m_y -= source.m_y;
	m_z -= source.m_z;

	return *this;
}

Vector3d & Vector3d::operator*=(Vector3d const& source)
{
	m_x *= source.m_x;
	m_y *= source.m_y;
	m_z *= source.m_z;

	return *this;
}

Vector3d & Vector3d::operator*=(float source)
{
	m_x *= source;
	m_y *= source;
	m_z *= source;

	return *this;
}

Vector3d & Vector3d::operator/=(Vector3d const& source)
{
	m_x /= source.m_x;
	m_y /= source.m_y;
	m_z /= source.m_z;

	return *this;
}

Vector3d & Vector3d::operator/=(float source)
{
	m_x /= source;
	m_y /= source;
	m_z /= source;

	return *this;
}


//Comparison operators
//====================


bool operator==(Vector3d const& lhs, Vector3d const& rhs)
{
	return (lhs.m_x == rhs.m_x) &&
		   (lhs.m_y == rhs.m_y) &&
		   (lhs.m_z == rhs.m_y);
}

bool operator!=(Vector3d const& lhs, Vector3d const& rhs)
{
	return !(lhs == rhs);
}


//Operation operators
//===================

Vector3d operator-(Vector3d const& rhs)
{
	Vector3d result(rhs);
	result *= -1.0f;
	return result;
}

Vector3d operator+(Vector3d const& lhs, Vector3d const& rhs)
{
	Vector3d result(lhs);
	result += rhs;
	return result;
}

Vector3d operator-(Vector3d const& lhs, Vector3d const& rhs)
{
	Vector3d result(lhs);
	result -= rhs;
	return result;
}

Vector3d operator*(Vector3d const& lhs, Vector3d const& rhs)
{
	Vector3d result(lhs);
	result *= rhs;
	return result;
}

Vector3d operator*(float lhs, Vector3d const& rhs)
{
	Vector3d result(rhs);
	result *= lhs;
	return result;
}
Vector3d operator*(Vector3d const& lhs, float rhs)
{
	Vector3d result(lhs);
	result *= rhs;
	return result;
}

Vector3d operator/(Vector3d const& lhs, float rhs)
{
	Vector3d result(lhs);
	result /= rhs;
	return result;
}

Vector3d operator/(float lhs, Vector3d const& rhs)
{
	Vector3d result(rhs);
	result /= lhs;
	return result;
}


//Getters et setters
//==================

float Vector3d::getX() const
{
	return m_x;
}

void Vector3d::setX(float x)
{
	m_x = x;
}

float Vector3d::getY() const
{
	return m_y;
}

void Vector3d::setY(float y)
{
	m_y = y;
}

float Vector3d::getZ() const
{
	return m_z;
}

void Vector3d::setZ(float z)
{
	m_z = z;
}

void Vector3d::setXYZ(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

//Other functions
//===============

float Vector3d::length() const
{
	return sqrt( 
		pow(m_x, 2) + 
		pow(m_y, 2) + 
		pow(m_z, 2));
}
