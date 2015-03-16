

class Liste{

public:

	void Swap(Noeud*, Noeud*);

	//ENUM pour bien indiquer le type de Trie désiré.
	enum class SortType
	{
		ID, NOM, DATE, TITRE
	};

	Liste();
	~Liste();
	void Ajouter(Noeud*);
	void Supprimer(unsigned int);
	void Trier(SortType, bool);
	unsigned int getCompteur();
	void Vidage();
	void Afficher();
	Abonnement* RechercheAbonnement(unsigned int);
	Noeud* getPremier();

private:

	unsigned int compteur;
	Noeud* premier;
	Noeud* Recherche(unsigned int);
	Noeud* SortedMerge(Noeud*, Noeud*, SortType, bool);
	void MergeSort(Noeud**, SortType, bool);
	void FrontBackSplit(Noeud*, Noeud**, Noeud**);
	bool EvaluateSortType(Noeud*, Noeud*, SortType, bool);

};