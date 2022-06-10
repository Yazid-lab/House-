#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED
typedef struct {
    int day;
    int month;
    int year;
}date;
typedef struct {
    int id;
    float surface;
    char description[100];
}appart;
typedef struct {
    char nom[50];
    date date_debut;
    date date_fin;
    appart appartement;

}location;
location saisir_location();
void afficher_location(location l);
int recherchelocation();
int supprimerlocation();
void changer_information();
void initialiser_location(location l);
int comparer_date(date d1,date d2);//return 1 if d1>d2 return 0 if d1=d2 return -1 if d1<d2
int verifier_appartement(location l[],int n,date debut_nouvelle_location);//return 1 if appart is free



#endif // LOCATION_H_INCLUDED
