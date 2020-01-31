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
	// std::vector<Produit> panier;
	// Client Client1(1, "Marc", "Jesus", panier);
	// std::cout<<Client1.getNomClient()<<std::endl;
	// Client1.setNomClient("HEY");
	// std::cout<<Client1.getNomClient()<<std::endl;

	// Client1.addproduit(new Produit(4, "patate", 25));
	// Client1.addproduit(new Produit(123, "livre d'anglais", 50));

	// panier = Client1.getListeProduits();
	// for (int i = 0; i < panier.size(); i++)
	// 	{
	// 	std::cout<<panier[i].getTitreProduit()<<std::endl;
	// }

	// std::cout<<"Q2"<<std::endl;
	
	// Client1.viderlisteproduits();
	// panier = Client1.getListeProduits();
	// for (int i = 0; i < panier.size(); i++)
	// 	{
	// 	std::cout<<panier[i].getTitreProduit()<<std::endl;
	// 	}

	return 0;
}
