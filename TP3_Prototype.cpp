//------------------------------------
//  tp3_prototype.cpp
//
//
//  Par Alain Martel

//  Ce programme est un prototype "hardcod�" donnant un aper�u de la fonctionalit� 
//  � mettre en place pour le TP3.
//  
//-------------------------------------

#include "librairie.h"


void EcranBienvenue();
char MenuPrincipal();

void Ajouter();
char MenuAjouter();
void ChargerFichier();
void AjoutInteractif();

void Modifier();
char MenuModifier(string);
void ModifierAdresse(string N);
void ModifierPublication(string N);

void Trier();
char MenuTrier();
void TrierListe(string Critere, string Ordre);

void Supprimer();

void Afficher();
char MenuAfficher();
void AfficherListeComplete(string);
void AfficherIntervalle(string);
void AfficheIntervNum(string option);
void AfficheIntervDate(string option);
void AfficheIntervValeur(string option);
void AfficheIntervNom(string option);
void AfficherUnAbonnement();
void AffichageTermine();

void Vider();

char Confirmation(string);
void MessageDeConfirmation();

void SupprimerAbonnement(int NumAbonnement);

void AfficherListeComplete(string);
void AfficherIntervalle(string);
void AfficheIntervNum(string option);
void AfficheIntervDate(string option);
void AfficheIntervValeur(string option);
void AfficheIntervNom(string option);

void AfficherUnAbonnement();

//------------------------------------
//
//-------------------------------------
void main()
{
	EcranBienvenue();
	char Choix;
	do
	{
		Choix = MenuPrincipal();
		switch (toupper(Choix))
		{
		case 'A': Ajouter(); break;
		case 'M': Modifier(); break;
		case 'T': Trier(); break;
		case 'S': Supprimer(); break;
		case 'F': Afficher(); break;
		case 'V': Vider(); break;
		default: break;
		}
	} while (Choix != 'Q');
}

//------------------------------------
//
//-------------------------------------
char MenuPrincipal()
{
	EcranBienvenue();
	char Choix;
	cout << "\n\nMenu principal:\n\n";
	cout << "\tA-Ajouter\n";
	cout << "\tM-Modifier\n";
	cout << "\tT-Trier\n";
	cout << "\tS-Supprimer\n";
	cout << "\tF-aFficher\n";
	cout << "\tV-Vider la liste\n\n";
	cout << "\tQ-Quitter\n";
	cout << "\t\tVotre choix:";
	cin >> Choix;
	return toupper(Choix);
}

//------------------------------------
//
//-------------------------------------
char MenuAjouter()
{
	EcranBienvenue();
	char Choix;
	cout << "\n\nAjout d'abonnements\n\n";
	cout << "\tF-� partir d'un Fichier\n";
	cout << "\tI-Interactivement\n";
	cout << "\tQ-menu Principal\n";

	cout << "\t\tVotre choix:";
	cin >> Choix;
	return toupper(Choix);
}


//------------------------------------
//
//-------------------------------------
void Modifier()
{
	char Choix;
	string NumAbonnement;

	EcranBienvenue();
	cout << "\n\nModifications des informations d'un abonnement\n\n";
	cout << "Num�ro d'abonnement � modifier:";
	cin >> NumAbonnement;


	Choix = MenuModifier(NumAbonnement);
	switch (Choix)
	{
	case 'A': ModifierAdresse(NumAbonnement); break;
	case 'V': ModifierPublication(NumAbonnement); break;
	default: break;
	}
}

//------------------------------------
//
//-------------------------------------
void Vider()
{
	char Choix;
	EcranBienvenue();
	cout << "\n\n\t";
	Choix = Confirmation("Vous �tes bien s�r de vouloir vider la liste?");

	switch (toupper(Choix))
	{
	case 'C': MessageDeConfirmation(); break;
	default:break;
	}
}

