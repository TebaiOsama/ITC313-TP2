/** 
  * File:     Magasin.cpp 
  * Author:   F.Forrer/O.Tebai (Francois_Forrer@etu.u-bourgogne.fr/Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Definition of the class Magasin
  */

#include "Magasin.h"
#include "Produit.h"
#include <vector>
#include <string>
#include <iostream>


Magasin::Magasin(){}

Magasin::Magasin(std::vector<Produit*> t_produits){
	m_produits = t_produits;
}
/*
Magasin::Magasin(std::vector<Produit*> t_produits, std::vector<Client*> t_clients, std::vector<Commande*> t_commandes){
	m_produits = t_produits;
	m_commandes = t_commandes;
	m_clients = t_clients;
}
*/
void Magasin::ajoutProduit(std::string t_titre_produit, double t_prix_produit, int t_quantite_disponible, std::string t_description_produit){
	m_produits.push_back(new Produit(t_titre_produit, t_prix_produit, t_quantite_disponible, t_description_produit));
}

void Magasin::affichageProduits(){
	std::cout<<"Produits disponibles : "<<std::endl<<std::endl;
	std::cout<<"Nom\t\t\tDescription\t\t\tQuantite\tPrix"<<std::endl;
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		std::cout<<m_produits[i]->getTitreProduit();
		m_produits[i].tabulations(m_produits[i]->getTitreProduit().length(), true);
		std::cout<<m_produits[i]->getDescriptionProduit();
		m_produits[i].tabulations(m_produits[i]->getDescriptionProduit().length(), false);
		std::cout<<m_produits[i]->getQuantiteDisponible()
				 <<"\t\t"
				 <<m_produits[i]->getPrixProduit()<<"€"<<std::endl;
	}
	std::cout<<std::endl;
}

void Magasin::affichageProduitParNom(std::string t_nom_produit){
	std::cout<<"Details du produit : "<<std::endl<<std::endl;
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		if(m_produits[i]->getTitreProduit()==t_nom_produit){
			std::cout<<m_produits[i]->getTitreProduit();
			m_produits[i].tabulations(m_produits[i]->getTitreProduit().length(), true);
			std::cout<<m_produits[i]->getDescriptionProduit();
			m_produits[i].tabulations(m_produits[i]->getDescriptionProduit().length(), false);
			std::cout<<m_produits[i]->getQuantiteDisponible()
				     <<"\t\t"
				     <<m_produits[i]->getPrixProduit()<<"€"<<std::endl;
		}
	}
	std::cout<<std::endl;
}

void Magasin::majQuantiteProduit(std::string t_nom_produit, int t_quantite_produit){
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		if(m_produits[i]->getTitreProduit()==t_nom_produit){
			m_produits[i]->setQuantiteDisponible(t_quantite_produit);
			break;
		}
	}
}
