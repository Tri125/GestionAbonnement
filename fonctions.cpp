#include "librairie.h"


void AjoutAvecFichier(Liste* liste, string nomFichier)
{
	ifstream ficIn;
	ficIn.open(nomFichier);
	string ligneCourante;
	int nbLigne = 0;

	while (!ficIn.is_open())
	{
		cout << "Erreur de lecture.\n";
		cout << "Veuillez entrer le nom du fichier contenant les citations : ";

		cin >> nomFichier;
		ficIn.open(nomFichier);
	}

	while (ficIn.good())
	{
		nbLigne++;
		getline(ficIn, ligneCourante);
		/*
		int pos = ligneCourante.find_first_not_of("\n ");
		//find_first_not_of peut retourner string::npos (constante �valu� � -1) si rien n'a �t� trouv�.
		//Si c'est le cas, ligne vide ou mal format�, break � l'ext�rieur du for pour prendre la prochaine ligne.
		if (pos == string::npos)
		{
		cout << "Erreur ligne " << nbLigne << " citation vide.\n";
		continue;
		}

		ligneCourante = ligneCourante.substr(pos);
		*/

		//Si la ligne n'est pas valide, continue � la prochaine boucle.
		//� pour effet d'aller chercher la prochaine ligne.
		//if (!ValidationLigne(ligneCourante, nbLigne))
			//continue;


	}



	ficIn.close();

}

void AjoutInteractif(Liste*, Noeud*)
{

}

void ModificationAbonnement(Liste*, Noeud*, string, ModifyType)
{

}