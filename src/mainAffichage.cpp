#include "Image.h"
 
#include <iostream>
using namespace std;
 
int main (int argc, char** argv) {
 
   Image image (10,10);
sdlJeu sj;
 
   Pixel jaune (255, 255, 0);
   Pixel noir (0, 0, 0);
   Pixel blanc (255, 255, 255);
 
   image.effacer(noir);
   image.dessinerRectangle(1, 1, 8, 8, jaune);
   image.setPix(3,3,noir);
   image.setPix(6,3,noir);
   image.setPix(3,6,noir);
   image.setPix(4,7,noir);
   image.setPix(5,7,noir);
   image.setPix(6,6,noir);
   image.setPix(1,1,noir);
   image.setPix(8,1,noir);
   image.setPix(1,8,noir);
   image.setPix(8,8,noir);
 
   //image.afficher();
	sj.afficherInit();
 
   cout << "Appuyer sur entree pour quitter ";
   cin.get();
 
   return 0;    
}