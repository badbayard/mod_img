#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cassert>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
using namespace std;

class Image {

private :	
	Pixel* tab;
	unsigned int dimx, dimy;
	SDL_Surface * surface;
	SDL_Texture * texture;
	bool has_changed;
/** @brief variable de la classe image
*/

public :
/**
	@brief constructeur par défault
*/
	Image();
	
/**
	@brief Constructeur de la classe : Initialise dimx et dimy
	@param dimensionX dimensionY : entier
*/
	Image( unsigned int dimensionX, unsigned int dimensionY);
	
/**
	@brief Destructeur de la classe
*/
	~Image();
	
/**
	@brief Récupérer le pixel aux coordonnées x,y
	@param x y : entier
*/
	Pixel & getPix( unsigned int x, unsigned int y) const;
	
/**
	@brief Modifier le pixel aux coordonnées x,y
	@param x y : entier et
	@param couleur : Pixel
*/
	void setPix( unsigned int x, unsigned int y, Pixel couleur);
	
/**
	@brief Dessiner un rectangle de couleur dans l'image
	@param xmin ymin xmax ymax : entier
	@parma couleur : Pixel
*/
	void dessinerRectangle( unsigned int xmin, unsigned int ymin, unsigned int xmax, unsigned int ymax, Pixel couleur);
	
/**
	@brief Efface toute l'image et ne laisse que la couleur mise en paramètre
	@param couleur : Pixel
*/
	void effacer( const Pixel& couleur);
	
/**
	@brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
*/
	void testRegression();
	
/**
	@brief permet de sauver l'image
*/
	void sauver(const string & filename) const;
	
	void ouvrir(const string & filename);
	
	void afficherConsole();

	void afficher();

	class sdljeu {

		private : 

	SDL_Window *	afficherInit ();

	};



};

#endif
