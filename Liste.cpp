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
	if (compteur > 0)
	{
		MergeSort(&premier);
	}
}

void Liste::MergeSort(Noeud** headRef)
{
	Noeud* head = *headRef;
	Noeud* left;
	Noeud* right;
	if ((head == NULL) || head->pNext == NULL)
	{
		return;
	}
	FrontBackSplit(head, &left, &right);
	MergeSort(&left);
	MergeSort(&right);
	*headRef = SortedMerge(left, right);

}

Noeud* Liste::SortedMerge(Noeud* left, Noeud* right)
{
	Noeud* result = NULL;
	if (left == NULL)
		return right;
	else
		if (right == NULL)
			return left;
	if (left->pInfo->getId() <= right->pInfo->getId())
	{
		result = left;
		result->pNext = SortedMerge(left->pNext, right);
	}
	else
	{
		result = right;
		result->pNext = SortedMerge(left, right->pNext);
	}
	return result;


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
			fast = fast->pNext;
			if (fast != NULL)
			{
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