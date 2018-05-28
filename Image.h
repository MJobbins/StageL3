#ifndef IMAGE_H
#define IMAGE_H

#include "Color.h"

class Image {

public:

	static const int DEFAULT_SIZE_X;

	static const int DEFAULT_SIZE_Y;


    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

	Image();

	Image(int sizeX, int sizeY);

	~Image();


    //Setters and Getters
    //===================

	int getSizeX();

	int getSizeY();

	Color getColor(int x, int y) const;

	void setColor(int x, int y, Color color);


	//Other functions
    //===============

	int pixelRedToPPM(int x, int y);

	int pixelGreenToPPM(int x, int y);

	int pixelBlueToPPM(int x, int y);

	void saveImage(std::string name);

private:

    /*****************
	**    ATTRIBUTS
	******************/

    //Il faudrait un tableau en 2d, mais un tableau en 1d éconimise beaucoup de place.
    //Nous allons donc traiter celui ci comme un tableau 2d.
	Color *m_tab;

	int m_sizeX;

	int m_sizeY;

	//Ceci permet d'être sur que personne n'utilisera le constructeur par copie.
	Image(Image const& i);

};

#endif
