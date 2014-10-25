class Abonnement{
private:
	unsigned int id;
	string prenom;
	string nom;
	string titre;
	string adresse;
	DateEpoch debutAbonnement;

public:

	string ToString();

#pragma region Constructeur
	Abonnement();
	Abonnement(int, string, string, string, string, DateEpoch);
	Abonnement(int, string, string, string, string, int, int, int);
#pragma endregion Constructeur


#pragma region Getter
	unsigned int getId();
	string getPrenom();
	string getNom();
	string getTitre();
	string getAdresse();
	DateEpoch getDebutAbonnement();
#pragma endregion Getter

#pragma region Setter
	void settPrenom(string);
	void setNom(string);
	void setTitre(string);
	void setAdresse(string);
	void setDebutAbonnement(DateEpoch);
	void setDebutAbonnement(int, int, int);
#pragma endregion Setter

};