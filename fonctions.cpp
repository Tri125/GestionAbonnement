#include "librairie.h"



struct ManyDataField : public exception
{
	const char * what() const throw ()
	{
		return "Plus que 6 champs de données détectés";
	}
};

struct NotEnoughDataField : public exception
{
	const char * what() const throw ()
	{
		return "Moins que 6 champs de données détectés";
	}
};


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

		size_t pos = ligneCourante.find_first_not_of("\n \t");
		//find_first_not_of peut retourner string::npos (constante évalué à -1) si rien n'a été trouvé.
		//Si c'est le cas, ligne vide, commence par # ou mal formaté, break à l'extérieur du for pour prendre la prochaine ligne.
		if (pos == string::npos)
		{
			continue;
		}
		// Ligne avec les espaces en début retiré.
		ligneCourante = ligneCourante.substr(pos);

		//Commence par un hashtag, donc ligne de commentaire
		if (ligneCourante[0] == '#')
			continue;
		try
		{
			//ValidationChamps(ligneCourante);
			liste->Ajouter(TraitementLigne(ligneCourante));
		}
		catch (invalid_argument&)
		{
			cout << endl;
			cout << "Erreur: Numéro d'abonnement n'est pas un entier." << endl;
			cout << "Fichier: " << nomFichier << endl << "Ligne: " << nbLigne << endl;
			system("pause");
			continue;
		}

		catch (exception& e)
		{
			cout << endl;
			cout << "Erreur: " << e.what() << endl;
			cout << "Fichier: " << nomFichier << endl << "Ligne: " << nbLigne << endl;
			system("pause");
			continue;
		}

		//cout << ligneCourante << endl;
	}



	ficIn.close();

}


/*
https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
Solution de Loki Astari
*/
Noeud* TraitementLigne(string ligne)
{
	const char SEPARATING_SYMBOL = ';';
	const int NOMBRE_CHAMPS = 6;

	vector<string> client;
	stringstream ss(ligne);
	string data;
	unsigned int id = 0;
	double tmp = 0;

	while (getline(ss, data, SEPARATING_SYMBOL))
	{
		client.push_back(data);
	}

	if (client.size() > NOMBRE_CHAMPS)
		throw ManyDataField();
	//Pas besoin de else, c'est du code unreacheable de toute manière.
	if (client.size() < NOMBRE_CHAMPS)
		throw NotEnoughDataField();

	size_t longueur;
	for (int i = 0; i < NOMBRE_CHAMPS; i++)
	{
		longueur = client[i].size();
		switch (i)
		{
		case (int)DataType::ID:
			tmp = stod(client[i]);
			char precedent;
			for (size_t index = 0; index < client[i].length(); index++)
			{
				if (index == client[i].length() - 1)
					break;
				if (isspace(client[i][index]) && isdigit(precedent))
					throw invalid_argument("");
				precedent = client[i][index];
			}
			if (floor(tmp) == tmp && client[i].find(',') == string::npos)
				id = stoul(client[i]);
			else
				throw invalid_argument("");
			break;
		case (int)DataType::PRENOM:
			if (longueur <= 0 || longueur > 20)
				throw runtime_error("Longueur Prenom n'est pas situé entre 0 et 20 caractères");
			break;
		case (int)DataType::NOM:
			if (longueur <= 0 || longueur > 20)
				throw runtime_error("Longueur Nom n'est pas situé entre 0 et 20 caractères");
			break;
		case (int)DataType::TITRE:
			if (longueur <= 0 || longueur > 20)
				throw runtime_error("Longueur Titre n'est pas situé entre 0 et 20 caractères");
			break;
		case (int)DataType::ADRESSE:
			if (longueur <= 0 || longueur > 50)
				throw runtime_error("Longueur Adresse n'est pas situé entre 0 et 50 caractères");
			break;
		case (int)DataType::DATE:
			if (longueur != 10)
				throw runtime_error("Longueur Date n'est pas 10 caractères");
			break;
		default:
			cout << "fonctions.cpp TraitementLigne(), la longueur du champs aurait du être déjà validé.\n";
			throw exception();
			break;
		}
	}

	DateEpoch date = ValidationDate(client[(int)DataType::DATE]);
	return new Noeud(id, client[1], client[2], client[3], client[4], date);
}


