#include "Image.h"

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

Image::Image()
{
	dimx = 0;
	dimy = 0;
	tab = NULL;
}

Image::Image( unsigned int dimensionX, unsigned  int dimensionY)
{
	dimx = dimensionX;
	dimy = dimensionY;
	tab = new Pixel [dimx*dimy];
}

Image::~Image()
{
	dimx = 0;
	delete [] tab;
	dimy = 0;
}

Pixel & Image::getPix (unsigned int x, unsigned int y) const
{
	assert( x >= 0);
	assert( y >= 0);
	return tab[y*dimx+x];
}

void Image::setPix( unsigned int x, unsigned int y, Pixel couleur)
{
	assert( x >= 0);
	assert( y >= 0);
	tab[y*dimx+x].setRouge(couleur.getRouge());
	tab[y*dimx+x].setVert(couleur.getVert());
	tab[y*dimx+x].setBleu(couleur.getBleu());
}

void Image::dessinerRectangle( unsigned int xmin, unsigned int ymin, unsigned int xmax, unsigned int ymax, Pixel couleur)
{
	assert( xmin >= 0);
	assert(xmin <= xmax);
	assert( ymin >= 0);
	assert(ymin <= ymax);
	for(unsigned int i=xmin; i<=xmax; i++)
	{
		for(unsigned int j=ymin; j<=ymax; j++)
		{
			setPix(j, i, couleur);
		}
	}	
}

void Image::effacer (const Pixel& couleur)
{
	assert( dimx >=0 );
	assert( dimy >=0 );
	assert(couleur.getRouge() >= 0);
	assert(couleur.getRouge() <= 255);
	assert(couleur.getVert() >= 0);
	assert(couleur.getVert() <= 255);
	assert(couleur.getBleu() >= 0);
	assert(couleur.getBleu() <= 255);
	
	for(unsigned int i=0; i<dimx; i++)
	{
		for(unsigned int j=0; j<dimy; j++)
		{
			setPix(i, j, couleur);
		}
	}
}

void Image::testRegression()
{
	assert( dimx >=0 );
	assert( dimy >=0 );
	
	Pixel pix(125,130,135);
	
	// Test pour vérifier le get
	assert(pix.getRouge() == 125);
	assert(pix.getVert() == 130);
	assert(pix.getBleu() == 135);
	
	pix.setRouge(32);
	pix.setVert(142);
	pix.setBleu(22);
	
	// Test pour vérifier le set
	assert(pix.getRouge() == 32);
	assert(pix.getVert() == 142);
	assert(pix.getBleu() == 22);
	
	// Test de SetPix et GetPix
	setPix(2,2,pix);
	
	assert(getPix(2,2).getRouge() == 32);
	assert(getPix(2,2).getVert() == 142);
	assert(getPix(2,2).getBleu() == 22);
	
	
	// Test pour la fonction dessinerRectangle
	dessinerRectangle(1,1,3,3,pix);
	
	for(unsigned int i = 1; i<4; i++)
		{
			for(unsigned int j =1; j<4; j++)
			{
				assert(getPix(i,j).getRouge() == 32);
				assert(getPix(i,j).getVert() == 142);
				assert(getPix(i,j).getBleu() == 22);
			}
		}

	// Test pour la fonction Effacer
	effacer(pix);
	
	for(unsigned int i = 0; i<dimx; i++)
		{
			for(unsigned int j =0; j<dimy; j++)
			{
				assert(getPix(i,j).getRouge() == 32);
				assert(getPix(i,j).getVert() == 142);
				assert(getPix(i,j).getBleu() == 22);
			}
		}



	// Test pour voir si tous les pixels ont des r, g, b corrects
	
	/*for( unsigned int i=0; i<dimx*dimy; i++)
	{
		assert( tab[i].getRouge() >=0 );
		assert( tab[i].getRouge() <= 255);
		assert( tab[i].getVert() >=0 );
		assert( tab[i].getVert() <= 255);
		assert( tab[i].getBleu() >=0 );
		assert( tab[i].getBleu() <= 255);
	} */  
	
}


void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            // Pixel& pix = getPix(x++,y);
						Pixel& pix = getPix(x++,y);
						/*
            pix.setRouge(getPix(x,y).getRouge());
            pix.setVert(getPix(x,y).getVert());
            pix.setBleu(getPix(x,y).getBleu());*/
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> b >> g;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

/*
sdlJeu::sdlJeu () {
	window = NULL;
	renderer = NULL;
	font = NULL ;
	image = NULL;
	monimage = NULL;

}
*/
void sdlJeu::afficherInit(){

	int dimx =200;
	int dimy =200;


	if(SDL_VideoInit(NULL) <0)
	{
		cout << "SDL ne c'est pas initialiser correctement " <<SDL_GetError()<<endl; 
		SDL_Quit();
		exit(1);
	}
	else
	{
		cout<< "SDL bien initialiser " << endl;
	}

	if(TTF_Init() != 0)
	{
		cout << "ERREUR dans SDL_ttf : " << SDL_GetError() << endl;
		SDL_Quit();
		exit(1);
	}
	else
	{
		cout <<" SDL_ttf marche bien " <<endl;
	}

	{
		std::cout <<"SUCCES !! " <<endl ;
	}

	/**
	 * chargement des images
	 */

  image = IMG_Load("data/image1.ppm");

	if(!image)
	{
		cout <<"Erreur de chargement de l'image " <<endl;
		cout << IMG_GetError()<<" <----  c'est l'erreur de l'image ici "<<endl;
		//exit(1);
	}

	window = SDL_CreateWindow("Image",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,dimx, dimy,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (window ==NULL)
	{
		cout << "Probleme lors de la creation de la fenetre : " << SDL_GetError() <<endl;
		SDL_Quit();
		exit(1);
	}

	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (renderer == NULL)
	{
		cout <<"Erreur lors de la creation du render" << endl;
		cout << SDL_GetError();
		return exit(1);
	}
	else
	{
		cout << "Succee de la creation du render " <<endl;
	}

	monimage = SDL_CreateTextureFromSurface(renderer,image);

	SDL_Delay(3000); // en ms pas en seconde 
	SDL_DestroyRenderer (renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


	

