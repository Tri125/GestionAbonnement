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
}

Noeud::~Noeud()
{
	delete pInfo;
	delete pNext;
}

string Noeud::ToString()
{
	return nullptr;
}

#pragma region Getter
Abonnement* Noeud::getPInfo()
{
	return pInfo;
}

Noeud* Noeud::getPNext()
{
	return pNext;
}
#pragma endregion Getter

#pragma region Setter
void Noeud::setPNext(Noeud* next)
{
	pNext = next;
}

void Noeud::setPInfo(Abonnement* info)
{
	pInfo = info;
}
#pragma endregion Setter