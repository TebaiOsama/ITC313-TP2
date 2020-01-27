#include "Commande.h"


Commande::Commande(){}
// Commande::Commande(Client t_client, std::vector<Produit> t_produits_commandes, bool t_status){
// 	m_client = t_client;
// 	m_produits_commandes = t_produits_commandes;
// 	m_status = t_status;
// }

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
	t_flux<<"Le client "<<t_commande.getClient().getNomClient()<<" "<<t_commande.getClient().getPrenomClient()<<" a dans son panier les produits suivants : "<<std::endl;

	  	  
	return t_flux;
}