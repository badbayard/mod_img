#include "Image.h"
#include "Pixel.h"
#include <iostream>
using namespace std;
 
int main() {

   Pixel orange (255, 128, 0);
   Pixel rose (255, 128, 255);
   Pixel bleu (0, 128, 255);
 
   Image image1 (64,48);
   image1.effacer(orange);
   image1.dessinerRectangle(10, 5, 25, 10, rose);
   image1.setPix(2,2,rose);
   image1.sauver("../data/image1.ppm");
 
   Image image2;
   image2.ouvrir("../data/image1.ppm");
   image2.dessinerRectangle(5, 5, 15, 10, bleu);
   image2.dessinerRectangle(25, 25, 35, 45, bleu);
   image2.sauver("../data/image2.ppm");

 
   cout << "Appuyer sur entree pour quitter ";
   cin.get();
 
   return 0;    
}




/*
int main ()
{
	Pixel pix(128,0,128);
	Image photo;
	
	cout <<endl;
	
	cout << " Il y a : " << (int) pix.getRouge() << " en Rouge !" << endl;
	cout << " Il y a : " << (int) pix.getVert() << " en Vert !" << endl;
	cout << " Il y a : " << (int) pix.getBleu() << " en Bleu !" << endl;
	
	pix.setRouge(32);
	pix.setVert(142);
	pix.setBleu(22);
	
	cout << endl << " Et après un petit changement : " << endl << endl;
	
	cout << " Il y a : " << (int) pix.getRouge() << " en Rouge !" << endl;
	cout << " Il y a : " << (int) pix.getVert() << " en Vert !" << endl;
	cout << " Il y a : " << (int) pix.getBleu() << " en Bleu !" << endl;
	

cout << endl;
return 0;

}*/
