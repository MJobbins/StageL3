#ifndef CUBE_H
#define CUBE_H

#include "Geometry.h"

class Cube : public Geometry {

public:
	float m_cote;

	float getCote();

	void setCote();
};

#endif
