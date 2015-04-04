

#include "librairie.h"


// Exception lorsqu'une ligne a plus que 6 champs de données.
struct ManyDataField : public exception
{
	const char * what() const throw ()
	{
		return "Plus que 6 champs de données détectés";
	}
};


// Exception lorsqu'une ligne a moins que 6 champs de données.
struct NotEnoughDataField : public exception
{
	const char * what() const throw ()
	{
		return "Moins que 6 champs de données détectés";
	}
};

// Fonction qui apartir d'un pointeur vers une Liste et d'un nom de fichier
// ouvre un flux d'entrée pour faire la lecture du fichier et populer la Liste de Noeuds.
void AjoutAvecFichier(Liste* liste, string nomFichier)
{
	ifstream ficIn;
	ficIn.open(nomFichier);
	string ligneCourante;
	int nbLigne = 0;

	//Si l'ouverture échoue, demande à nouveau nom de fichier.
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
		//Si c'est le cas, ligne vide ou mal formaté, continue pour prendre la prochaine ligne.
		if (pos == string::npos)
		{
			continue;
		}
		// Ligne avec les espaces en début retiré.
		ligneCourante = ligneCourante.substr(pos);

		//Commence par un hashtag, donc ligne de commentaire et on ignore
		if (ligneCourante[0] == '#')
			continue;
		try
		{
			//Envois la ligne dans la fonction TraitementLigne qui retourne un pointeur sur un objet Noeud
			// et le rajoute dans la liste.
			// TraitementLigne pour lancer une exception si la ligne n'est pas dans un format pour créer un objet Noeud.
			liste->Ajouter(TraitementLigne(ligneCourante));
		}
		//Exception lancer par la famille de fonctions stol  (string to long) et autres.
		// Est seulement utilisé pour convertir le numéro de client.
		catch (invalid_argument&)
		{
			//Affiche le nom du fichier et la ligne où ce trouve l'erreur.
			cout << endl;
			cout << "Erreur: Numéro d'abonnement n'est pas un entier." << endl;
			cout << "Fichier: " << nomFichier << endl << "Ligne: " << nbLigne << endl;
			Pause();
			continue;
		}

		//Autres exceptions
		catch (exception& e)
		{
			//Affiche le nom du fichier et la ligne où ce trouve l'erreur.
			cout << endl;
			cout << "Erreur: " << e.what() << endl;
			cout << "Fichier: " << nomFichier << endl << "Ligne: " << nbLigne << endl;
			Pause();
			continue;
		}

	}



	ficIn.close();

}


/*
https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
Solution de Loki Astari

Extrait les champs de données d'une string de format csv, les valides et les testes pour créer un objet Noeud
et retourner un pointeur du dit objet.
*/
Noeud* TraitementLigne(string ligne)
{
	//Caractère séparant les champs
	const char SEPARATING_SYMBOL = ';';
	const int NOMBRE_CHAMPS = 6;

	//Chaque string du vecteur est un champs de donnée extrait de la ligne.
	vector<string> client;
	//stringstream simplifie l'extraction de beaucoup d'efforts.
	stringstream ss(ligne);
	string data;
	unsigned int id = 0;
	double tmp = 0;

	//Extraction de chaque champs séparé par SEPARATING_SYMBOL et l'enregistre dans data.
	while (getline(ss, data, SEPARATING_SYMBOL))
	{
		//Met la donnée dans le vector.
		client.push_back(data);
	}

	//Lance une exception si plus que NOMBRE_CHAMPS a été extrait de la ligne
	if (client.size() > NOMBRE_CHAMPS)
		throw ManyDataField();
	//Lance une exception si moins que NOMBRE_CHAMPS a été extrait de la ligne
	if (client.size() < NOMBRE_CHAMPS)
		throw NotEnoughDataField();

	size_t longueur;
	for (int i = 0; i < NOMBRE_CHAMPS; i++)
	{
		longueur = client[i].size();
		switch (i)
		{
		case (int)DataType::ID:
			//string to double et enregistre le résultat dans tmp;
			//Lance une exception invalid_argument si stod échoue.
			tmp = stod(client[i]);
			if (tmp < 0)
				throw runtime_error("Le numéro client est négatif");
			char precedent;
			for (size_t index = 0; index < client[i].length(); index++)
			{
				//Essentiellement, teste pour voir si il y a un caractère qui sépare les numéros.
				//Est nécessaire, car stod va convertir la première partie continue sans problème malgré que le format soit innaceptable.
				if (index == client[i].length() - 1)
					break;
				if (isspace(client[i][index]) && isdigit(precedent))
					throw invalid_argument("");
				precedent = client[i][index];
			}
			//stod échoue pour les flottants séparé par un point ".", mais ignore les virgules.
			//Dois donc vérifier soit même pour ce cas.
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
			throw runtime_error("fonctions.cpp TraitementLigne(), la longueur du champs aurait du être déjà validé.");
			break;
		}
	}
	//Lance ValidationDate pour obtenir un objet DateEpoch validé.
	//Peut lancer des exceptions.
	DateEpoch date = ValidationDate(client[(int)DataType::DATE]);
	//Création d'un nouveau objet Noeud et retour de son pointeur.
	return new Noeud(id, client[1], client[2], client[3], client[4], date);
}

