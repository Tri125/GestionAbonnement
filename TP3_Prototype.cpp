//------------------------------------
//  tp3_prototype.cpp
//
//
//  Par Alain Martel

//  Ce programme est un prototype "hardcodé" donnant un aperçu de la fonctionalité 
//  à mettre en place pour le TP3.
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

Liste* clients = new Liste();
//------------------------------------
//
//-------------------------------------
void main()
{
	srand((unsigned int)time(NULL));
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
	delete clients;
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
	cout << "\tF-à partir d'un Fichier\n";
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
	unsigned int id;
	bool erreur = false;
	Abonnement* cible;
	do
	{
		try
		{
			erreur = false;
			EcranBienvenue();
			cout << "\n\nModifications des informations d'un abonnement\n\n";
			cout << "Numéro d'abonnement à modifier:";
			cin >> NumAbonnement;
			id = stol(NumAbonnement);
		}
		catch (invalid_argument&)
		{
			cout << endl;
			cout << "\nErreur: Numéro d'abonnement n'est pas un entier.\n" << endl;
			system("pause");
			erreur = true;
		}
	} while (erreur);
	cible = clients->RechercheAbonnement(id);
	if (!cible)
	{
		cout << "\nErreur: Abonnement introuvable.\n";
		system("pause");
		return;
	}
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
	Choix = Confirmation("Vous êtes bien sûr de vouloir vider la liste?");

	switch (toupper(Choix))
	{
	case 'C': MessageDeConfirmation();
		clients->Vidage();
		break;
	default:break;
	}
}

