/** 
  * File:     Magasin.h
  * Author:   F.Forrer/O.Tebai (Francois_Forrer@etu.u-bourgogne.fr/Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the class Magasin
  */

#ifndef _Magasin_h
#define _Magasin_h

#include "Produit.h"
#include "Client.h"
//#include "Commande.h"
#include <vector>
#include <string>
#include <iostream>


class Magasin{
private:
	std::vector<Produit*> m_produits;
	std::vector<Client*> m_clients;
	//std::vector<Commande*> m_commandes;
public:
	Magasin();
	Magasin(std::vector<Produit*> t_produits);
	
	//methodes
	//Q3
	void ajoutProduit(std::string t_titre_produit, double t_prix_produit, int t_quantite_disponible=1, std::string t_description_produit=""); //ajout d'un produit dans la liste produits
	
	void affichageProduits(); //affichage des produits dans la liste produits
	void affichageProduitParNom(std::string t_nom_produit); //on demande d'afficher tous les produits avec le titre mis en parametre
	void majQuantiteProduit(std::string t_nom_produit, int t_quantite_produit); //on met a jour la quantite d'un produit dans le magasin
	//Q5
	void ajoutClient(std::string t_nom_client, std::string t_prenom_client); //ajout d'un nouveau client au magasin
	void affichageClients(); //affichage a l'ecran des clients d'un magasin
	void affichageClientParNom(std::string t_nom_client, std::string t_prenom_client); //affichage a l'ecran d'un client avec un Nom et Prenom ou un ID
	void affichageClientParNom(int t_id_client);
	void ajoutProduitPanierClient(std::string t_nom_client, std::string t_prenom_client, std::string t_nom_produit); //ajouter un produit à un panier d'achat d'un client
	void ajoutProduitPanierClient(int t_id_client, std::string t_nom_produit);
	void effacerProduitPanierClient(std::string t_nom_client, std::string t_prenom_client, std::string t_nom_produit); //supprimer un produit à un panier d'achat d'un client
	void effacerProduitPanierClient(int t_id_client, std::string t_nom_produit);
	void setProduitPanierClient(); //modifier quantite de produits d'un panier d'achat d'un client
};

#endif