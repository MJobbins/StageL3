#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include "Camera.h"
#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"
#include "Image.h"
#include "Sphere.h"
#include "UniColor.h"
#include "Hit.h"

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
m_angleH(DEFAULT_ANGLE),
m_scene(nullptr)
{}

Camera::Camera(Camera const& source) :
m_position(source.m_position),
m_direction(source.m_direction),
m_vertical(source.m_vertical),
m_horizontal(source.m_horizontal),
m_angleV(source.m_angleV),
m_angleH(source.m_angleH),
m_scene(source.m_scene)
{}

Camera::Camera(Point3d const& p,
        	   Vector3d const& vDir,
        	   Vector3d const& vVer,
        	   Vector3d const& vHor,
        	   float angleV,
        	   float angleH,
               std::vector<Entity*> const& scene) :
m_position(p),
m_direction(vDir),
m_vertical(vVer),
m_horizontal(vHor),
m_angleV(angleV / 360.0f * 2.0f * (float)M_PI),
m_angleH(angleH / 360.0f * 2.0f * (float)M_PI),
m_scene(&scene)
{
    //m_scene = &scene;
}

Camera::~Camera()
{

}


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
    m_scene = source.m_scene;

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
           (lhs.m_angleH == rhs.m_angleH) &&
           (lhs.m_scene == rhs.m_scene);
}

bool operator!=(Camera const& lhs, Camera const& rhs)
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

//numberOfRays is the number of rays per pixel. It has to be superior to 0.
void Camera::makeImage(int width, int height, int numberOfRays = 1) const
{
    Image image(width, height);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            for(int k = 0; k < numberOfRays; k++) //Pour de l'anti aliasing, et plus de précision.
            {
                Point3d p( (( (i * 2.0f) / height) - 1.0f),
                           (( (j * 2.0f) / width) - 1.0f),
                           0.0f );

                Vector3d rayOP(m_direction);
                rayOP += p.getX() * tan(m_angleH) * m_horizontal;
                rayOP += p.getY() * tan(m_angleV) * m_vertical;

                rayOP.normalize();

                Color pixelColor = startLaser(rayOP);

                image.setColor(i, j, pixelColor);
            }
        }
    }
    image.saveImageBis(std::string("test1.ppm"));
}

Color Camera::startLaser(Vector3d const& vectDirect) const
{
    Hit closestHit; // Ce sera notre hit final.

    Ray rayOP(m_position, vectDirect, Color(1.0f));

    for (const auto &i : *m_scene) {

        Hit currentHit;
        currentHit.setEntity(*i);

        if(i->intersects(rayOP, currentHit))
        {
            if(!closestHit.getHit())
            {
                //std::cout << "premier" << std::endl;
                closestHit = currentHit;
            }
            else
            {
                if(closestHit.getDistance() > currentHit.getDistance())
                    closestHit = currentHit;
            }
        }
    }

    //This is all i need for the basic version with no reflection
    /*

    if(distance == -1.0f)
    {

    }
    */
    if(!closestHit.getHit()) {
        return Color::BLACK; //Pour le moment noir, lorsqu'on auras de
        //La lumière il faudras mettre la couleur de la lumière
    }
    else {
        return closestHit.getEntity().getColor(closestHit.getU(), closestHit.getV());
    }
}

int main()
{

    Sphere sphere(40);
    UniColor uc(Color::GREEN);
    Entity entite1(sphere, uc, Point3d(100.0f, 50.0f, 50.0f));

    Sphere sphere2(1);
    UniColor uc2(Color::MAGENTA);
    Entity entite2(sphere2, uc2, Point3d(8.0f, 0.0f, 0.0f));

    std::vector<Entity*> tableau;
    tableau.push_back(&entite1);
    tableau.push_back(&entite2);

    Camera mainCamera(Point3d::ZERO, Vector3d::I, Vector3d::K, Vector3d::J, 45.0f, 45.0f, tableau);

    mainCamera.makeImage(2000, 1000, 1);

    return 0;
}
