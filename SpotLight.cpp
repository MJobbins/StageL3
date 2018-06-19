//
// Created by Jobbins Morgan on 15/06/2018.
//

#include "SpotLight.h"


/*****************
**    METHODES
******************/

//Constructors & destructors
//==========================

SpotLight::SpotLight() :
m_color(Color::WHITE),
m_position(Point3d::ZERO)
{}

SpotLight::SpotLight(SpotLight const &source) :
m_color(source.m_color),
m_position(source.m_position)
{}

SpotLight::SpotLight(Color color, Point3d position) :
m_color(color),
m_position(position)
{}

SpotLight::~SpotLight()
{}


//Setters and Getters
//===================

void SpotLight::setColor(Color const &color)
{
    m_color = color;
}

Color SpotLight::getColor() const
{
    return m_color;
}

void SpotLight::setPosition(Point3d const &position)
{
    m_position = position;
}

Point3d SpotLight::getPosition() const
{
    return m_position;
}
