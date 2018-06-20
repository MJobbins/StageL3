#include "Color.h"

const Color Color::BLACK   (0.0f, 0.0f, 0.0f);
const Color Color::WHITE   (1.0f, 1.0f, 1.0f);
const Color Color::RED     (1.0f, 0.0f, 0.0f);
const Color Color::GREEN   (0.0f, 1.0f, 0.0f);
const Color Color::BLUE    (0.0f, 0.0f, 1.0f);
const Color Color::CYAN    (0.0f, 1.0f, 1.0f);
const Color Color::MAGENTA (1.0f, 0.0f, 1.0f);
const Color Color::YELLOW  (1.0f, 1.0f, 0.0f);


	//Constructors & destructors
	//==========================

Color::Color() :
m_red(1.0f),
m_green(0.0f),
m_blue(0.0f)
{}

Color::Color(Color const& source) :
m_red(source.Color::getRed()),
m_green(source.Color::getGreen()),
m_blue(source.Color::getBlue())
{}

Color::Color(float r, float g, float b) :
m_red(r),
m_green(g),
m_blue(b)
{}

Color::Color(float g) :
m_red(g),
m_green(g),
m_blue(g)
{}

Color::~Color()
{}


    //Assignement operators
    //=====================

Color & Color::operator=(Color const& source)
{
	m_red	= source.Color::getRed();
	m_green = source.Color::getGreen();
	m_blue 	= source.Color::getBlue();

	return *this;
}

Color & Color::operator+=(Color const& source)
{
	m_red 	+= source.Color::getRed();
	m_green += source.Color::getGreen();
	m_blue	+= source.Color::getBlue();

	return *this;
}

Color & Color::operator+=(float grey)
{
	m_red	+= grey;
	m_green += grey;
	m_blue	+= grey;

	return *this;
}

Color & Color::operator-=(Color const& source)
{
	m_red	-= source.Color::getRed();
	m_green -= source.Color::getGreen();
	m_blue	-= source.Color::getBlue();

	return *this;
}

Color & Color::operator-=(float grey)
{
	m_red	-= grey;
	m_green -= grey;
	m_blue	-= grey;

	return *this;
}

Color & Color::operator*=(Color const& source)
{
	m_red 	*= source.Color::getRed();
	m_green *= source.Color::getGreen();
	m_blue	*= source.Color::getBlue();

	return *this;
}

Color & Color::operator*=(float factor)
{
	m_red 	*= factor;
	m_green	*= factor;
	m_blue 	*= factor;

	return *this;
}

Color & Color::operator/=(float factor)
{
	m_red 	/= factor;
	m_green	/= factor;
	m_blue	/= factor;

	return *this;
}

    //Comparison operators
    //====================

bool operator==(Color const& lhs, Color const& rhs)
{
	return	(lhs.m_red 	 == rhs.m_red) 	 &&
			(lhs.m_green == rhs.m_green) &&
			(lhs.m_blue  == rhs.m_blue);
}

bool operator!=(Color const& lhs, Color const& rhs)
{
	return !(lhs == rhs);
}


    //Operation operators
    //===================

 Color operator+(Color const& lhs, Color const& rhs)
 {
 	Color result(lhs);
 	result += rhs;
 	return result;
 }

 Color operator+(float lhs, Color const& rhs)
 {
 	Color result(lhs);
 	result += rhs;
 	return result;
 }

 Color operator+(Color const& lhs, float rhs)
 {
 	Color result(lhs);
 	result += rhs;
 	return result;
 }

 Color operator-(Color const& lhs, Color const& rhs)
 {
 	Color result(lhs);
 	result -= rhs;
 	return result;
 }

 Color operator-(float lhs, Color const& rhs)
 {
 	Color result(lhs);
 	result -= rhs;
 	return result;
 }

 Color operator-(Color const& lhs, float rhs)
 {
 	Color result(lhs);
 	result -= rhs;
 	return result;
 }

 Color operator*(Color const& lhs, Color const& rhs)
 {
 	Color result(lhs);
 	result *= rhs;
 	return result;
 }

 Color operator*(float lhs, Color const& rhs)
 {
 	Color result(lhs);
 	result *= rhs;
 	return result;
 }
 Color operator*(Color const& lhs, float rhs)
 {
 	Color result(lhs);
 	result *= rhs;
 	return result;
 }

 Color operator/(Color const& lhs, float rhs)
 {
 	Color result(lhs);
 	result /= rhs;
 	return result;
 }


    //Setters and Getters
    //===================

float Color::getRed() const
{
	return m_red;
}

void Color::setRed(float r)
{
	m_red = r;
}

float Color::getGreen() const
{
	return m_green;
}

void Color::setGreen(float g)
{
	m_green = g;
}

float Color::getBlue() const
{
	return m_blue;
}

void Color::setBlue(float b)
{
	m_blue = b;
}

void Color::setRGB(float r, float g, float b)
{
	m_red 	= r;
	m_green = g;
	m_blue 	= b;
}

void Color::setColor(Color const& color)
{
	m_red	 = color.m_red;
	m_green	 = color.m_green;
	m_blue 	 = color.m_blue;
}

float Color::getGrey() const
{
	return m_red;
}

void Color::setGrey(float g)
{
	m_red = m_green = m_blue = g;
}

float Color::getLuminosity() const
{
	return (0.299F * m_red + 0.587 * m_green + 0.114 * m_blue);
}

void Color::clamp()
{
	if(m_blue > 1)
		m_blue = 1;
	if(m_red > 1)
		m_red = 1;
	if(m_green > 1)
		m_green = 1;
}