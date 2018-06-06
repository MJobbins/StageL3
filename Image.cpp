#include <fstream>
#include <string>
#include <iostream>
#include "Image.h"

const int Image::DEFAULT_SIZE_X(640);
const int Image::DEFAULT_SIZE_Y(360);

Image::Image() :
		m_tab(nullptr),
		m_sizeX(Image::DEFAULT_SIZE_X),
		m_sizeY(Image::DEFAULT_SIZE_Y)
{
    //Nous traiterons ce tableau comme un 2d
    m_tab = new Color[m_sizeX * m_sizeY];
}

Image::Image(int sizeX, int sizeY):
        m_tab(nullptr),
        m_sizeX(sizeX),
        m_sizeY(sizeY)
{
    m_tab = new Color[m_sizeX * m_sizeY];
}

Image::~Image()
{
    delete[] m_tab;
}

int Image::getSizeX() const
{
	return m_sizeX;
}

int Image::getSizeY() const
{
	return m_sizeY;
}

Color Image::getColor(int x, int y) const
{
    return m_tab[x * (m_sizeY) + y];
}

void Image::setColor(int x, int y, Color color)
{
    m_tab[x * (m_sizeY) + y].setColor(color);
}

int Image::pixelRedToPPM(int x, int y)
{
    return (int)(m_tab[x * (m_sizeY) + y].getRed() * 255);
}

int Image::pixelGreenToPPM(int x, int y)
{
    return (int)(m_tab[x * (m_sizeY) + y].getGreen() * 255);
}

int Image::pixelBlueToPPM(int x, int y)
{
    return (int)(m_tab[x * (m_sizeY) + y].getBlue() * 255);
}


void Image::saveImage(std::string name)
{
	std::ofstream file(name);

	file << "P3\n"
         << m_sizeX
         << " "
         << m_sizeY
         << "\n"
         << 255
         << "\n";

	for(int i = 0; i < m_sizeX; i++)
	{
	    for(int j = 0; j < m_sizeY; j++)
	    {
            file << pixelRedToPPM(i, j) << " "
                 << pixelGreenToPPM(i, j) << " "
                 << pixelBlueToPPM(i, j) <<" ";
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
    fprintf(file, "%d %d\n", m_sizeX, m_sizeY);
    fprintf(file, "255\n");

    for(int i = 0; i < m_sizeX; i++)
    {
        for(int j = 0; j < m_sizeY; j++)
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


/*
int main()
{
    Image image;

    Color testCol(Color::RED);

    for(int i = 0; i < image.getSizeX(); i++)
    {
    	for(int j = 0; j < image.getSizeY(); j++)
    	{
    	    image.setColor(i, j, Color(0.9f, 0.4f, 0.9f));
    	}
    }

    image.saveImage("try.ppm");
    image.saveImageBis("tryBis.ppm");

    return 0;
}
 */