//------------------------------------
//
//-------------------------------------
char MenuModifier(string NumAbonnement)
{
	unsigned int id;
	Abonnement* cible;
	char Choix;

	//NumAbonnement déjà convertie sans erreur à l'appel précédent. Idéalement je changerais l'appel de fonction.
	id = stol(NumAbonnement);
	cible = clients->RechercheAbonnement(id);
	EcranBienvenue();
	cible->AffichageDetailer();

	cout << "\tModifier:\n\n";
	cout << "\t\tA-Adresse\n";
	cout << "\t\tV-Publication\n";
	cout << "\t\tQ-retour au menu précédent\n";
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
	unsigned int id;
	Abonnement* cible;
	bool erreur = false;
	//NumAbonnement déjà convertie sans erreur à l'appel précédent. Idéalement je changerais l'appel de fonction.
	id = stol(Num);
	cible = clients->RechercheAbonnement(id);
	getline(cin, tampon);
	do
	{
		erreur = false;
		EcranBienvenue();
		cout << "\n\nModification de l'adresse de l'abonnement " << Num << "\n\n";
		cout << "\t\t Ancienne adresse\t: " << cible->getAdresse() << "\n\n";

		cout << "\t\t Nouvelle adresse\t: ";
		getline(cin, NeoAdresse);
		if (!isValidAdresse(NeoAdresse))
		{
			erreur = true;
			cout << "\t\tErreur: Adresse n'est pas situé entre 0 et 50 caractères\n";
			system("pause");
		}
	} while (erreur);

	EcranBienvenue();
	cout << "\n\nNouvelle adresse proposée pour abonnement " << Num << "\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tAdresse\t\t:" << NeoAdresse << endl;
	cout << "-------------------------------------------\n";
	Choix = Confirmation("Enregistrer les changements");
	switch (toupper(Choix))
	{
	case 'C':
		MessageDeConfirmation();
		cible->setAdresse(NeoAdresse);
		break;
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
	unsigned int id;
	Abonnement* cible;
	bool erreur = false;
	//NumAbonnement déjà convertie sans erreur à l'appel précédent. Idéalement je changerais l'appel de fonction.
	id = stol(Num);
	cible = clients->RechercheAbonnement(id);
	getline(cin, tampon);
	do
	{
		erreur = false;


		EcranBienvenue();
		cout << "\n\nModification de la Publication de: " << Num << "\n\n";
		cout << "\t\t Ancienne Publication\t: " << cible->getTitre() << "\n\n";
		cout << "\t\t Nouvelle Publication\t: ";
		getline(cin, NeoPublication);

		if (!isValidTitre(NeoPublication))
		{
			erreur = true;
			cout << "\t\tErreur: Publication n'est pas situé entre 0 et 20 caractères\n";
			system("pause");
		}

	} while (erreur);

	EcranBienvenue();
	cout << "\n\nNouvelle Publication de l'abonnement " << Num << "\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tPublication\t\t:" << NeoPublication << endl;
	cout << "-------------------------------------------\n";
	Choix = Confirmation("Modifier la Publication");
	switch (toupper(Choix))
	{
	case 'C':
		MessageDeConfirmation();
		cible->setTitre(NeoPublication);
		break;
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
	int i = clients->getCompteur();
	//char Choix;

	EcranBienvenue();
	cout << "\n\nAjout d'abonnements à partir d'un fichier\n\n";
	cout << "Fichier à charger:";
	cin >> FicIn;
	AjoutAvecFichier(clients, FicIn);
	cout << "-- Chargement de " << FicIn << " en cours ...\n";
	cout << "-- " << clients->getCompteur() - i << " abonnements ajoutés. Chargement terminé.\n\n";
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
	DateEpoch DateAdhesion;
	string Publication;
	char Choix;
	do
	{
		EcranBienvenue();
		cout << "\n\nAjout interactif d'un abonnement\n\n";
		cout << "Nom\t\t:";
		cin >> Nom;
		getline(cin, tampon);
		cout << "Prénom\t\t:";
		getline(cin, Prenom);
		cout << "Adresse\t\t:";
		getline(cin, Adresse);

		DateAdhesion = DateEpoch();
		cout << "Publication\t:";
		getline(cin, Publication);
	} while (!ValidationInteractif(Prenom, Nom, Publication, Adresse, DateAdhesion));

	EcranBienvenue();
	cout << "\n\nInfo du nouvel abonnement:\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tNom\t\t:" << Nom << endl;
	cout << "\tPrénom\t\t:" << Prenom << endl;
	cout << "\tAdresse\t\t:" << Adresse << endl;
	cout << "\tDate abonnement\t:";
	DateAdhesion.Affiche();
	cout << "\tPublication\t:" << Publication << endl << endl;
	cout << "-------------------------------------------\n";

	Choix = Confirmation("Voulez-vous ajouter ce abonnement?");
	switch (toupper(Choix))
	{
	case 'C':
		AjoutInteractif(clients, Prenom, Nom, Publication, Adresse, DateAdhesion);
		MessageDeConfirmation();
		break;

	default:break;
	}
}

//------------------------------------
//
//-------------------------------------
void MessageDeConfirmation()
{
	EcranBienvenue();
	cout << "\n\n\t-*-*-*-*Opération traitée avec succès-*-*-*-*\n\n\n";
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
		case '1': TrierListe("Numéro d'abonnement", "croissant");
			clients->Trier(Liste::SortType::ID, true);
			break;
		case '2': TrierListe("Numéro d'abonnement", "décroissant");
			clients->Trier(Liste::SortType::ID, false);
			break;
		case '3': TrierListe("Nom abonné", "croissant");
			clients->Trier(Liste::SortType::NOM, true);
			break;
		case '4': TrierListe("Nom abonné", "décroissant");
			clients->Trier(Liste::SortType::NOM, false);
			break;
		case '5': TrierListe("Date abonnement", "croissant");
			clients->Trier(Liste::SortType::DATE, true);
			break;
		case '6': TrierListe("Date abonnement", "décroissant");
			clients->Trier(Liste::SortType::DATE, false);
			break;
		case '7': TrierListe("Publication", "croissant");
			clients->Trier(Liste::SortType::TITRE, true);
			break;
		case '8': TrierListe("Publication", "décroissant");
			clients->Trier(Liste::SortType::TITRE, false);
			break;
		default: break;
		}
	}
}

void TrierListe(string Critere, string Ordre)
{
	EcranBienvenue();
	cout << "\n\nTri " << Ordre << " selon " << Critere << " en cours ...";
	cout << "\nTri complété\n";
	cout << "---------------------------------------------\n\n";
	system("pause");
}

