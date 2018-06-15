#ifndef IMAGE_H
#define IMAGE_H

#include "Color.h"

class Image {

public:

	static const int DEFAULT_WIDTH;

	static const int DEFAULT_HEIGHT;


    /*****************
    **    METHODES
    ******************/

    //Constructors & destructors
    //==========================

	Image();

	Image(int width, int height);

	~Image();


    //Setters and Getters
    //===================

	int getWidth() const;

	int getHeight() const;

	Color getColor(int w, int h) const;

	void setColor(int w, int h, Color color);


	//Other functions
    //===============

	int pixelRedToPPM(int w, int h);

	int pixelGreenToPPM(int w, int h);

	int pixelBlueToPPM(int w, int h);

    void saveImage(std::string name);
    void saveImageBis(std::string name);

private:

    /*****************
	**    ATTRIBUTS
	******************/

    //Il faudrait un tableau en 2d, mais un tableau en 1d éconimise beaucoup de place.
    //Nous allons donc traiter celui ci comme un tableau 2d.
	Color *m_tab;

	int m_width;

	int m_height;

	//Ceci permet d'être sur que personne n'utilisera le constructeur par copie.
	Image(Image const& i);

};

#endif
