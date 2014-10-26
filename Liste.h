class Liste{
private:

	unsigned int compteur;
	Noeud* premier;

	//Insert de O(1) for the win!
	Noeud* dernier;
	void Swap(Noeud*, Noeud*);

public:

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
};