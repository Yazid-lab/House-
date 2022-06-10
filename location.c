#include "location.h"
#include<stdio.h>
#include<string.h>
int recherchelocation(location tab[],int n,int id_rech)
{
    int i;
    for(i=0;i<n;i++)
    {
        if (id_rech==tab[i].appartement.id)
        {
            printf("La location recherchee est %s\n",tab[i].nom);
        }
        else
        {
            printf("la location n'existe pas\n");

        }
    }
    return 0;
}
int comparer_date(date d1,date d2)
{
    if (d1.year>d2.year)
        return 1;
    else if (d2.year>d1.year)
        return -1;
    else if (d1.month>d2.month)
        return 1;
    else if (d2.month>d1.month)
        return -1;
    else if (d1.day>d2.day)
        return 1;
    else if (d1.day<d2.day)
        return -1;
    return 0;
}
location saisir_location()
{
    location l;
    printf("donner le nom du locataire\n");
    scanf("%s",l.nom);
    do//saisie controlle de la date
    {
    do{
    fflush(stdin);
    printf("donner le jour de debut\n");//saisie de la date de debut
    }while((scanf("%d",&l.date_debut.day)!=1)|| ((l.date_debut.day<1) || (l.date_debut.day>30)));
    do{
    fflush(stdin);
    printf("donner le mois de debut\n");
    }while((scanf("%d",&l.date_debut.month)!=1)||((l.date_debut.month<1) || (l.date_debut.month>12)));
    do {
    fflush(stdin);
    printf("donner l'annee de debut\n");
    }while(scanf("%d",&l.date_debut.year)!=1);
    do{
    fflush(stdin);
    printf("donner le jour de fin\n");//saisie date fin
    }while((scanf("%d",&l.date_fin.day)!=1)||(l.date_fin.day<1 || l.date_fin.day>30));
    do{
    fflush(stdin);
    printf("donner le mois de fin\n");
    }while((scanf("%d",&l.date_fin.month)!=1)||(l.date_fin.month<1 || l.date_fin.month>12));
    do{
    fflush(stdin);
    printf("donner l'annee de fin\n");
    }while(scanf("%d",&l.date_fin.year)!=1);
    if ((comparer_date(l.date_fin,l.date_debut)==-1))
        printf("verfier les dates SVP\n");
    }while(comparer_date(l.date_fin,l.date_debut)<0);
    do
    {
    fflush(stdin);
    printf("donner l'id de l'appartement\n");
    }while(scanf("%i",&l.appartement.id)!=1);
    do
    {
    fflush(stdin);
    printf("donner la surface de l'appartement\n");
    }while(scanf("%f",&l.appartement.surface)!=1);
    printf("donner la description de l'appartement\n");
    scanf("%s",l.appartement.description);




return l;
}
void afficher_location(location l)
{
    printf("********************\n%s\ndate debut: %d /%d /%d \ndate fin : %d/%d/%d \n\n",l.nom,l.date_debut.day,l.date_debut.month,l.date_debut.year,l.date_fin.day,l.date_fin.month,l.date_fin.year);
    printf("********************\nAppartement:\nid de l'appartement: %d | surface:  %f | description: %s \n\n",l.appartement.id,l.appartement.surface,l.appartement.description);
}
int supprimerlocation(location tab[],int n,int indice)
{
    int i;
    for(i=indice;i<n;i++)
    {
        tab[i]=tab[i+1];
    }
    return n-1;
}
void changer_information(location tab[])
{
    char nouveau_nom[50];
    int choix,i;
    do{
        printf("tapez l'indice du locataire de la fiche à changer\n");
    }while(scanf("%d",&i)!=1);
    do
    {
        printf("tapez 1 si vous voulez changer le nom\n\t2 si vous voulez changer la date début\n\t3 si vous voulez changer la date fin\n\t4 si vous voulez changer l'appartement\n");

    }while(scanf("%d",&choix)!=1);
    switch(choix)
    {
    case 1:
        printf("\ndonnez le nouveau nom\n");
        scanf("%s",nouveau_nom);
        strcpy(tab[i].nom,nouveau_nom);
        break;
    case 2:
    do{
    fflush(stdin);
    printf("donner le jour de debut\n");//saisie de la date de debut
    }while((scanf("%d",&tab[i].date_debut.day)!=1)|| ((tab[i].date_debut.day<1) || (tab[i].date_debut.day>30)));
    do{
        fflush(stdin);
    printf("donner le mois de debut\n");
    }while((scanf("%d",&tab[i].date_debut.month)!=1)||((tab[i].date_debut.month<1) || (tab[i].date_debut.month>12)));
    do {
        fflush(stdin);
    printf("donner l'annee de debut\n");
    }while(scanf("%d",&tab[i].date_debut.year)!=1);
        break;
    case 3:
    do{
    fflush(stdin);
    printf("donner le jour de fin\n");//saisie date fin
    }while((scanf("%d",&tab[i].date_fin.day)!=1)||(tab[i].date_fin.day<1 || tab[i].date_fin.day>30));
    do{
    fflush(stdin);
    printf("donner le mois de fin\n");
    }while((scanf("%d",&tab[i].date_fin.month)!=1)||(tab[i].date_fin.month<1 || tab[i].date_fin.month>12));
    do{
        fflush(stdin);
    printf("donner l'annee de fin\n");
    }while(scanf("%d",&tab[i].date_fin.year)!=1);
        break;
    case 4:
        printf("donner l'id de l'appartement\n");//saisie de l'apparetement
        scanf("%i",&tab[i].appartement.id);
        printf("donner la surface de l'appartement\n");
        scanf("%f",&tab[i].appartement.surface);
        printf("donner la description de l'appartement\n");
        scanf("%s",tab[i].appartement.description);//fin saisie appartement
        break;
    default : printf("tapez un choix valide\n");
    }
}

