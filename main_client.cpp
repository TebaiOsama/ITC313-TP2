/** 
  * File:     main_Client.cpp 
  * Author:   O. Tebai (Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Test Client class
  */


#include <iostream>
#include "Client.h"
#include <string>
#include "Produit.h"

int main(){
	std::vector<Produit> panier;
	Client Client1(1, "Marc", "Jesus", panier);
	std::cout<<Client1.getNomClient()<<std::endl;
	Client1.setNomClient("HEY");
	std::cout<<Client1.getNomClient()<<std::endl;

	Client1.addproduit(new Produit(4, "patate", 25));
	Client1.addproduit(new Produit(123, "livre d'anglais", 50));

	panier = Client1.getListeProduits();
	for (int i = 0; i < panier.size(); i++)
		{
		std::cout<<panier[i].getTitreProduit()<<std::endl;
	}

	std::cout<<"Q2"<<std::endl;
	
	Client1.viderlisteproduits();
	panier = Client1.getListeProduits();
	for (int i = 0; i < panier.size(); i++)
		{
		std::cout<<panier[i].getTitreProduit()<<std::endl;
		}

	return 0;
}
