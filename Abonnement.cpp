


#include "librairie.h"

#pragma region Constructeur
Abonnement::Abonnement()
{
	id = -1;
}

/*
Méthode pour avoir un affichage plus graphique des informations de l'abonnement.
*/
void Abonnement::AffichageDetailer()
{
	cout << "-------------------------------------------\n";
	cout << "\tNom\t\t:";
	cout << nom << endl;
	cout << "\tPrénom\t\t:";
	cout << prenom << endl;
	cout << "\tPublication\t:";
	cout << titre << endl;
	cout << "\tAdresse\t\t:";
	cout << adresse << endl;
	cout << "\tDate abonnement\t:";
	debutAbonnement.Affiche();
	cout << endl << endl;
	cout << "-------------------------------------------\n";
}

Abonnement::Abonnement(int i, string p, string n, string t, string adr, DateEpoch date)
{
	id = i;
	prenom = p;
	nom = n;
	titre = t;
	adresse = adr;
	debutAbonnement = date;
}
Abonnement::Abonnement(int i, string p, string n, string t, string adr, int a, int m, int j)
{
	id = i;
	prenom = p;
	nom = n;
	titre = t;
	adresse = adr;
	debutAbonnement = DateEpoch(a, m, j);
}
#pragma endregion Constructeur

// Retourne un string contenant toute les informations de l'Abonnement
string Abonnement::ToString()
{
	return  to_string(id) + "  " + nom + "        "
	+ prenom + "               "
	+ titre + "     "
	+ adresse + "                         "
	+ debutAbonnement.ToString();
}


#pragma region Getter
unsigned int Abonnement::getId()
{
	return id;
}

string Abonnement::getPrenom()
{
	return prenom;
}

string Abonnement::getNom()
{
	return nom;
}

string Abonnement::getTitre()
{
	return titre;
}

string Abonnement::getAdresse()
{
	return adresse;
}

DateEpoch Abonnement::getDebutAbonnement()
{
	return debutAbonnement;
}
#pragma endregion Getter

#pragma region Setter
void Abonnement::settPrenom(string p)
{
	prenom = p;
}

void Abonnement::setNom(string n)
{
	n = nom;
}

void Abonnement::setTitre(string t)
{
	titre = t;
}

void Abonnement::setAdresse(string addr)
{
	adresse = addr;
}

void Abonnement::setDebutAbonnement(DateEpoch date)
{
	debutAbonnement = date;
}

void Abonnement::setDebutAbonnement(int a, int m, int j)
{
	debutAbonnement = DateEpoch(a, m, j);
}
#pragma endregion Setter