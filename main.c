#include "location.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main()
{
    location  l[30];
    int choix;
    int c,indice;
    int i=0;
    int taille=0;
    system("COLOR 17");
    FILE *fp;
    fp=fopen("Data.txt","r");
    if (fp==NULL)
        printf("Impossible d'ouvrir le fichier\n");

    else
    {
        printf("lecture en cours\n");
        while (!feof(fp))
        {
            fscanf(fp,"%s%d%d%d%d%d%d%d%f%s\n", l[taille].nom,&l[taille].date_debut.day,&l[taille].date_debut.month,&l[taille].date_debut.year,&l[taille].date_fin.day,&l[taille].date_fin.month,&l[taille].date_fin.year,&l[taille].appartement.id,&l[taille].appartement.surface,l[taille].appartement.description);
            taille++;
        }

    }
    fclose(fp);

    while (1)
    {
        do
        {
        fflush(stdin);
        printf("Taper 1 pour remplir les locations\n");
        printf("Taper 2 pour afficher les locations\n");
        printf("Taper 3 pour chercher une location\n");
        printf("Taper 4 pour modifier une location\n");
        printf("Taper 5 pour supprimer une location\n");
        printf("Taper 6 pour enregistrer et quitter\n");
        }while(scanf("%d",&choix)!=1);
        switch(choix)
        {
    case 0:
        printf("entrez un choix valide\n");
        break;

    case 1:
        do
        {
            l[taille]=saisir_location();
            taille++;
            do{
                fflush(stdin);
                    printf("Voulez vous ajouter une autre location\nTapez 1 si oui 0 si non\n");
            }while(scanf("%d",&c)!=1);
        }while(c==1 && taille<30);
    break;
    case 2:
        if (taille==0)
            printf("Aucune location enregistre\n");
        else{
            for(i=0;i<taille;i++)
            afficher_location(l[i]);
            }
    break;
    case 3:
        recherchelocation(l,taille);
        break;
    case 4:
        changer_information(l);
        break;
    case 5:
        do
        {
        printf("donner l'indice de la location à supprimer\n");
        }while(scanf("%d",&indice)!=1);
        taille=supprimerlocation(l,taille,indice);
        break;
    case 6:
        fp=fopen("Data.txt","wt");
        printf("la taille est %d\t",taille);
        for (i=0;i<=taille;i++)
        {
            fprintf(fp,"%s %d %d %d %d %d %d %d %f %s\n",l[i].nom,l[i].date_debut.day,l[i].date_debut.month,l[i].date_debut.year,l[i].date_fin.day,l[i].date_fin.month,l[i].date_fin.year,l[i].appartement.id,l[i].appartement.surface,l[i].appartement.description);
        }
        fclose(fp);
        exit(1);
    case 7:
        printf("taille est %d\n",taille);
        break;
    default:
        {
        printf("Entrer un choix valide\n");

        }

        }


}
return 0;
}
