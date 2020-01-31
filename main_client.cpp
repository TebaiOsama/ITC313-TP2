/** 
  * File:     main_client.cpp 
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Testing of class Client
  */


#include <iostream>
#include "Client.h"
#include <string>
#include "Produit.h"

int main(){

	Client Client1(1, "Marc", "Dubois");
	Produit Produit1("Patate", 25.5);
	Produit Produit2("Bananes", 1.21);
	Produit Produit3("Pommes", 2.61);
	Client1.addProduit(Produit1);
	std::cout<<Client1;
	Client1.viderListeProduits();
	Client1.addProduit(Produit2);
	Client1.addProduit(Produit3);
	Client1.modifQuantiteObjet("Bananes", 12);

	std::cout<<Client1;

	return 0;
}
