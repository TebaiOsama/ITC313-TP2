#ifndef _Menu_h
#define _Menu_h

#include <iostream>
#include <vector>
#include <fstream>
#include "Magasin.h"

class Menu{
private:

	Magasin easystore;

public:
	Menu();
	bool VerificationNumerique(); //fonction qui retourne vrai si la valeur dans le cin est numerique
	void demarrer();
	void gestionMagasin();
	void gestionUtilisateurs();
	void commandeUtilisateurs();
	void gestionCommandes();
	void quitter();
};

#endif