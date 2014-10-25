#include "librairie.h"

#pragma region Constructeur
Abonnement::Abonnement()
{
	id = -1;
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