//------------------------------------
//
//-------------------------------------
char MenuModifier(string NumAbonnement)
{
	char Choix;
	EcranBienvenue();
	cout << "\n\nInformations de l'abonnement " << NumAbonnement << ":\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tNom\t\t:Abramovitch" << endl;
	cout << "\tPr�nom\t\t:Iossef" << endl;	
	cout << "\tPublication\t:L'actualit� nationale" << endl;
	cout << "\tAdresse\t\t:1234 Place Rouge" << endl;	

	cout << "\tDate abonnement\t:2003-07-25" << endl << endl;
	cout << "-------------------------------------------\n";

	cout << "\tModifier:\n\n";
	cout << "\t\tA-Adresse\n";
	cout << "\t\tV-Publication\n";
	cout << "\t\tQ-retour au menu pr�c�dent\n";
	cout << "\t\tVotre choix:";
	cin >> Choix;
	return toupper(Choix);
}

//------------------------------------
//
//------------------------------------
void ModifierAdresse(string Num)
{
	string NeoAdresse;
	string tampon;
	char Choix;

	EcranBienvenue();
	cout << "\n\nModification de l'adresse de l'abonnement " << Num << "\n\n";
	cout << "\t\t Ancienne adresse\t: 1234 Place Rouge\n\n";
	cout << "\t\t Nouvelle adresse\t: ";
	getline(cin, tampon);
	getline(cin, NeoAdresse);

	EcranBienvenue();
	cout << "\n\nNouvelle adresse propos�e pour abonnement " << Num << "\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tAdresse\t\t:" << NeoAdresse << endl;
	cout << "-------------------------------------------\n";
	Choix = Confirmation("Enregistrer les changements");
	switch (toupper(Choix))
	{
	case 'C': MessageDeConfirmation(); break;
	default:break;
	}
}

//------------------------------------
//
//-------------------------------------
void ModifierPublication(string Num)
{
	string NeoPublication;
	string tampon;
	char Choix;

	EcranBienvenue();
	cout << "\n\nModification de la Publication de: " << Num << "\n\n";
	cout << "\t\t Ancienne Publication\t: L'actualit� nationale\n\n";
	cout << "\t\t Nouvelle Publication\t: ";
	getline(cin, tampon);
	getline(cin, NeoPublication);

	EcranBienvenue();
	cout << "\n\nNouvelle Publication de l'abonnement " << Num << "\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tPublication\t\t:" << NeoPublication << endl;
	cout << "-------------------------------------------\n";
	Choix = Confirmation("Modifier la Publication");
	switch (toupper(Choix))
	{
	case 'C': MessageDeConfirmation(); break;
	default:break;
	}
}


//------------------------------------
//
//-------------------------------------
void Ajouter()
{
	char Choix;
	Choix = MenuAjouter();
	while (Choix != 'Q')
	{
		switch (toupper(Choix))
		{
		case 'F': ChargerFichier(); break;
		case 'I': AjoutInteractif(); break;
		case 'Q': return;
		default: break;
		}
		Choix = MenuAjouter();
	}
}

//------------------------------------
//
//-------------------------------------

void ChargerFichier()
{
	string FicIn;
	//char Choix;

	EcranBienvenue();
	cout << "\n\nAjout d'abonnements � partir d'un fichier\n\n";
	cout << "Fichier � charger:";
	cin >> FicIn;
	cout << "-- Chargement de " << FicIn << " en cours ...\n";
	cout << "-- 327 abonnements ajout�s. Chargement termin�.\n\n";
	system("pause");
}
//------------------------------------
//
//-------------------------------------
void AjoutInteractif()
{
	string Nom;
	string tampon;
	string Prenom;
	string Adresse;
	string DateAdhesion;
	string Publication;
	char Choix;

	EcranBienvenue();
	cout << "\n\nAjout interactif d'un abonnement\n\n";
	cout << "Nom\t\t:";
	cin >> Nom;
	getline(cin, tampon);
	cout << "Pr�nom\t\t:";
	getline(cin, Prenom);
	cout << "Adresse\t\t:";
	getline(cin, Adresse);
	
	DateAdhesion = "2014-10-10";
	cout << "Publication\t:";
	getline(cin, Publication);

	EcranBienvenue();
	cout << "\n\nInfo du nouvel abonnement:\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tNom\t\t:" << Nom << endl;
	cout << "\tPr�nom\t\t:" << Prenom << endl;
	cout << "\tAdresse\t\t:" << Adresse << endl;
	cout << "\tDate abonnement\t:" << DateAdhesion << endl;
	cout << "\tPublication\t:" << Publication << endl << endl;
	cout << "-------------------------------------------\n";

	Choix = Confirmation("Voulez-vous ajouter ce abonnement?");
	switch (toupper(Choix))
	{
	case 'C': MessageDeConfirmation(); break;
	default:break;
	}
}

