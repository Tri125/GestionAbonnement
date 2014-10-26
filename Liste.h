class Liste{
private:
	Noeud* premier;

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
	void Recherche(unsigned int);
	Noeud* getPremier();
	void setPremier(Noeud*);
};