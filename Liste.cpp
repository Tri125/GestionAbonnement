


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

//Échange les pInfo des deux Noeuds passé en paramètres.
void Liste::Swap(Noeud* first, Noeud* second)
{
	swap(first->pInfo, second->pInfo);
}

//D'après un unsigned int, recherche dans les Noeuds de la Liste 
//pour un Abonnement avec le même numéro. Retourne le pointeur du Noeud si trouvé, sinon nullptr
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


//D'après un unsigned int, recherche dans les Noeuds de la Liste 
//pour un Abonnement avec le même numéro. Retourne le pointeur de l'Abonnement , sinon nullptr
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

//Suprimme tout les Noeuds de la Liste
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

//Retourne compteur qui indique le nombre de Noeuds dans la Liste.
unsigned int Liste::getCompteur()
{
	return compteur;
}


/*
Méthode qui appel la méthode de MergeSort.
SortType est un ENUM pour spécifier sur qu'elle donnée des Abonnements que l'on trie.
Le bool pour spécifier si le trie sera en ordre croissant ou non (décroissant).
*/
void Liste::Trier(SortType type, bool croissant)
{
	if (compteur > 1)
	{
		MergeSort(&premier, type, croissant);
	}
}



/*

Source: http://www.sanfoundry.com/cpp-program-implement-merge-sort-linked-list/
Implémentation de Manish Bhojasia

MergeSort, implémentation récursive (TopDown).
Complexité de cas moyen, meilleur cas et pire cas de O(n log n)

Change les pointeurs entre les Noeuds.
Prend un pointeur d'un pointeur d'un Noeud (L'adresse d'un objet pointeur pointant vers un Noeud, dans note cas le premier Noeud de la Liste)
SortType pour spécifier sur qu'elle donnée le trie s'applique.
bool pour spécifier si l'algorithme doit trier en ordre croissant ou non.
*/
void Liste::MergeSort(Noeud** headRef, SortType type, bool croissant)
{
	Noeud* head = *headRef;
	Noeud* left;
	Noeud* right;
	//Liste non existante ou une Liste d'un seul élément est déjà trié.
	if ((head == NULL) || head->pNext == NULL)
	{
		return;
	}
	//Divise les Noeuds en deux
	FrontBackSplit(head, &left, &right);
	//Appel récursif
	MergeSort(&left, type, croissant);
	MergeSort(&right, type, croissant);
	//Trie et Fusion
	*headRef = SortedMerge(left, right, type, croissant);

}


/*
Méthode qui avec deux pointeurs sur des objets Noeuds, les positionnes en ordre (pNext, pBack) selon les critères de sélection
SortType type et bool croissant.
*/
Noeud* Liste::SortedMerge(Noeud* left, Noeud* right, SortType type, bool croissant)
{
	Noeud* result = NULL;
	if (left == NULL)
		return right;
	else
		if (right == NULL)
			return left;
	//Évalue selon le type de trie et si l'ordre croissant est désiré.
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


/*
Retourne true or false.
Évaluation selon SortType type et bool croissant pour déterminer si les données d'Abonnement du
Noeud left est plus grand ou plus petit que les données d'Abonnement du Noeud right.

*/
bool Liste::EvaluateSortType(Noeud* left, Noeud* right, SortType type, bool croissant)
{
	switch (type)
	{
		//Trie sur le numéro du client
	case SortType::ID:
		if (croissant)
			return (left->pInfo->getId() <= right->pInfo->getId());
		return (left->pInfo->getId() >= right->pInfo->getId());
		break;
		//Trie sur le nom du client
	case SortType::NOM:
		if (croissant)
			return (left->pInfo->getNom() <= right->pInfo->getNom());
		return (left->pInfo->getNom() >= right->pInfo->getNom());
		break;
		//Titre sur le titre
	case SortType::TITRE:
		if (croissant)
			return (left->pInfo->getTitre() <= right->pInfo->getTitre());
		return (left->pInfo->getTitre() >= right->pInfo->getTitre());
		break;
		//Trie sur la date
	case SortType::DATE:
		if (croissant)
			return (left->pInfo->getDebutAbonnement() <= right->pInfo->getDebutAbonnement());
		return (left->pInfo->getDebutAbonnement() >= right->pInfo->getDebutAbonnement());
		break;
		//Ne devrait pas ce produire sauf si on rajoute un élément dans l'ENUM SortType et que l'on oublie de l'implémenter dans EvaluateSortType()
	default:
		cout << "Liste::EvaluateSortType : NotImplemented Argument";
		return false;
		break;

	}
}

/*
Sépare les liens entre les noeuds.
*/
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

//Affiche tout les éléments de la Liste.
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