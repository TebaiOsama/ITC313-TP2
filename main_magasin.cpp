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
	

	//Q5
	lidl.ajoutClient("Tebai", "Osama");
	lidl.ajoutClient("Forrer", "Francois");
	lidl.affichageClients();
	lidl.affichageClientParNom("Tebai", "Osama");
	lidl.affichageClientParNom(2);

	lidl.ajoutProduitPanierClient("Tebai", "Osama","Abbracci");
	lidl.affichageProduits();

	lidl.effacerProduitPanierClient("Tebai", "Osama","Abbracci");
	lidl.ajoutProduitPanierClient("Tebai", "Osama","Abbracci");
	lidl.setProduitPanierClient("Tebai", "Osama","Gocciole", 12);




	//Q7c
	Client premier(1, "Tebai","Osama");
	std::vector<Produit> premiersprod;
	premiersprod.push_back(Produit("Television", 600));
	premiersprod.push_back(Produit("PS4", 300));
	Commande premierecommande(premier, premiersprod, true);
	lidl.ajoutCommande(premier, premiersprod, true);

	Client deuxieme(2, "Forrer", "Francois");
	std::vector<Produit> prod0uis;
	prod0uis.push_back(Produit("Television", 600));
	prod0uis.push_back(Produit("PS4", 300));
	lidl.ajoutCommande(deuxieme, prod0uis, true);

	lidl.afficherCommandes();


	//Q7b
	lidl.majStatusCommande(true, premierecommande);


	//Q7d
	lidl.afficherCommandesClient(3);

	return 0;
}