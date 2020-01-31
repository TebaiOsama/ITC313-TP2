/** 
  * File:     main_commande.cpp 
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Testing of class commande
  */

#include "Commande.h"

int main(){
	
	std::vector<Produit> produits_commandes;
	produits_commandes.push_back(Produit("Television", 600));
	produits_commandes.push_back(Produit("PS4", 300));
	Client Premier(1,"Marc","Antoine");
	Commande commande(Premier,produits_commandes,true);

	std::cout<<commande;
	return 0;
}