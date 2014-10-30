#include "librairie.h"

void DateEpoch::Affiche()
{
   cout << An << "-" << Mois << "-" << Jour << endl;
}

string DateEpoch::ToString()
{
	stringstream ss;
	ss.str(std::string());
	ss << An << "-" << Mois << "-" << Jour << endl;
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
   struct tm* ptm = new struct tm;
   localtime_s(ptm, &Epoch);
   An = ptm->tm_year + 1900;
   Mois = ptm->tm_mon + 1;
   Jour = ptm->tm_mday;
   Heure = ptm->tm_hour;
   Minute = ptm->tm_min;
   Seconde = ptm->tm_sec;
}

void DateEpoch::ConvertFormatToEpoch()
{
   struct tm* ptm = new struct tm;
   localtime_s(ptm, &Epoch);

   ptm->tm_year = An - 1900;
   ptm->tm_mon = Mois + 1;
   ptm->tm_mday = Jour;
   Epoch = mktime(ptm);
}


bool DateEpoch::operator< (DateEpoch& rh)
{
   if (this->An < rh.An || this->Mois < rh.Mois
      || this->Jour < rh.Jour)
   {
      return true;
   }
   return false;
}

bool DateEpoch::operator== (DateEpoch& rh)
{
   if (this->An == rh.An && this->Mois == rh.Mois
      && this->Jour == rh.Jour)
   {
      return true;
   }
   return false;
}

bool DateEpoch::operator<= (DateEpoch& rh)
{
   return !(*this > rh);
}

bool DateEpoch::operator!= (DateEpoch& rh)
{
   return !(*this == rh);
}

bool DateEpoch::operator>= (DateEpoch& rh)
{
   return !(*this < rh);
}

bool DateEpoch::operator> (DateEpoch& rh)
{
   return rh < *this;
}