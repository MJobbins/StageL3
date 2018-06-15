#include <iostream>
#include <fstream>
#include "UniColor.h"
#include "Color.h"


/*****************
**    METHODES
******************/

//Constructors & destructors
//==========================

UniColor::UniColor() :
        m_color(Color::WHITE)
{}

UniColor::UniColor(Color const &c) :
        m_color(c)
{}

UniColor::~UniColor()
{}


//Setters and Getters
//===================

Color UniColor::getColor() const{
	return m_color;
}

void UniColor::setColor(Color const& color) {
	m_color = color;
}


//Function from parent class
//==========================

Color UniColor::getColor(float u, float v) const
{
    return m_color;
}


