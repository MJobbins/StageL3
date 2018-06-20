#include "Optic.h"
#include "Color.h"

Optic::Optic() :
m_mirror(0.0f),
m_specularColor(Color::WHITE)
{}

float Optic::getMirror() const{
	return m_mirror;
}

void Optic::setMirror(float m) {
	m_mirror = m;
}

Color Optic::getSpecularColor() const
{
	return m_specularColor;
}

void Optic::setSpecularColor(Color c)
{
	m_specularColor = c;
}

Color Optic::getColorMirrror(int Point3d_p) {
	// TODO - implement Optic::getColorMirrror
	throw "Not yet implemented";
}

float Optic::getDiffuse() {
	// TODO - implement Optic::getDiffuse
	throw "Not yet implemented";
}

float Optic::getTransparency() {
	// TODO - implement Optic::getTransparency
	throw "Not yet implemented";
}

void Optic::getColorDiffuse() {
	// TODO - implement Optic::getColorDiffuse
	throw "Not yet implemented";
}

Optic::~Optic()
{

}

