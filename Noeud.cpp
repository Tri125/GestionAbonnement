#include "librairie.h"

Noeud::Noeud()
{
	pInfo = nullptr;
	pNext = nullptr;
}

Noeud::Noeud(Abonnement* ab)
{
	pInfo = ab;
	pNext = nullptr;
	pBack = nullptr;
}

Noeud::Noeud(unsigned int i, string p, string n, string titre, string addr, DateEpoch date)
{
	pInfo = new Abonnement(i, p, n, titre, addr, date);
	pNext = nullptr;
	pBack = nullptr;
}

Noeud::Noeud(unsigned int i, string p, string n, string titre, string addr, int a, int m, int j)
{
	pInfo = new Abonnement(i, p, n, titre, addr, a, m ,j);
	pNext = nullptr;
	pBack = nullptr;
}

Noeud::~Noeud()
{
	delete pInfo;
}

Noeud* dernierNoeud(Noeud* racine)
{
	while (racine && racine->pNext)
		racine = racine->pNext;
	return racine;
}

string Noeud::ToString()
{
	return pInfo->ToString();
}

#pragma region Getter
Abonnement* Noeud::getPInfo()
{
	return pInfo;
}
#pragma endregion Getter

#pragma region Setter

void Noeud::setPInfo(Abonnement* info)
{
	pInfo = info;
}
#pragma endregion Setter