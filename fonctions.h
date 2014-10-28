void AjoutAvecFichier(Liste*, string);
void AjoutInteractif(Liste*, Noeud*);

enum class ModifyType
{
	ADRESSE, PUBLICATION
};

void ModificationAbonnement(Liste*, Noeud*, string, ModifyType);