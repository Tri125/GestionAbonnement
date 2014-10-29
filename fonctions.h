void AjoutAvecFichier(Liste*, string);
void AjoutInteractif(Liste*, Noeud*);

enum class ModifyType
{
	ADRESSE, PUBLICATION
};

enum class DataType
{
	ID = 0, PRENOM = 1, NOM = 2, TITRE = 3, ADRESSE = 4, DATE = 5
};

void ModificationAbonnement(Liste*, Noeud*, string, ModifyType);
//void ValidationChamps(string);
Noeud* TraitementLigne(string);
DateEpoch ValidationDate(string);