/*
D'après un string, vérifie si c'est d'un format YYYY-MM-DD pour créer un objet DateEpoch et le retourner.
Utilise une expression régulière pour valider le format.
*/
DateEpoch ValidationDate(string date)
{
	// 0000-00-00
	const string pattern = "[0-9]{4}-[0-9]{2}-[0-9]{2}";
	//Les résultats seront enregistrés dans le cmatch.
	cmatch match;
	//Charge le moteur regex avec le motif et en spécifiant la nomenclature ECMAScript
	regex dateRegex(pattern, regex_constants::extended);
	//Lance le moteur regex! regex_match avec une cible, un cmatch pour mettre les résultats et une regex pour trouver les résultats.
	regex_match(date.c_str(), match, dateRegex);

	//Plus qu'un match, moins qu'un match? Ce n'est pas d'un format que l'on s'attend.
	//Lance une exception
	if (match.size() != 1)
		throw runtime_error("N'est pas un format date valide");
	//Le motif de la date maintenant validé, on l'enregistre dans une string et l'on peut prendre certaine liberté pour
	//en extraire les années, les mois et les jours.
	string validatedFormat = match[0].str();

	int annee;
	int mois;
	int jour;
	//La forme est déjà validé avec une regex. On peu donc ce permettre un peu de liberté concernant la conversion sans avoir peur de lancer des exceptions.
	annee = stoi(validatedFormat.substr(0, 4));
	mois = stoi(validatedFormat.substr(5, 7));
	jour = stoi(validatedFormat.substr(8));

	//Création d'un objet DateEpoch
	DateEpoch validatedTime(annee, mois, jour);
	//Si Epoch, le nombre de secondes depuis 1970, est à -1, alors l'objet n'a pas reçu une date qui peut être représenté.
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
		Pause();
	return valide;
}

//void ModificationAbonnement(Liste*, Noeud*, string, ModifyType)
//{
//
//}

/*
À partir d'un pointeur vers un objet Liste, de 4 string et d'un objet DateEpoch, crée un objet Noeud et le rajoute dans l'objet Liste.
*/
void AjoutInteractif(Liste* liste, string prenom, string nom, string titre, string adresse, DateEpoch date)
{
	unsigned int id = 0;
	try
	{
		//Essaie de trouver un numéro client non utilisé
		id = GenererGUID(liste);
	}
	catch (runtime_error& e)
	{
		id = 0;
		cout << e.what();
		//Est une mauvaise idée puisque si le numéro 0 est déjà utilisé, les opérations de suppression, de recherche et de modification
		//sera brisé.
		cout << endl << "\nErreur: Le numéro 0 lui sera assigné par défault\n";
		Pause();
	}
	liste->Ajouter(new Noeud(id, prenom, nom, titre, adresse, date));
}

/*
Génère un unsigned int au hasard et vérifie si le nombre est déjà utilisé par un objet Abonnement dans la Liste.
Si c'est le cas, tente une nouvelle génération au hasard.
*/
unsigned int GenererGUID(Liste* liste)
{
	unsigned int guid = 0;
	const int MAX_TRY = 1000;
	int currentTry = 0;
	do
	{
		if (currentTry > MAX_TRY)
		{
			//À déjà essayé MAX_TRY fois. Peut-être qu'il ne reste plus de nombre libre qui peut être représenté par un unsigned int
			//On que la liste est trop saturé qu'il est difficile de ne pas générer un au hasard qui n'est pas déjà utilisé.
			throw runtime_error("fonctions::GenererGUID impossible à trouver un GUID dans un délais acceptable.");
		}
		//Max étant la valeur maximal d'un unsigned int
		guid = rand() % 4294967296;
		currentTry++;
	} while (liste->RechercheAbonnement(guid));
	return guid;
}


bool isValidAdresse(string adresse)
{
	if (adresse.length() > 0 && adresse.length() <= 50)
		return true;
	return false;
}

bool isValidTitre(string titre)
{
	if (titre.length() > 0 && titre.length() <= 20)
		return true;
	return false;
}

void Pause()
{
	cout << "Appuyer sur une touche pour continuer.";
	cin.sync();
	cin.get();
}