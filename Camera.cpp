#include <cmath>
#include <string>
#include "Camera.h"
#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"
#include "Image.h"

//Static default values
const Point3d Camera::DEFAULT_POSITION(Point3d::ZERO);
const Vector3d Camera::DEFAULT_DIRECTION(Vector3d::I);
const Vector3d Camera::DEFAULT_VERTICAL(Vector3d::J);
const Vector3d Camera::DEFAULT_HORIZONTAL(Vector3d::K);
const float Camera::DEFAULT_ANGLE(1.0f);


/*****************
**    METHODES
******************/

//Constructors & destructors
//==========================

Camera::Camera() :
m_position(DEFAULT_POSITION),
m_direction(DEFAULT_DIRECTION),
m_vertical(DEFAULT_VERTICAL),
m_horizontal(DEFAULT_HORIZONTAL),
m_angleV(DEFAULT_ANGLE),
m_angleH(DEFAULT_ANGLE)
{}

Camera::Camera(Camera const& source) :
m_position(source.m_position),
m_direction(source.m_direction),
m_vertical(source.m_vertical),
m_horizontal(source.m_horizontal),
m_angleV(source.m_angleV),
m_angleH(source.m_angleH)
{}

Camera::Camera(Point3d const& p,
        	   Vector3d const& vDir,
        	   Vector3d const& vVer,
        	   Vector3d const& vHor,
        	   float angleV,
        	   float angleH) :
m_position(p),
m_direction(vDir),
m_vertical(vVer),
m_horizontal(vHor),
m_angleV(angleV),
m_angleH(angleH)
{}

Camera::~Camera()
{}


//Assignement operators
//=====================

Camera &Camera::operator=(Camera const &source)
{
    m_position = source.m_position;
    m_direction = source.m_direction;
    m_vertical = source.m_vertical;
    m_horizontal = source.m_horizontal;
    m_angleH = source.m_angleH;
    m_angleV = source.m_angleV;

    return *this;
}


//Comparison operators
//====================

bool operator==(Camera const& lhs, Camera const& rhs)
{
    return (lhs.m_position == rhs.m_position) &&
           (lhs.m_direction == rhs.m_direction) &&
           (lhs.m_vertical == rhs.m_vertical) &&
           (lhs.m_horizontal == rhs.m_horizontal) &&
           (lhs.m_angleV == rhs.m_angleV) &&
           (lhs.m_angleH == rhs.m_angleH);
}

bool operator!=(Color const& lhs, Color const& rhs)
{
    return !(lhs == rhs);
}


//Setters and Getters
//===================

Point3d Camera::getPosition() const
{
    return m_position;
}

void Camera::setPosition(Point3d const& source)
{
    m_position = source;
}

Vector3d Camera::getDirection() const
{
    return m_direction;
}

void Camera::setDirection(Vector3d const& source)
{
    m_direction = source;
}

Vector3d Camera::getVertical() const
{
    return m_vertical;
}

void Camera::setVertical(Vector3d const &source)
{
    m_vertical = source;
}

float Camera::getVerticalAngle() const
{
    return m_angleV;
}

void Camera::setVerticalAngle(float source)
{
    m_angleV = source;
}

float Camera::getHorizontalAngle() const
{
    return m_angleH;
}

void Camera::setHorizontalAngle(float source)
{
    m_angleH = source;
}


//Other functions
//===============

//numberOfRays is the number of rays per pixel. It has to be supérior to 0.
void Camera::makeImage(int sizeX, int sizeY, int numberOfRays) const
{
    Image image(sizeX, sizeY);

    for(int i = 0; i < sizeX; i++)
    {
        for(int j = 0; j < sizeY; j++)
        {
            for(int k = 0; k < numberOfRays; k++)
            {
                Point3d p( (( (i * 2.0f) / sizeX) - 1.0f),
                           (( (j * 2.0f) / sizeY) - 1.0f),
                           0.0f );

                Vector3d rayOP(m_direction);
                rayOP += p.getX() * tan(m_angleH) * m_horizontal;
                rayOP += p.getY() * tan(m_angleV) * m_vertical;

                Color pixelColor = startLaser(rayOP);

                image.setColor(i, j, pixelColor);
            }
        }
    }
}

Color Camera::startLaser(Vector3d const& vectDirect) const
{
    Color c;
    return c;
}