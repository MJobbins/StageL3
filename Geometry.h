#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry {


public:
	virtual ~Geometry() = 0;

	bool intersection(int Rayon_ray, int Hit_h, int float_distMax, int float_distMin);
};

#endif
