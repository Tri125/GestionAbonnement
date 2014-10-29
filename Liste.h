class Liste{

public:

	void Swap(Noeud*, Noeud*);
	enum class SortType
	{
		ID, NOM, PRENOM, DATE, TITRE
	};

	Liste();
	~Liste();
	void Ajouter(Noeud*);
	void Supprimer(unsigned int);
	void Trier(SortType, bool);
	Noeud* Recherche(unsigned int);
	unsigned int getCompteur();
	void Vidage();
	void Afficher();

private:

	unsigned int compteur;
	Noeud* premier;

	//Insert de O(1) for the win!
	Noeud* dernier;
	Noeud* SortedMerge(Noeud*, Noeud*, SortType, bool);
	void MergeSort(Noeud**, SortType, bool);
	void FrontBackSplit(Noeud*, Noeud**, Noeud**);
	bool EvaluateSortType(Noeud*, Noeud*, SortType, bool);

};