//------------------------------------
//
//-------------------------------------
void MessageDeConfirmation()
{
	EcranBienvenue();
	cout << "\n\n\t-*-*-*-*Op�ration trait�e avec succ�s-*-*-*-*\n\n\n";
	system("pause");
}

//------------------------------------
//
//-------------------------------------
char Confirmation(string msg)
{
	char Choix;
	cout << "\t" << msg << "\n\n";
	cout << "\t\tC-Confirmer\n";
	cout << "\t\tA-ou autre touches pour Annuler\n";

	cout << "\t\tVotre choix:";
	cin >> Choix;
	return toupper(Choix);
}

//------------------------------------
//
//-------------------------------------
void Trier()
{
	char Choix;
	Choix = MenuTrier();
	if (Choix != 'Q')
	{
		switch (Choix)
		{
		case '1': TrierListe("Num�ro d'abonnement", "croissant"); break;
		case '2': TrierListe("Num�ro d'abonnement", "d�croissant"); break;
		case '3': TrierListe("Nom abonn�", "croissant"); break;
		case '4': TrierListe("Nom abonn�", "d�croissant"); break;
		case '5': TrierListe("Date abonnement", "croissant"); break;
		case '6': TrierListe("Date abonnement", "d�croissant"); break;
		case '7': TrierListe("Publication", "croissant"); break;
		case '8': TrierListe("Publication", "d�croissant"); break;
		default: break;
		}
	}
}

void TrierListe(string Critere, string Ordre)
{
	EcranBienvenue();
	cout << "\n\nTri " << Ordre << " selon " << Critere << " en cours ...";
	cout << "\nTri compl�t�\n";
	cout << "---------------------------------------------\n\n";
	system("pause");
}

char MenuTrier()
{
	char Choix;

	EcranBienvenue();
	cout << "\n\nTri de la liste des abonnements\n\n";
	cout << "\tTrier par:\n\n";
	cout << "\t\t1-Num�ro (.:)\n";
	cout << "\t\t2-Num�ro (:.)\n";
	cout << "\t\t3-Nom  (.:)\n";
	cout << "\t\t4-Nom  (:.)\n";
	cout << "\t\t5-Date abonnement (.:)\n";
	cout << "\t\t6-Date abonnement (:.)\n";
	cout << "\t\t7-Publication (.:)\n";
	cout << "\t\t8-Publication (:.)\n\n";
	cout << "\t\tQ-retour au menu Principal\n";

	cout << "\t\tVotre choix:";
	cin >> Choix;
	return toupper(Choix);
}
//------------------------------------
//
//-------------------------------------
void Supprimer()
{
	string NumAbonnement;
	char Choix;

	EcranBienvenue();
	cout << "\n\n\n\tNum�ro d'abonnement � supprimer:";
	cin >> NumAbonnement;
	cout << "-------------------------------------------\n";
	cout << "\tNom\t\t:Abramovitch" << endl;
	cout << "\tPr�nom\t\t:Iossef" << endl;	
	cout << "\tPublication\t:La semaine hebdo" << endl;
	cout << "\tAdresse\t\t:1234 Place Rouge" << endl;
	cout << "\tDate abonnement\t:2003-07-25" << endl << endl;
	cout << "-------------------------------------------\n";

	Choix = Confirmation("Voulez vous le supprimer?");
	switch (toupper(Choix))
	{
	case 'C': MessageDeConfirmation(); break;
	default:break;
	}
}

