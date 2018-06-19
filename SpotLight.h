//
// Created by Jobbins Morgan on 15/06/2018.
//

#ifndef RAYTRACING_SPOTLIGHT_H
#define RAYTRACING_SPOTLIGHT_H


#include "Color.h"
#include "Point3d.h"

class SpotLight
{

public :

    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

    SpotLight();
    SpotLight(SpotLight const& source);
    SpotLight(Color color, Point3d position);
    ~SpotLight();

    //Setters and Getters
    //===================

    void setColor(Color const& color);
    Color getColor() const;

    void setPosition(Point3d const& position);
    Point3d getPosition() const;


private :

    /*****************
    **    ATTRIBUTS
    ******************/

    Color m_color;
    Point3d m_position;

};


#endif //RAYTRACING_SPOTLIGHT_H
