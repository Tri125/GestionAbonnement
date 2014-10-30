#include "librairie.h"


Liste::Liste()
{
	compteur = 0;
	premier = nullptr;
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

Noeud* Liste::getPremier()
{
	return premier;
}

void Liste::Ajouter(Noeud* n)
{
	compteur++;
	if (premier)
		premier->pBack = n;
	n->pNext = premier;
	premier = n;
}

void Liste::Supprimer(unsigned int id)
{
	if (compteur > 0)
	{
		Noeud* cible = Recherche(id);
		if (cible)
		{
			if (!cible->pBack)
			{
				premier = premier->pNext;
			}
			else
			{
				cible->pBack->pNext = cible->pNext;
			}
			delete cible;
			compteur--;
		}
	}
}

void Liste::Swap(Noeud* first, Noeud* second)
{
	swap(first->pInfo, second->pInfo);
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

Abonnement* Liste::RechercheAbonnement(unsigned int id)
{
	Noeud* courant = premier;
	while (courant)
	{
		if (courant->pInfo->getId() == id)
		{
			return courant->pInfo;
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


//http://www.sanfoundry.com/cpp-program-implement-merge-sort-linked-list/
void Liste::Trier(SortType type, bool croissant)
{
	if (compteur > 1)
	{
		MergeSort(&premier, type, croissant);
	}
}

void Liste::MergeSort(Noeud** headRef, SortType type, bool croissant)
{
	Noeud* head = *headRef;
	Noeud* left;
	Noeud* right;
	if ((head == NULL) || head->pNext == NULL)
	{
		return;
	}
	FrontBackSplit(head, &left, &right);
	MergeSort(&left, type, croissant);
	MergeSort(&right, type, croissant);
	*headRef = SortedMerge(left, right, type, croissant);

}

Noeud* Liste::SortedMerge(Noeud* left, Noeud* right, SortType type, bool croissant)
{
	Noeud* result = NULL;
	if (left == NULL)
		return right;
	else
		if (right == NULL)
			return left;
	if (EvaluateSortType(left, right, type, croissant))
	{
		result = left;
		result->pNext = SortedMerge(left->pNext, right, type, croissant);
		result->pNext->pBack = result;
	}
	else
	{
		result = right;
		result->pNext = SortedMerge(left, right->pNext, type, croissant);
		result->pNext->pBack = result;
	}
	return result;


}

bool Liste::EvaluateSortType(Noeud* left, Noeud* right, SortType type, bool croissant)
{
	switch (type)
	{
	case SortType::ID:
		if (croissant)
			return (left->pInfo->getId() <= right->pInfo->getId());
		return (left->pInfo->getId() >= right->pInfo->getId());
		break;

	case SortType::NOM:
		if (croissant)
			return (left->pInfo->getNom() <= right->pInfo->getNom());
		return (left->pInfo->getNom() >= right->pInfo->getNom());
		break;

	case SortType::TITRE:
		if (croissant)
			return (left->pInfo->getTitre() <= right->pInfo->getTitre());
		return (left->pInfo->getTitre() >= right->pInfo->getTitre());
		break;

	case SortType::DATE:
		if (croissant)
			return (left->pInfo->getDebutAbonnement() <= right->pInfo->getDebutAbonnement());
		return (left->pInfo->getDebutAbonnement() >= right->pInfo->getDebutAbonnement());
		break;

	default:
		cout << "Liste::EvaluateSortType : NotImplemented Argument";
		return false;
		break;

	}
}


void Liste::FrontBackSplit(Noeud* source, Noeud** frontRef, Noeud** backRef)
{
	Noeud* fast;
	Noeud* slow;

	if (source == NULL || source->pNext == NULL)
	{
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->pNext;
		while (fast != NULL)
		{
			fast->pBack = nullptr;
			fast = fast->pNext;
			if (fast != NULL)
			{
				fast->pBack = nullptr;
				slow = slow->pNext;
				fast = fast->pNext;
			}
		}
		*frontRef = source;
		*backRef = slow->pNext;
		slow->pNext = NULL;
	}
}


void Liste::Afficher()
{
	Noeud* courant = premier;
	while (courant)
	{
		cout << courant->ToString();
		cout << endl;
		courant = courant->pNext;
	}
}