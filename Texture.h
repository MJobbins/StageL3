#ifndef TEXTURE_H
#define TEXTURE_H

#include <fstream>
#include "Optic.h"
#include "Color.h"

class Texture : Optic {

public:

    //std::string getFileName() const;
    //void setFileName();

//	Color colorAtPixel(float u, float v);

private:
    std::string m_fileName;
};

#endif
