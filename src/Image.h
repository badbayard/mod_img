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
	/** @brief Tableau de pixels */	
	Pixel* tab;
	/** @brief Dimension de l'image */
	unsigned int dimx, dimy;
	
	/** Variable pour la gestion de la SDL  */
	SDL_Surface * surface;
	SDL_Texture * texture;
	bool has_changed;
	SDL_Window * window;
	int window_dimx, window_dimy;
	SDL_Renderer * renderer;
	TTF_Font * font;
	SDL_Surface * image;
	SDL_Texture * monimage;
	SDL_Rect r;
				
	/** Fonction pour l'affichage SDL*/
	/** @brief Affiche l'image du programme principal */		
	void	afficherInit(int init_win_x, int init_win_y);
	/** @brief Gestion des événements de la fenêtre */
	void 	afficherBoucle();
	/** @brief Destruction de la fenêtre */
	void 	afficherDetruit();

public :
	/** @brief Constructeur par défaut */
	Image();
	
	/** @brief Constructeur de la classe 
		@param dimensionX dimensionY :entier */
	Image( unsigned int dimensionX, unsigned int dimensionY);
	
	/** @brief Destructeur de la classe */
	~Image();
	
	/** @brief Récupére le pixel aux coordonnées x,y 
		@param x y :entier */
	Pixel & getPix( unsigned int x, unsigned int y) const;
	
	/** @brief Modifie le pixel aux coordonnées x,y
		@param x y :entier */
	void setPix( unsigned int x, unsigned int y, Pixel couleur);
	
	/** @brief Dessine un rectangle de couleur entre des coordonnées minimum et maximum
		@param xmin ymin xmax ymax :entier
		@param couleur :Pixel */
	void dessinerRectangle( unsigned int xmin, unsigned int ymin, unsigned int xmax, unsigned int ymax, Pixel couleur);
	
	/** @brief Efface toute l'image et ne laisse que la couleur mise en paramètre
		@param couleur :Pixel */
	void effacer( const Pixel& couleur);
	
	/** @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes */
	void testRegression();
	
	/** @brief Enregistre l'image grâce au chemin passé en paramètre (chemin/nom_image) 
		@param filename :chaine de caractères */
	void sauver(const string & filename) const;
	
	/** @brief Ouvre l'image grâce au chemin passé en paramètre (chemin/nom_image) 
		@param filename :chaine de caractères */
	void ouvrir(const string & filename);
	
	void afficherConsole();

	/** @brief Appelle les 3 fonctions privées pour l'affichage */
	void afficher();

};

#endif
