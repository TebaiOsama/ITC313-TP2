/** 
  * File:     Menu.h 
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     2020
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the class Menu
  */

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