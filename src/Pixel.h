#ifndef PIXEL_H
#define PIXEL_H
class Pixel {

private : 	
	unsigned char r, g, b; // Compris entre 0 et 255)

public : 
	Pixel();	// Constructeur
				// Le destructeur existe par defaut
				
	// Constructeur de la classe (initialise r, g, b avec les paramètres)
	Pixel (	unsigned char nr, unsigned char nv, unsigned char nb);
			
	// Récupérer la composante Rouge 
	unsigned char getRouge() const;
	
	// Récupérer la composante Vert
	unsigned char getVert() const;
	
	// Récupérer la composante Bleu
	unsigned char getBleu() const;
	
	// Modifie la composante Rouge
	void setRouge( unsigned char nr);
	
	// Modifie la composante Vert
	void setVert( unsigned char nv);
	
	// Modifie la composante Bleu
	void setBleu( unsigned char nb);	
};



#endif
