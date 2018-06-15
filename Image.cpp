#include <fstream>
#include <string>
#include <iostream>
#include "Image.h"

const int Image::DEFAULT_WIDTH(640);
const int Image::DEFAULT_HEIGHT(360);

/*****************
**    METHODES
******************/

//Constructors & destructors
//==========================

Image::Image() :
		m_tab(nullptr),
		m_width(Image::DEFAULT_WIDTH),
		m_height(Image::DEFAULT_HEIGHT)
{
    //Nous traiterons ce tableau comme un 2d
    m_tab = new Color[m_width * m_height];
}

Image::Image(int width, int height):
        m_tab(nullptr),
        m_width(width),
        m_height(height)
{
    m_tab = new Color[m_width * m_width];
}

Image::~Image()
{
    delete[] m_tab;
}


//Setters and Getters
//===================

int Image::getWidth() const
{
	return m_width;
}

int Image::getHeight() const
{
	return m_height;
}

Color Image::getColor(int w, int h) const
{
    return m_tab[h * (m_width) + w];
}

void Image::setColor(int w, int h, Color color)
{
    m_tab[h * (m_width) + w].setColor(color);
}


//Other functions
//===============

int Image::pixelRedToPPM(int w, int h)
{
    return (int)(m_tab[h * (m_width) + w].getRed() * 255);
}

int Image::pixelGreenToPPM(int w, int h)
{
    return (int)(m_tab[h * (m_width) + w].getGreen() * 255);
}

int Image::pixelBlueToPPM(int w, int h)
{
    return (int)(m_tab[h * (m_width) + w].getBlue() * 255);
}


void Image::saveImage(std::string name)
{
	std::ofstream file(name);

	file << "P3\n"
         << m_width
         << " "
         << m_height
         << "\n"
         << 255
         << "\n";

	for(int i = 0; i < m_height; i++)
	{
	    for(int j = 0; j < m_width; j++)
	    {
            file << pixelRedToPPM(i, j) << " "
                 << pixelGreenToPPM(j, i) << " "
                 << pixelBlueToPPM(j, i) <<" ";
            //if((j)%8) file << "\n";
	    }
	file << "\n";
	}

	file << std::endl;

	file.close();
}


void Image::saveImageBis(std::string name)
{
    FILE *file = fopen(name.c_str(), "wb");

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", m_width, m_height);
    fprintf(file, "255\n");

    for(int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_width; j++)
        {
            unsigned char r, g, b;
            r = pixelRedToPPM(i, j);
            g = pixelGreenToPPM(i, j);
            b = pixelBlueToPPM(i, j);
            fwrite(&r, sizeof(unsigned char), 1, file);
            fwrite(&g, sizeof(unsigned char), 1, file);
            fwrite(&b, sizeof(unsigned char), 1, file);
        }
    }
    fclose(file);
}