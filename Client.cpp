/** 
  * File:     Client.cpp 
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Definition of the class Client
  */

#include "Client.h"
Client::Client(){}

Client::Client(int t_id_client, std::string t_nom_client, 
	std::string t_prenom_client, std::vector<Produit> t_listeproduits){
	m_id_client = t_id_client;
	m_nom_client = t_nom_client;
	m_prenom_client = t_prenom_client;
	m_listeproduits = t_listeproduits;
}


int Client::getIdClient(){
	return m_id_client;
}

std::string Client::getNomClient(){
	return m_nom_client;
}
std::string Client::getPrenomClient(){
	return m_prenom_client;
}
std::vector<Produit> Client::getListeProduits(){
	return m_listeproduits;
}

void Client::addProduit(Produit produit){
	m_listeproduits.push_back(produit);
}

void Client::viderListeProduits(){
	m_listeproduits.clear();
}

void Client::modifQuantiteObjet(std::string t_nom_produit, int t_quantite_produit){
	for(int i=0; (unsigned)i<m_listeproduits.size(); i++){
		if(m_listeproduits[i].getTitreProduit()==t_nom_produit){
			m_listeproduits[i].setQuantiteDisponible(t_quantite_produit);
			break;
		}
	}
}


void Client::supprimerProduit(std::string t_nom_produit){
	for(int i=0; (unsigned)i<m_listeproduits.size(); i++){
		if(m_listeproduits[i].getTitreProduit()==t_nom_produit){
			m_listeproduits.erase(m_listeproduits.begin()+i);
			break;
		}
	}
}


int Client::getQuantiteObjet(std::string t_nom_produit){
	for(int i=0; (unsigned)i<m_listeproduits.size();i++){
		if(m_listeproduits[i].getTitreProduit()==t_nom_produit)
			return m_listeproduits[i].getQuantiteDisponible();
	}
	return 0;
}

std::ostream& operator<<(std::ostream& t_flux, Client& t_client){

	t_flux<<"ID Client : "<<t_client.getIdClient()<<std::endl;
	t_flux<<"Identitée : "<<t_client.getNomClient()<<" "<<t_client.getPrenomClient()<<std::endl<<std::endl;

	t_flux<<"Produits dans le panier : "<<std::endl<<std::endl;
	t_flux<<"Nom\t\t\tDescription\t\t\tQuantite\tPrix"<<std::endl;
	for(int i=0; (unsigned)i<t_client.getListeProduits().size(); i++){
		t_flux<<t_client.getListeProduits()[i].getTitreProduit();
		t_client.getListeProduits()[i].tabulations(t_client.getListeProduits()[i].getTitreProduit().length(), true);
		t_flux<<t_client.getListeProduits()[i].getDescriptionProduit();
		t_client.getListeProduits()[i].tabulations(t_client.getListeProduits()[i].getDescriptionProduit().length(), false);
		t_flux<<t_client.getListeProduits()[i].getQuantiteDisponible()
				 <<"\t\t"
				 <<t_client.getListeProduits()[i].getPrixProduit()<<"€"<<std::endl;
	}
	t_flux<<std::endl;


	return t_flux;

}