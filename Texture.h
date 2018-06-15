#ifndef TEXTURE_H
#define TEXTURE_H

#include <fstream>
#include "Optic.h"
#include "Color.h"

class Texture : public Optic {

public:

    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

    Texture();
    Texture(Texture const& source);
    Texture(std::string const& name);
    ~Texture();


    //Setters and Getters
    //===================

    std::string getFileName() const;
    void setFileName(std::string const& name);


    //Function from parent class
    //==========================

    Color getColor(float u, float v) const;

private:
    std::string m_fileName;
};

#endif
