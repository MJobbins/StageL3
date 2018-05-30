#ifndef CAMERA_H
#define CAMERA_H

#include "Point3d.h"
#include "Vector3d.h"
#include "Color.h"
#include "Entity.h"

class Camera {

public:

    //Static default values
    static const Point3d DEFAULT_POSITION;
    static const Vector3d DEFAULT_DIRECTION;
    static const Vector3d DEFAULT_VERTICAL;
    static const Vector3d DEFAULT_HORIZONTAL;
    static const float DEFAULT_ANGLE;


    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

    Camera();
    Camera(Camera const& source);
    Camera(Point3d const& p,
           Vector3d const& vDir,
           Vector3d const& vVert,
           Vector3d const& vHor,
           float angleV,
           float angleH,
           std::vector<Entity> const& scene);
    virtual ~Camera();


    //Assignement operators
    //=====================

    Camera& operator=(Camera const& source);


    //Comparison operators
    //====================

    friend bool operator==(Camera const& lhs, Camera const& rhs);
    friend bool operator!=(Camera const& lhs, Camera const& rhs);


    //Setters and Getters
    //===================

	Point3d getPosition() const;
	void setPosition(Point3d const& source);

	Vector3d getDirection() const;
	void setDirection(Vector3d const& source);

    Vector3d getVertical() const;
    void setVertical(Vector3d const& source);

    float getVerticalAngle() const;
    void setVerticalAngle(float source);

    float getHorizontalAngle() const;
    void setHorizontalAngle(float source);


    //Other functions
    //===============

    //Gènère une image à partir d'un lancé de rayons. numberOfRays 
    //doit être supéreiur ou égale à SizeX * SizeY
    void makeImage(int sizeX, int sizeY, int numberOfRays) const;
	
	Color startLaser(Vector3d const& vectDirect) const;

private:

    /*****************
    **    ATTRIBUTS
    ******************/

    Point3d m_position;

    Vector3d m_direction;
    Vector3d m_vertical;
    Vector3d m_horizontal;

    float m_angleV;
    float m_angleH;

    const std::vector<Entity>* m_scene;
};

#endif
