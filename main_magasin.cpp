/** 
  * File:     main_magasin.cpp 
  * Author:   F.Forrer/O.Tebai (Francois_Forrer@etu.u-bourgogne.fr/Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Testing of class Magasin
  */

#include "Magasin.h"
 
int main(){

	//Q1
	Magasin lidl;

	//Q3
	lidl.ajoutProduit("Abbracci", 2.53, 52, "Biscuits Italiens");
	lidl.ajoutProduit("Gocciole", 1.96, 78, "Biscuits Italiens");
	lidl.ajoutProduit("Cookies", 3.4, 125, "Biscuits Americains");

	lidl.affichageProduits();
	// lidl.affichageProduitParNom("Abbracci");
	// lidl.majQuantiteProduit("Abbracci",55);
	// lidl.affichageProduitParNom("Abbracci");

	//Q5
	lidl.ajoutClient("Tebai", "Osama");
	lidl.ajoutClient("Forrer", "Francois");
	// lidl.affichageClients();
	// lidl.affichageClientParNom("Tebai", "Osama");
	// lidl.affichageClientParNom(2);

	lidl.ajoutProduitPanierClient("Tebai", "Osama","Abbracci");
	lidl.affichageProduits();

	// std::vector<Produit*> produits;
	// Produit p("PS4", 450, 200, "Console Sony");
	// produits.push_back(&p);

	// produits.push_back(new Produit("Switch", 300, 150, "Console Nintendo"));
	// produits.push_back(new Produit("Xbox", 350, 450, "Console Microsoft"));


	// Magasin micro(produits);

	// micro.affichageProduits();
	// micro.affichageProduitParNom("Switch");
	// micro.majQuantiteProduit("Switch", 22);
	// micro.affichageProduits();
	return 0;
}