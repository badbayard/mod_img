

Qu'est ce que c'est ?
---------------------

	C'est un programme réalisé dans le cadre de l'UE de LIFAP4 qui consiste à créer un module de gestion d'images


Liste des fichiers nécessaires à la compilation :
-------------------------------------------------

	Image.h
	Pixel.cpp
	Image.cpp
	main.cpp
	mainTest.cpp
	mainAffichage.cpp
	
Compilation :
-------------

	Pour compiler le programme, il faut utiliser le Makefile qui est à la racine du dossier 11408376_11512256_11510421.
	
	~$ cd 11408376_11512256_11510421
	~/11408376_11512256_11510421$ make
	
	
Exécution :
-----------

	Une fois la compilation effectuée, cela crée 3 exécuables dans le dossier bin : exemple test affichage
	- "exemple" exécute le code du fichier main.cpp qui crée une image et la stocke dans data
	- "test" exécute le code du fichier mainTest.cpp qui teste si les fonctions de base de l'image et du pixel fonctionne
	- "affichage" exécute le code du fichier mainAffichage.cpp qui affiche l'image créée dans le main
	
	Pour les exécuter, il suffit de taper la commande :
		~/11408376_11512256_11510421& cd bin/
		
	Puis, pour "exemple" :
			~/11408376_11512256_11510421/bin$ ./exemple
			
		, pour "test" :
			~/11408376_11512256_11510421/bin$ ./test
			
		, pour "affichage" :
			~/11408376_11512256_11510421/bin$ ./affichage
			

Documentation :
---------------

Un fichier de génération de documentation est fourni dans le dossier doc.

	Après avoir installé doxygen, taper la commande :
		~/11408376_11512256_11510421$ doxygen doc/image.doxy
		
	Pour afficher la documentation sur un navigateur :
		~/11408376_11512256_11510421$ [nom_du_navigateur] doc/html/index.html
		
	
	Un diagramme des modules réalisé sous Dia est consultable dans le dossier doc sous le nom "diagramme_classes.dia"



Contacts :
----------

	Pour tout renseignements, nous contacter :
	Julien CADIER (11510421) : julien.cadier@etu.univ-lyon1.fr
	Yannis HUTT (11408376)	 : yannis.hutt@etu.univ-lyon1.fr
	Randy ANDRIAMARO (11512256) : randy.andriamaro@etu.univ-lyon1.fr


