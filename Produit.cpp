/** 
  * File:     Produit.cpp 
  * Author:   O.Tebai (Osama_Tebai@etu.u-bourgogne.fr)
  * Date:     Fall 2019 
  * Course:   C-C++ Programming / Esirem 3A Informatique Electronique 
  * Summary:  Definition of the class Produit
  */



#include "Produit.h"
#include <string>


Produit::Produit(int t_id_produit, std::string t_titre_produit, double t_prix_produit, std::string t_description_produit, int t_quantite_disponible){
	m_id_produit = t_id_produit;
	m_titre_produit = t_titre_produit;
	m_quantite_disponible = t_quantite_disponible;
	m_prix_produit = t_prix_produit;
	m_description_produit = t_description_produit;
}

//getters
int Produit::getIdProduit() const{
	return m_id_produit;
}
std::string Produit::getTitreProduit() const{
	return m_titre_produit;
}
std::string Produit::getDescriptionProduit() const{
	return m_description_produit;
}
int Produit::getQuantiteDisponible() const{
	return m_quantite_disponible;
}
double Produit::getPrixProduit() const{
	return m_prix_produit;
}
//setters
void Produit::setQuantiteDisponible(int t_quantite_disponible){
	m_quantite_disponible = t_quantite_disponible;
}
void Produit::setTitreProduit(std::string t_titre_produit){
	m_titre_produit = t_titre_produit;
}
void Produit::setDescriptionProduit(std::string t_description_produit){
	m_description_produit = t_description_produit;
}
void Produit::setPrixProduit(double t_prix_produit){
	m_prix_produit = t_prix_produit;
}