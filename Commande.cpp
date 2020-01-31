/** 
  * File:     Commande.cpp 
  * Author:   F.Forrer/O.Tebai (Francois_Forrer@etu.u-bourgogne.fr/Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Definition of the class Commande
  */

#include "Commande.h"



Commande::Commande(Client t_client, std::vector<Produit> t_produits_commandes, bool t_status){
	m_client = t_client;
	m_produits_commandes = t_produits_commandes;
	m_status = t_status;
}

Client Commande::getClient(){
	return m_client;
}

std::vector<Produit> Commande::getProduitsCommandes(){
	return m_produits_commandes;
}

bool Commande::getStatus(){
	return m_status;
}

std::ostream& operator<<(std::ostream& t_flux, Commande& t_commande){
	int produits=t_commande.getProduitsCommandes().size();
	t_flux<<"Le client "<<t_commande.getClient().getNomClient()<<" "<<t_commande.getClient().getPrenomClient();
	switch(produits){
		case 0 : std::cout<<" n'a aucun produit dans son panier d'achat."<<std::endl;
		break;
		case 1 : std::cout<<" a un seul produit dans son panier : "<<std::endl <<t_commande.getProduitsCommandes()[0]<<std::endl;
		break;
		default: std::cout<<" a dans son panier les produits suivants : "<<std::endl;

		std::cout<<"Nom\t\t\tDescription\t\t\tQuantite\tPrix"<<std::endl;
		for(int i=0; i<produits; i++){
			std::cout<<t_commande.getProduitsCommandes()[i].getTitreProduit();
			t_commande.getProduitsCommandes()[i].tabulations(t_commande.getProduitsCommandes()[i].getTitreProduit().length(), true);
			std::cout<<t_commande.getProduitsCommandes()[i].getDescriptionProduit();
			t_commande.getProduitsCommandes()[i].tabulations(t_commande.getProduitsCommandes()[i].getDescriptionProduit().length(), false);
			std::cout<<t_commande.getProduitsCommandes()[i].getQuantiteDisponible()
					 <<"\t\t"
					 <<t_commande.getProduitsCommandes()[i].getPrixProduit()<<"€"<<std::endl;
		}
		std::cout<<std::endl;
		
	}
		  	  
	return t_flux;
}

void Commande::setStatus(bool t_status){
	m_status = t_status;
}