//------------------------------------
//
//-------------------------------------
void Afficher()
{
	char Choix;
	EcranBienvenue();
	Choix = MenuAfficher();
	while (Choix != 'Q')
	{
		switch (Choix)
		{
		case 'L': AfficherListeComplete(""); break;
		case 'E': AfficherListeComplete("ecran"); break;
		case 'F': AfficherListeComplete("fichier"); break;
		case 'I': AfficherIntervalle(""); break;
		case 'N': AfficherIntervalle("fichier"); break;
		case 'C': AfficherUnAbonnement(); break;
		default: break;
		}
		Choix = MenuAfficher();
	}
}

//------------------------------------
//
//-------------------------------------
char MenuAfficher()
{
	EcranBienvenue();
	char Choix;
	cout << "\n\nAffichage\n\n";
	cout << "Options d'affichage:\n\n";
	cout << "\t� l'�cran\n\n";
	cout << "\t\tL-Liste compl�te\n";
	cout << "\t\tE-liste compl�te, un Ecran � la fois\n";
	cout << "\t\tI-intervalle d'abonnements\n\n";
	cout << "\t\tC-un seul abonnement\n\n";
	cout << "\tDans un fichier\n\n";
	cout << "\t\tF-Liste compl�te\n";
	cout << "\t\tN-iNtervalle d'abonnements\n\n";
	cout << "\t\tQ-retour au menu Principal\n";

	cout << "\t\tVotre choix:";
	cin >> Choix;
	return toupper(Choix);
}


void EcranBienvenue()
{
	char coinHG = (char)201;
	char coinHD = (char)187;
	char coinBG = (char)200;
	char coinBD = (char)188;
	char ligneH = (char)205;
	char ligneV = (char)186;

	system("cls");
	setlocale(LC_ALL, "C");
	cout << coinHG;
	for (int i = 0; i<48; i++)
		cout << ligneH;
	cout << coinHD << endl;
	cout << ligneV << "                                                " << ligneV << endl;
	cout << ligneV << "  Les productions Votre Pr\x82nom Nom inc          " << ligneV << endl;
	cout << ligneV << "                                                " << ligneV << endl;
	cout << ligneV << "     Syst\x8Ame de gestion des abonnements         " << ligneV << endl;
	cout << ligneV << "                                                " << ligneV << endl;
	cout << coinBG;
	for (int i = 0; i<48; i++)
		cout << ligneH;
	cout << coinBD << endl;
	setlocale(LC_ALL, "");

}

//------------------------------------
//
//-------------------------------------
void AfficherListeComplete(string option)
{

	string FicOut;

	if (option == "fichier")
	{
		EcranBienvenue();
		cout << "Nom du fichier qui recevra la liste:";
		cin >> FicOut;
		cout << "Ecriture de la liste compl�te en cours...\n";
		cout << "�criture de 475 abonnements termin�e. Disponible dans le fichier " << FicOut << "\n";
	}
	else
	{
		cout << "Num   Nom                  Prenom               Publication                                Dates   \n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		for (int i = 1; i< 1000; i++)
		{
			if ((i % 50 == 0) && (option == "ecran"))
				system("pause");
			cout << i << " ";
			cout << "  Abramovitch        ";
			cout << "Iossef               ";
			cout << "La vie en rouge     ";
			cout << "1234 Place Rouge                         ";
			cout << "2003-07-25 " << endl;
		}
	}
	AffichageTermine();
}

