#ifndef TEXTURE_H
#define TEXTURE_H

#include <fstream>
#include "Optic.h"
#include "Color.h"

class Texture : Optic {

public:
	std::ofstream m_fichier;

	void setFichier();

	void generateTexture();

	Color colorAtPixel();
};

#endif
