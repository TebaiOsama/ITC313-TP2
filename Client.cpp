/** 
  * File:     Client.cpp 
  * Authors:  O.Tebai/F.Forrer (Osama_Tebai@etu.u-bourgogne.fr/Francois_Forrer@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Definition of the class Client
  */

#include <string>
#include <iostream>
#include <vector>
#include "Client.h"
#include "Produit.h"

Client::Client(int t_id_client, std::string t_nom_client, 
	std::string t_prenom_client, std::vector<Produit> t_listeproduits){
	m_id_client = t_id_client;
	m_nom_client = t_nom_client;
	m_prenom_client = t_prenom_client;
	m_listeproduits = t_listeproduits;
}

void Client::setIdClient(int t_id_client){
	m_id_client = t_id_client;
}

void Client::setNomClient(std::string t_nom_client){
	m_nom_client = t_nom_client;
}
void Client::setPrenomClient(std::string t_prenom_client){
	m_prenom_client = t_prenom_client;
}
void Client::setListeProduits(std::vector<Produit> t_listeproduits){
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

void Client::addproduit(Produit* nom_produit){
	m_listeproduits.push_back(*nom_produit);
}

void Client::viderlisteproduits(){
	m_listeproduits.clear();
}

/*void Client::modifquantiteobjet(Produit* t_produit, int n){
	n=4;//nombre de produits voulues
	int a=0;//pour l'instant nombre de produit déjà demandés à 0
	for(int i=0; i<m_listeproduits.size();i++){
		if((*t_produit).getTitreProduit() == m_listeproduits[i].getTitreProduit())
			a++;//nombre de produits déjà demandés
	}
	a=n-a;//nombre de produits manquants
	if(a>0){
		if((*t_produit).getQuantiteDisponible()>a){
			for(int i=0; i<a; i++){ 
				addproduit(t_produit);
				a--;
			}
		}
		else if((*t_produit).getQuantiteDisponible()<a){
			std::cout<<"Nous n'avons pas assez de quantités en stock";
		}
	}
	else if(a<0){
		for(int i=0; i<-a; i++){
			supprimerproduit(*t_produit);
			a++;
		}
	}
}
*/
void Client::supprimerproduit(Produit t_produit){
	int pos = 0;
	for(int i=0; i < m_listeproduits.size() ; i++){
		int pos = std::distance(m_listeproduits.begin(),t_produit.getTitreProduit());
	}
	m_listeproduits.erase(pos);
	//m_listeproduits.erase(std::remove(m_listeproduits.begin(), m_listeproduits.end(), t_produit), m_listeproduits.end());
}