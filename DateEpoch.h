
class DateEpoch
{
   int DateEpoch::An;
   int Mois;
   int Jour;
   int Heure;
   int Minute;
   int Seconde;


public:
   DateEpoch();
   DateEpoch(int, int, int);
   DateEpoch(int);
   time_t Epoch;
   void Affiche();
   bool operator< (DateEpoch&);
   bool operator<= (DateEpoch&);
   bool operator== (DateEpoch&);
   bool operator!= (DateEpoch&);
   bool operator>= (DateEpoch&);
   bool operator> (DateEpoch&);

private:

   void DateEpoch::ConvertEpochToFormat();
   void DateEpoch::ConvertFormatToEpoch();
};