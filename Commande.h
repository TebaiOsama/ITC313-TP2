

#ifndef _Commande_h
#define _Commande_h

#include "Produit.h"
#include "Client.h"
#include <vector>

class Commande{
private:
	Client m_client;
	std::vector<Produit> m_produits_commandes;
	bool m_status;
public:
	Commande(Client t_client, std::vector<Produit> t_produits_commandes, bool t_status);
	Client getClient();
	std::vector<Produit> getProduitsCommandes();
	bool getStatus();
	void setStatus(bool t_status);
};

std::ostream& operator<<(std::ostream& t_flux, Commande& t_commande);

#endif