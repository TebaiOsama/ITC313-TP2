#ifndef _Menu_h
#define _Menu_h

#include <iostream>
#include <vector>
#include "Magasin.h"

class Menu{
private:

	Magasin easystore;
	//int m_iterateur; //iterateur du client choisi par l'utilisateur

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