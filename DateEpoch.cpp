


#include "librairie.h"

void DateEpoch::Affiche()
{
	cout << An << "-";
	//Pour s'assurer d'afficher deux digit pour respecter le format de date de 10 caract�res
	if (Mois < 10)
		cout << 0;

	cout << Mois << "-";
	if (Jour < 10)
		cout << 0;
	cout << Jour << endl;
}

string DateEpoch::ToString()
{
	stringstream ss;
	ss.str(std::string());

	ss << An << "-";
	if (Mois < 10)
		ss << 0;

	ss << Mois << "-";
	if (Jour < 10)
		ss << 0;
	ss << Jour;
	return ss.str();
}


DateEpoch::DateEpoch()
{
	Epoch = time(NULL);
	ConvertEpochToFormat();
}

DateEpoch::DateEpoch(int A, int M, int J)
{
	An = A;
	Mois = M;
	Jour = J;
	ConvertFormatToEpoch();
}

DateEpoch::DateEpoch(int E)
{
	Epoch = E;
	ConvertEpochToFormat();
}

void DateEpoch::ConvertEpochToFormat()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	//https://stackoverflow.com/questions/119578/disabling-warnings-generated-via-crt-secure-no-deprecate
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
	// deprecated code here
	timeinfo = localtime(&rawtime);
#pragma warning(pop)
	//struct tm* timeinfo = new struct tm;
	//localtime_s(timeinfo, &Epoch);
	An = timeinfo->tm_year + 1900;
	Mois = timeinfo->tm_mon + 1;
	Jour = timeinfo->tm_mday;
	Heure = timeinfo->tm_hour;
	Minute = timeinfo->tm_min;
	Seconde = timeinfo->tm_sec;
}

void DateEpoch::ConvertFormatToEpoch()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	//https://stackoverflow.com/questions/119578/disabling-warnings-generated-via-crt-secure-no-deprecate
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
	// deprecated code here
	timeinfo = localtime(&rawtime);
#pragma warning(pop)

	//struct tm* timeinfo = new struct tm;
	//localtime_s(timeinfo, &Epoch);
	timeinfo->tm_year = An - 1900;
	timeinfo->tm_mon = Mois + 1;
	timeinfo->tm_mday = Jour;
	Epoch = mktime(timeinfo);
}

//D�finission des op�rateurs de comparaisons
bool DateEpoch::operator< (const DateEpoch& rh)
{
	//Epoch �tant le nombre de seconde �coul� depuis 1970, on peut le compar� directement
	return this->Epoch < rh.Epoch;
}

bool DateEpoch::operator== (const DateEpoch& rh)
{

	return this->Epoch == rh.Epoch;
}

bool DateEpoch::operator<= (const DateEpoch& rh)
{
	return this->Epoch <= rh.Epoch;
}

bool DateEpoch::operator!= (const DateEpoch& rh)
{
	return this->Epoch != rh.Epoch;
}

bool DateEpoch::operator>= (const DateEpoch& rh)
{
	return this->Epoch >= rh.Epoch;
}

bool DateEpoch::operator> (const DateEpoch& rh)
{
	return this->Epoch > rh.Epoch;
}