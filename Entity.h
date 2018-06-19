#ifndef ENTITY_H
#define ENTITY_H

#include "Point3d.h"
#include "Vector3d.h"
#include "Geometry.h"
#include "Optic.h"
#include "Ray.h"
class Hit;

class Entity {


public:

    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

    Entity();
    Entity(Entity const& source);
    Entity(Geometry &shape, Optic &view);
    Entity(Geometry &shape, Optic &view,
           Point3d const& position = Point3d(0.0f, 0.0f, 0.0f),
           Point3d const& rotation = Point3d(0.0f, 0.0f, 0.0f),
           float scale = 1.0f);
    ~Entity();

    //Assignement operators
    //=====================

    Entity& operator=(Entity const& source);


    //Comparison operators
    //====================

    friend bool operator==(Entity const& lhs, Entity const& rhs);
    friend bool operator!=(Entity const& lhs, Entity const& rhs);


    //Setters and Getters
    //===================

	Point3d getPosition() const;

	void setPosition(Point3d position);

	Point3d getRotation() const;

	void setRotation(Point3d rotation);

	float getSize() const;

	void setSize(float size);


    //Other functions
    //===============

	void translate();

	void rotate();

	void scale();

	bool isInEntity(Point3d p) const;

	bool intersects(Ray const& ray, Hit &hit) const;

	Color getColor(float u, float v, Hit &hit) const;

	float getMirror() const;

	float setMirrror(float m);

private:

    /*****************
    **    ATTRIBUTS
    ******************/

    Point3d m_position;
    Point3d m_rotation;
    float m_size;

    Geometry *m_shape;
    Optic *m_visual;
};

#endif
