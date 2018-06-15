#include <iostream>
#include <fstream>
#include "UniColor.h"
#include "Color.h"

Color UniColor::getColor() {
	// TODO - implement UniColor::getColor
	throw "Not yet implemented";
}

void UniColor::setColor() {
	// TODO - implement UniColor::setColor
	throw "Not yet implemented";
}

Color UniColor::getColor(float u, float v) const
{
    //std::cout << "current color :" << u << "+" << v << std::endl;
    //return v*m_color;
    std::string name("../Textures/earth.ppm");
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

    std::cout << "u :" << u << " v : " << v << " width : " << width << " sizeY : " << height << std::endl;

    int pixelW = (int)(u*(float)width);
    int pixelH = (int)(v*(float)height);

    int pos = file.tellg();

    int posPixel = pixelH*width + pixelW;

    int newpos = pos+(posPixel*3);


    file.seekg(newpos);
/*
    for(int i = 0; i < ui; i++)
    {
        for(int j = 0; j < vj; j++)
        {
        */
            red = file.get();
            green = file.get();
            blue = file.get();


            /*
        }
    }
             */

    file.close();
    int r, g, b;
    return Color(red/255.0f,green/255.0f,blue/255.0f);

}

UniColor::UniColor() :
m_color(Color::WHITE)
{}

UniColor::UniColor(Color const &c) :
m_color(c)
{}
