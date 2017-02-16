#ifndef PIXEL_H
#define PIXEL_H
class Pixel {

private : 	
	unsigned char r, g, b; // Compris entre 0 et 255)
/**
	@brief variables de pixel usigned char pour être compris entre 0 et 255
*/

public : 
/**
	@brief constructeur par défault 
*/
	Pixel();	// Constructeur
				// Le destructeur existe par defaut

/**
	@brief  Constructeur de la classe (initialise r, g, b avec les paramètres)
	@param nr nv nb :entier 
*/
	Pixel (	unsigned char nr, unsigned char nv, unsigned char nb);

/**		
	@brief Récupérer la composante Rouge 
*/
	unsigned char getRouge() const;
	
/**	
	@brief Récupérer la composante Vert
*/
	unsigned char getVert() const;
	
/**
	@brief Récupérer la composante Bleu
*/
	unsigned char getBleu() const;

/**
	@brief Modifie la composante Rouge
	@param nr : entier
*/
	void setRouge( unsigned char nr);
	
/**
	@brief Modifie la composante Vert
	@param nv : entier
*/
	void setVert( unsigned char nv);
	
/**
	 @brief Modifie la composante Bleu
	@param nb : entier
*/
	void setBleu( unsigned char nb);	
};



#endif
