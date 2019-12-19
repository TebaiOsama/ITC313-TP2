/** 
  * File:     Client.h 
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Declaration of the class Client
  */

#ifndef _Client_h
#define _Client_h

#include <string>
#include "Produit.h"
#include <vector>

class Client{
	public:
		Client(int t_id_client, std::string t_nom_client, 
		std::string t_prenom_client, std::vector<Produit> t_listeproduits); //constructeur
		//setters
		void setIdClient(int t_id_client);
		void setNomClient(std::string t_nom_client);
		void setPrenomClient(std::string t_prenom_client);
		void setListeProduits(std::vector<Produit> t_listeproduits);
		//getters
		int getIdClient();
		std::string getNomClient();
		std::string getPrenomClient();
		std::vector<Produit> getListeProduits();
		//methodes
		void addproduit(Produit* nom_produit);
		void viderlisteproduits();
		void modifquantiteobjet(Produit* t_produit, int n=0);
		void supprimerproduit(Produit t_produit);


	
	private:
		int m_id_client; //id unique utilisateur
		std::string m_nom_client; //nom client
		std::string m_prenom_client; //prenom client
		std::vector<Produit> m_listeproduits; //tableau de produits sélectionnés en attente
		
};

#endif
