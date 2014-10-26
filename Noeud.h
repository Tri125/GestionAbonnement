class Noeud{

private:


public:
	Noeud* pNext;
	Noeud* pBack;
	Abonnement* pInfo;

	Noeud();
	Noeud(Abonnement*);
	Noeud(unsigned int, string, string, string, string, DateEpoch);
	Noeud(unsigned int, string, string, string, string, int, int, int);
	~Noeud();
	string ToString();

#pragma region Getter
	Abonnement* getPInfo();
#pragma endregion Getter

#pragma region Setter
	void setPInfo(Abonnement*);
#pragma endregion Setter
};