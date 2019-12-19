/** 
  * File:     Magasin.h
  * Author:   F.Forrer/O.Tebai (Francois_Forrer@etu.u-bourgogne.fr/Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the class Magasin
  */

#ifndef _Magasin_h
#define _Magasin_h

#include <vector>
#include "Produit.h"
//#include "Client.h"
//#include "Commande.h"

class Magasin{
private:
	std::vector<Produit*> m_produits;
	//std::vector<Client*> m_clients;
	//std::vector<Commande*> m_commandes;
public:
	Magasin();
	Magasin(std::vector<Produit*> t_produits);
	
	//Magasin(std::vector<Produit*> t_produits=0, std::vector<Client*> t_clients=0, std::vector<Commande*> t_commandes=0);
	//methodes
	void ajoutProduit(std::string t_titre_produit, double t_prix_produit, int t_quantite_disponible=1, std::string t_description_produit=""); //ajout d'un produit dans la liste produits
	void affichageProduits(); //affichage des produits dans la liste produits
	void affichageProduitParNom(std::string t_nom_produit); //on demande d'afficher tous les produits avec le titre mis en parametre
	void majQuantiteProduit(std::string t_nom_produit, int t_quantite_produit); //on met a jour la quantite d'un produit dans le magasin
};

#endif