DateEpoch ValidationDate(string date)
{
	const string pattern = "\\d\\d\\d\\d-\\d\\d-\\d\\d";
	cmatch match;
	regex dateRegex(pattern, regex_constants::ECMAScript);
	regex_match(date.c_str(), match, dateRegex);

	if (match.size() != 1)
		throw runtime_error("N'est pas un format date valide");
	string validatedFormat = match[0].str();

	int annee;
	int mois;
	int jour;
	//La forme est déjà validé avec une regex. On peu donc ce permettre un peu de liberté concernant la conversion sans avoir peur de lancer d'exception.
	annee = stoi(validatedFormat.substr(0, 4));
	mois = stoi(validatedFormat.substr(5, 7));
	jour = stoi(validatedFormat.substr(8));

	DateEpoch validatedTime(annee, mois, jour);
	if (validatedTime.Epoch == -1)
		throw runtime_error("N'est pas une date qui peut être représenté");

	return validatedTime;
}



//void ValidationChamps(string ligne)
//{
//   const string SEPARATING_SYMBOL = ";";
//   int nbrChamps = 0;
//   size_t pos = ligne.find(SEPARATING_SYMBOL, 0);
//
//   while (pos != string::npos)
//   {
//      nbrChamps++;
//      pos = ligne.find(SEPARATING_SYMBOL, pos + 1);
//   }
//   if (nbrChamps > 5)
//      throw ManyDataField();
//
//   if (nbrChamps < 5)
//      throw NotEnoughDataField();
//
//}

bool ValidationInteractif(string prenom, string nom, string titre, string adresse, DateEpoch date)
{
	bool valide = true;
	size_t taille = prenom.length();

	if (taille <= 0 || taille > 20)
	{
		valide = false;
		cout << "Longueur Prénom n'est pas situé entre 0 et 20 caractères";
		cout << endl;
	}

	taille = nom.length();

	if (taille <= 0 || taille > 20)
	{
		valide = false;
		cout << "Longueur Nom n'est pas situé entre 0 et 20 caractères";
		cout << endl;
	}
	taille = titre.length();

	if (taille <= 0 || taille > 20)
	{
		valide = false;
		cout << "Longueur Titre n'est pas situé entre 0 et 20 caractères";
		cout << endl;
	}

	taille = adresse.length();

	if (taille <= 0 || taille > 50)
	{
		valide = false;
		cout << "Longueur Adresse n'est pas situé entre 0 et 50 caractères";
		cout << endl;
	}

	if (date.Epoch == -1)
	{
		valide = false;
		cout << "N'est pas une date qui peut être représenté";
		cout << endl;
	}

	if (!valide)
		system("pause");
	return valide;
}

void ModificationAbonnement(Liste*, Noeud*, string, ModifyType)
{

}

void AjoutInteractif(Liste* liste, string prenom, string nom, string titre, string adresse, DateEpoch date)
{
	unsigned int id = 0;
	try
	{
		id = GenererGUID(liste);
	}
	catch (runtime_error& e)
	{
		id = 0;
		cout << e.what();
		cout << endl << "\nErreur: Le numéro 0 lui sera assigné par défault\n";
		system("pause");
	}
	liste->Ajouter(new Noeud(id, prenom, nom, titre, adresse, date));
}


unsigned int GenererGUID(Liste* liste)
{
	unsigned int guid = 0;
	const int MAX_TRY = 100;
	int currentTry = 0;
	do
	{
		if (currentTry > MAX_TRY)
		{
			throw runtime_error("fonctions::GenererGUID impossible à trouver un GUID dans un délais acceptable.");
		}
		//Max étant la valeur maximal d'un unsigned int
		guid = rand() % 4294967296;
		currentTry++;
	} while (liste->RechercheAbonnement(guid));
	return guid;
}