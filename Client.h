/** 
  * File:     Client.h 
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the class Client
  */

#ifndef _Client_h
#define _Client_h

#include "Produit.h"
#include <vector>
#include <iostream>
#include <string>



class Client{
	public:
		Client();
		Client(int t_id_client, std::string t_nom_client, 
		std::string t_prenom_client, std::vector<Produit> t_listeproduits={}); //constructeur
		//getters
		int getIdClient();
		std::string getNomClient();
		std::string getPrenomClient();
		std::vector<Produit> getListeProduits();
		//methodes
		void addProduit(Produit produit);
		void viderListeProduits();
		void modifQuantiteObjet(std::string t_nom_produit, int t_quantite_produit);
		void supprimerProduit(std::string t_nom_produit);
		int getQuantiteObjet(std::string t_nom_produit);

	
	private:
		int m_id_client; //id unique utilisateur
		std::string m_nom_client; //nom client
		std::string m_prenom_client; //prenom client
		std::vector<Produit> m_listeproduits; //tableau de produits sélectionnés en attente
		
};

std::ostream& operator<<(std::ostream& t_flux, Client& t_client);
#endif
