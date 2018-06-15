#ifndef UNICOLOR_H
#define UNICOLOR_H

#include "Optic.h"
#include "Color.h"

class UniColor : public Optic {

public:

	/*****************
    **    METHODES
    ******************/

	//Constructors & destructors
	//==========================

    UniColor();
    explicit UniColor(Color const& c);
    ~UniColor();


    //Setters and Getters
    //===================

	Color getColor() const;

	void setColor(Color const& color);


    //Function from parent class
    //==========================

	Color getColor(float u, float v) const;

private:

	Color m_color;
};

#endif