//------------------------------------
//
//-------------------------------------
void AfficherIntervalle(string option)
{
	char Choix;
	EcranBienvenue();
	cout << "\n\nAffichage selon un intervalle\n\n";
	cout << "\t\t1-Num�ro abonnement\n";
	cout << "\t\t2-Date abonnement\n";
	cout << "\t\t3-Publication\n";
	cout << "\t\t4-Nom d'abonn�\n\n";
	cout << "\t\tA-retour au menu affichage\n";
	cout << "\t\tQ-retour au menu Principal\n";

	cout << "\t\tVotre choix:";
	cin >> Choix;
	switch (toupper(Choix))
	{
	case '1': AfficheIntervNum(option); break;
	case '2': AfficheIntervDate(option); break;
	case '3': AfficheIntervValeur(option); break;
	case '4': AfficheIntervNom(option); break;
	default: break;
	}
}

//------------------------------------
//
//-------------------------------------
void AfficheIntervNum(string option)
{
	int BorneTmp, BorneInf, BorneSup;
	string FicOut;

	EcranBienvenue();
	cout << "\n\nAffichage selon un intervalle de num�ro abonnement\n\n";
	cout << "\n\nBorne inf�rieure:";
	cin >> BorneInf;
	cout << "Borne sup�rieure:";
	cin >> BorneSup;

	if (BorneInf > BorneSup)
	{
		BorneTmp = BorneInf;
		BorneInf = BorneSup;
		BorneSup = BorneTmp;
	}

	if (option == "fichier")
	{
		cout << "\nNom du fichier qui recevra la liste par intervalle:";
		cin >> FicOut;
		cout << "Ecriture de la liste par intervalle de num�ro d'abonnement en cours...\n";
		cout << "�criture de 14 abonnements termin�e. Disponible dans le fichier " << FicOut << "\n";
	}
	else
	{
		cout << "Num     Nom                  Prenom               Publication                                Dates   \n";
		cout << "------------------------------------------------------------------------------------------------------\n";
		for (int i = BorneInf; i <= BorneSup; i++)
		{
			cout << i;
			cout << "\tAbramovitch        ";
			cout << "Iossef               ";
			cout << "La vie en rouge   ";
			cout << "1234 Place Rouge                         ";
			cout << "2003-07-25     "<< endl;
		}
	}
	AffichageTermine();

}
//------------------------------------
//
//-------------------------------------
void AfficheIntervDate(string option)
{

	EcranBienvenue();
	cout << "\n\nAffichage selon un intervalle d' abonnement\n\n";
	cout << "M�me principe que l'affichage selon un intervalle de num�ro-abonnement\n\n";
	AffichageTermine();

}
//------------------------------------
//
//-------------------------------------
void AfficheIntervValeur(string option)
{

	EcranBienvenue();
	cout << "\n\nAffichage selon un intervalle de publications\n\n";
	cout << "M�me principe que l'affichage selon un intervalle de num�ro-abonnement\n\n";
	AffichageTermine();


}
//------------------------------------
//
//-------------------------------------
void AfficheIntervNom(string option)
{

	EcranBienvenue();
	cout << "\n\nAffichage d'un intervalle de noms\n\n";
	cout << "M�me principe que l'affichage de la liste selon un intervalle de num�ro-abonnement\n\n";
	AffichageTermine();
}

//------------------------------------
//
//-------------------------------------
void AfficherUnAbonnement()
{

	int NumAbonnement;
	EcranBienvenue();
	cout << "\n\nAffichage d'une seul abonnement\n\n";
	cout << "Num�ro d'abonnement � afficher:";
	cin >> NumAbonnement;
	cout << "\n\nInformations de l'abonnement " << NumAbonnement << ":\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tNom\t\t:Abramovitch" << endl;
	cout << "\tPr�nom\t\t:Iossef" << endl;
	cout << "\tPublication\t:La semaine de l'info" << endl;
	cout << "\tAdresse\t\t:1234 Place Rouge" << endl;
	cout << "\tDate abonnement\t:2003-07-25" << endl << endl;

	cout << "-------------------------------------------\n";
	AffichageTermine();
}

//------------------------------------
//	cout << "\tPublication\t:La semaine de l'info" << endl Prenom
//-------------------------------------
void AffichageTermine()
{
	cout << "\n\t----------FIN---------------\n\n\n";
	system("pause");
}

