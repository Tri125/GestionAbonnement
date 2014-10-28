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
         ValidationChamps(ligneCourante);
      }

      catch (exception& e)
      {
         cout << endl;
         cout << "Erreur: " << e.what() << endl;
         cout << "Fichier: " << nomFichier << " ligne: " << nbLigne << endl;
         system("pause");
         continue;
      }
      //Si la ligne n'est pas valide, continue à la prochaine boucle.
      //À pour effet d'aller chercher la prochaine ligne.
      //if (!ValidationLigne(ligneCourante, nbLigne))
      //continue;

      cout << ligneCourante << endl;
   }



   ficIn.close();

}

string TraitementLigne(string ligne)
{
   return NULL;
}

void ValidationChamps(string ligne)
{
   const string SEPARATING_SYMBOL = ";";
   int nbrChamps = 0;
   size_t pos = ligne.find(SEPARATING_SYMBOL, 0);

   while (pos != string::npos)
   {
      nbrChamps++;
      pos = ligne.find(SEPARATING_SYMBOL, pos + 1);
   }

   if (nbrChamps > 5)
      throw ManyDataField();

   if (nbrChamps < 5)
      throw NotEnoughDataField();

}

void AjoutInteractif(Liste*, Noeud*)
{

}

void ModificationAbonnement(Liste*, Noeud*, string, ModifyType)
{

}