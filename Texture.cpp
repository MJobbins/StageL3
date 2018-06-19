#include <iostream>
#include "Texture.h"
#include "Color.h"

/*****************
**    METHODES
******************/

//Constructors & destructors
//==========================

Texture::Texture() :
m_fileName(std::string("default.ppm"))
{}

Texture::Texture(Texture const &source) :
m_fileName(source.m_fileName)
{}

Texture::Texture(std::string const &name) :
m_fileName(name)
{}

Texture::~Texture()
{}


//Setters and Getters
//===================

std::string Texture::getFileName() const
{
    return m_fileName;
}

void Texture::setFileName(std::string const& name)
{
    m_fileName = name;
}

//Function from parent class
//==========================

Color Texture::getColor(float u, float v) const
{
    //std::cout << "current color :" << u << "+" << v << std::endl;
    //return v*m_color;
    std::string name(m_fileName);
    std::ifstream file;

    file.open(name, std::ios::in);

    std::string bin, size;
    int width, height;
    int red, blue, green;

    std::getline(file, bin);
    file >> width;
    file >> height;
    std::getline(file, size);
    std::getline(file, size);

    //std::cout << "u :" << u << " v : " << v << " width : " << width << " sizeY : " << height << std::endl;

    int pixelW = (int)(u*(float)width);
    int pixelH = (int)((1-v)*(float)height);

    long long int pos = file.tellg();

    int posPixel = pixelH*width + pixelW;

    long long int newpos = pos+(posPixel*3);


    file.seekg(newpos);

    red = file.get();
    green = file.get();
    blue = file.get();

    file.close();
    int r, g, b;
    return Color(red/255.0f,green/255.0f,blue/255.0f);
}
