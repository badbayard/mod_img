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
	
		SDL_Window * window;
		SDL_Renderer * renderer;
		TTF_Font * font;
		SDL_Surface * image;
		SDL_Texture* monimage;
				
	void	afficherInit();
	void 	afficherBoucle();
	void 	afficherDetruit();
	void 	draw (SDL_Renderer * renderer, int x, int y, int w, int h);

public :
	Image();	// Constructeur par defaut
	
	// Constructeur de la classe : Initialise dimx et dimy
	Image( unsigned int dimensionX, unsigned int dimensionY);
	
	// Destructeur de la classe
	~Image();
	
	// Récupérer le pixel aux coordonnées x,y
	Pixel & getPix( unsigned int x, unsigned int y) const;
	
	// Modifier le pixel aux coordonnées x,y
	void setPix( unsigned int x, unsigned int y, Pixel couleur);
	
	// Dessiner un rectangle de couleur dans l'image
	void dessinerRectangle( unsigned int xmin, unsigned int ymin, unsigned int xmax, unsigned int ymax, Pixel couleur);
	
	// Efface toute l'image et ne laisse que la couleur mise en paramètre
	void effacer( const Pixel& couleur);
	
	// Effectue une série de tests vérifiant que le module fonctionne et
	// que les données membres de l'objet sont conformes
	void testRegression();
	
	void sauver(const string & filename) const;
	
	void ouvrir(const string & filename);
	
	void afficherConsole();

	void afficher();

};

/**
 * la class qui gérent le jeu avec un affichage SDL
 
class sdlJeu{
	
	private :

		SDL_Window * window;
		SDL_Renderer * renderer;
		TTF_Font * font;
		SDL_Surface * image;
		SDL_Texture* monimage;

		Image imcharge;
				
	void	afficherInit();
	void 	afficherBoucle();
	void 	afficherDetruit();
	public :
	void afficher();

	};
*/
#endif
