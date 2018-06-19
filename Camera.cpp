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
#include "Texture.h"

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
m_scene(nullptr),
m_lights(nullptr)
{}

Camera::Camera(Camera const& source) :
m_position(source.m_position),
m_direction(source.m_direction),
m_vertical(source.m_vertical),
m_horizontal(source.m_horizontal),
m_angleV(source.m_angleV),
m_angleH(source.m_angleH),
m_scene(source.m_scene),
m_lights(source.m_lights)
{}

Camera::Camera(Point3d const& p,
        	   Vector3d const& vDir,
        	   Vector3d const& vVer,
        	   Vector3d const& vHor,
        	   float angleV,
        	   float angleH,
               std::vector<Entity*> const& scene,
               std::vector<SpotLight*> const& lights) :
m_position(p),
m_direction(vDir),
m_vertical(vVer),
m_horizontal(vHor),
m_angleV(angleV / 360.0f * 2.0f * (float)M_PI),
m_angleH(angleH / 360.0f * 2.0f * (float)M_PI),
m_scene(&scene),
m_lights(&lights)
{
    m_horizontal = m_vertical * m_direction;
    m_vertical = m_direction * m_horizontal;

    m_direction.normalize();
    m_vertical.normalize();
    m_horizontal.normalize();
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
    m_lights = source.m_lights;

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
           (lhs.m_scene == rhs.m_scene) &&
           (lhs.m_lights == rhs.m_lights);
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
                rayOP -= p.getX() * tan(m_angleV) * m_vertical;
                rayOP -= p.getY() * tan(m_angleH) * m_horizontal;

                //rayOP.setXYZ(2000,0,1100);

                rayOP.normalize();

                Ray ray(m_position, rayOP, Color(1.0f));

                //Color pixelColor = startLaser(ray);

                Color pixelColor = ray.traceRay(m_scene, m_lights);

                image.setColor(i, j, pixelColor);
            }
        }
    }
    image.saveImageBis(std::string("test1.ppm"));
}


//Function moved into ray
        /*
Color Camera::startLaser(Ray const& ray) const
{
    Hit closestHit; // Ce sera notre hit final.

    for (const auto &i : *m_scene) {

        Hit currentHit;
        currentHit.setEntity(*i);

        if(i->intersects(ray, currentHit))
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

    if(!closestHit.getHit()) {
        return Color::BLACK; //Pour le moment noir, lorsqu'on auras de
        //La lumière il faudras mettre la couleur de la lumière
    }
    else {
        return closestHit.getColor();
    }
}
*/

int main()
{

    Sphere sphere(1);
    UniColor uc(Color::GREEN);
    Texture texture("../Textures/earth.ppm");
    Entity entite1(sphere, texture, Point3d(10.0f, 0.0f, 0.0f));
    entite1.setMirrror(0.1);

    Sphere sphere2(4);
    UniColor uc2(Color::MAGENTA);
    Texture texture2("../Textures/alaska.ppm");
    Entity entite2(sphere2, texture2, Point3d(10.0f, 5.0f, 0.0f));
    entite2.setMirrror(0.1);

    std::vector<Entity*> tableau;
    tableau.push_back(&entite1);
    tableau.push_back(&entite2);

    SpotLight lumière(Color(0.5,0,0.5), Point3d(8, 0, -4));
    SpotLight lumière2(Color(0.6,0.6,0), Point3d(9, -4, 4));

    std::vector<SpotLight*> tabLights;
    tabLights.push_back(&lumière);
    tabLights.push_back(&lumière2);


    //Camera mainCamera(Point3d(0.0f,0.0f,0.0f), Vector3d::I, Vector3d::K, Vector3d::J, 45.0f, 45.0f, tableau);

    //Camera mainCamera(Point3d(2000.0f, 0.0f,20000.0f), -Vector3d::K, Vector3d::I, Vector3d::ZERO, 5.0f, 5.0f, tableau);

    Camera mainCamera(Point3d(0.0f, 0.0f, 0.0f), Vector3d::I, Vector3d::K, Vector3d::ZERO, 45.0f, 45.0f, tableau, tabLights);

    mainCamera.makeImage(600, 600, 1);

    return 0;
}
