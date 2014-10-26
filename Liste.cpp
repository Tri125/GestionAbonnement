#include "librairie.h"


Liste::Liste()
{
	compteur = 0;
	premier = nullptr;
	dernier = nullptr;
}

Liste::~Liste()
{
	if (premier != nullptr)
	{
		Noeud* courant = premier;
		Noeud* destroy;
		while (courant)
		{
			destroy = courant;
			courant = courant->pNext;
			delete destroy;
		}
	}
}

void Liste::Ajouter(Noeud* n)
{
	compteur++;
	if (!premier)
	{
		premier = n;
		dernier = n;
	}
	else
	{
		dernier->pNext = n;
		n->pBack = dernier;
		dernier = n;
	}
}

void Liste::Supprimer(unsigned int id)
{
	Noeud* courant = Recherche(id);
	if (courant)
	{
		if (courant == premier)
		{
			premier = premier->pNext;
			premier->pBack = nullptr;
		}
		else
		{
			if (courant == dernier)
			{
				dernier = dernier->pBack;
				dernier->pNext = nullptr;
			}
			else
			{
				courant->pBack->pNext = courant->pNext;
				courant->pNext->pBack = courant->pBack;
			}
		}
		delete courant;
		compteur--;

	}
}

void Liste::Swap(Noeud* first, Noeud* second)
{
	swap(first->pNext, second->pNext);
	swap(first->pBack, second->pBack);
}

void Liste::Trier(SortType type, bool croissant)
{

}

Noeud* Liste::Recherche(unsigned int id)
{
	Noeud* courant = premier;
	while (courant)
	{
		if (courant->pInfo->getId() == id)
		{
			return courant;
		}
		courant = courant->pNext;
	}
	return nullptr;
}

void Liste::Vidage()
{
	Noeud* pParcours = premier;
	Noeud* pSupprimer;

	while (pParcours)
	{
		pSupprimer = pParcours;
		pParcours = pParcours->pNext;
		delete pSupprimer;
	}
	premier = nullptr;
	compteur = 0;
}


unsigned int Liste::getCompteur()
{
	return compteur;
}