class Noeud{

private:
	Noeud* pNext;
	Abonnement* pInfo;

public:
	Noeud();
	Noeud(Abonnement*);
	~Noeud();
	string ToString();

#pragma region Getter
	Abonnement* getPInfo();
	Noeud* getPNext();
#pragma endregion Getter

#pragma region Setter
	void setPNext(Noeud*);
	void setPInfo(Abonnement*);
#pragma endregion Setter
};