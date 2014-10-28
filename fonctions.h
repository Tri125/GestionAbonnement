void AjoutAvecFichier(Liste*, string);
void AjoutInteractif(Liste*, Noeud*);

enum class ModifyType
{
	ADRESSE, PUBLICATION
};

void ModificationAbonnement(Liste*, Noeud*, string, ModifyType);
void ValidationChamps(string);
Noeud* TraitementLigne(string);