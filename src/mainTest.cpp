#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Image.h"

using namespace std;

int main() {
   Image monImage(5,5);
   monImage.testRegression();
   cout << "Appuyer sur entree pour quitter "; cin.get();
   return 0;
}