char MenuTrier()
{
	char Choix;

	EcranBienvenue();
	cout << "\n\nTri de la liste des abonnements\n\n";
	cout << "\tTrier par:\n\n";
	cout << "\t\t1-Numéro (.:)\n";
	cout << "\t\t2-Numéro (:.)\n";
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
	bool erreur = false;
	char Choix;
	unsigned int id;

	do
	{
		try
		{
			EcranBienvenue();
			cout << "\n\n\n\tNuméro d'abonnement à supprimer:";
			cin >> NumAbonnement;
			erreur = false;
			id = stol(NumAbonnement);
		}
		catch (invalid_argument&)
		{
			cout << endl;
			cout << "\n\tErreur: Numéro d'abonnement n'est pas un entier.\n" << endl;
			system("pause");
			erreur = true;
		}
	} while (erreur);
	Abonnement* cible = clients->RechercheAbonnement(id);
	if (!cible)
	{
		cout << "\n\tErreur: Aucun Abonnement trouvé\n";
		system("pause");
		return;
	}
	cible->AffichageDetailer();
	Choix = Confirmation("Voulez vous le supprimer?");
	switch (toupper(Choix))
	{
	case 'C':
		clients->Supprimer(id);
		MessageDeConfirmation();
		break;
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
	cout << "\tÀ l'écran\n\n";
	cout << "\t\tL-Liste complète\n";
	cout << "\t\tE-liste complète, un Ecran à la fois\n";
	cout << "\t\tI-intervalle d'abonnements\n\n";
	cout << "\t\tC-un seul abonnement\n\n";
	cout << "\tDans un fichier\n\n";
	cout << "\t\tF-Liste complète\n";
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
	for (int i = 0; i < 48; i++)
		cout << ligneH;
	cout << coinHD << endl;
	cout << ligneV << "                                                " << ligneV << endl;
	cout << ligneV << "     Les productions "" inc        " << ligneV << endl;
	cout << ligneV << "                                                " << ligneV << endl;
	cout << ligneV << "     Syst\x8Ame de gestion des abonnements         " << ligneV << endl;
	cout << ligneV << "                                                " << ligneV << endl;
	cout << coinBG;
	for (int i = 0; i < 48; i++)
		cout << ligneH;
	cout << coinBD << endl;
	setlocale(LC_ALL, "");

}

//------------------------------------
//
//-------------------------------------
void AfficherListeComplete(string option)
{
	Noeud* current = clients->getPremier();
	string FicOut;

	if (option == "fichier")
	{
		ofstream stream;
		EcranBienvenue();
		cout << "Nom du fichier qui recevra la liste:";
		cin >> FicOut;
		stream.open(FicOut, ios::out);
		cout << "Ecriture de la liste complète en cours...\n";
		while (current)
		{
			stream << current->pInfo->getId() << ";";
			stream << current->pInfo->getPrenom() << ";";
			stream << current->pInfo->getNom() << ";";
			stream << current->pInfo->getTitre() << ";";
			stream << current->pInfo->getAdresse() << ";";
			stream << current->pInfo->getDebutAbonnement().ToString();
			stream << endl;
		}
		cout << "Écriture de 475 abonnements terminée. Disponible dans le fichier " << FicOut << "\n";
	}
	else
	{
		cout << "Num   Nom                  Prenom               Publication                                Dates   \n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		for (unsigned int i = 1; i < clients->getCompteur(); i++)
		{
			if ((i % 50 == 0) && (option == "ecran"))
				system("pause");
			cout << i << " ";
			cout << "  " << current->pInfo->getNom() << "        ";
			cout << current->pInfo->getPrenom() << "               ";
			cout << current->pInfo->getTitre() << "     ";
			cout << current->pInfo->getAdresse() << "                         ";
			current->pInfo->getDebutAbonnement().Affiche();
			cout << " " << endl;
			current = current->pNext;
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
	cout << "\t\t1-Numéro abonnement\n";
	cout << "\t\t2-Date abonnement\n";
	cout << "\t\t3-Publication\n";
	cout << "\t\t4-Nom d'abonné\n\n";
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
	cout << "\n\nAffichage selon un intervalle de numéro abonnement\n\n";
	cout << "\n\nBorne inférieure:";
	cin >> BorneInf;
	cout << "Borne supérieure:";
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
		cout << "Ecriture de la liste par intervalle de numéro d'abonnement en cours...\n";
		cout << "Écriture de 14 abonnements terminée. Disponible dans le fichier " << FicOut << "\n";
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
			cout << "2003-07-25     " << endl;
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
	cout << "Même principe que l'affichage selon un intervalle de numéro-abonnement\n\n";
	AffichageTermine();

}
//------------------------------------
//
//-------------------------------------
void AfficheIntervValeur(string option)
{

	EcranBienvenue();
	cout << "\n\nAffichage selon un intervalle de publications\n\n";
	cout << "Même principe que l'affichage selon un intervalle de numéro-abonnement\n\n";
	AffichageTermine();


}
//------------------------------------
//
//-------------------------------------
void AfficheIntervNom(string option)
{

	EcranBienvenue();
	cout << "\n\nAffichage d'un intervalle de noms\n\n";
	cout << "Même principe que l'affichage de la liste selon un intervalle de numéro-abonnement\n\n";
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
	cout << "Numéro d'abonnement à afficher:";
	cin >> NumAbonnement;
	cout << "\n\nInformations de l'abonnement " << NumAbonnement << ":\n\n";
	cout << "-------------------------------------------\n";
	cout << "\tNom\t\t:Abramovitch" << endl;
	cout << "\tPrénom\t\t:Iossef" << endl;
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