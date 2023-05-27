#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    printf("Hello world!\n");
    List malist = new_list();
    int x,y,a;
    int nbr, element;
    printf("ajoute des elements dans une liste.\n");
    printf("entrer le nombre d'elements:\t");
    scanf("%d",&nbr);
        for(int i = 0;i < nbr; i++)
    {

        printf("element :\t");
        scanf("%d",&element);
        ajoute_debut(malist,element);
    }
     affiche_liste(malist);
     malist = supprimer(malist, 5);
     affiche_liste(malist);
         printf("3-creer une liste de n elements differnets -1\n");
         printf("\n nombre d'elements.\n");
         scanf("%d",&nbr);
        for(int i = 0;i < nbr; i++)
    {

        printf("element :\t");
        scanf("%d",&element);
        if(element!=-1)
        {
                 ajoute_debut(malist,element);
        }
        else
        {
            break;
        }
    }
    affiche_liste(malist);
     printf("entrer l'element a rechercher :\t");
     scanf("%d",&a);
     if(rechercher_element(malist, a)== 1)
     {
         printf("%d est bien dans cette liste",a);
     }
    else
    {
        printf("%d n'appartient pas a cette liste",a);
    }
    printf("\nentrer deux entiers:\n");
    scanf("%d",&x);
    scanf("%d",&y);
    malist = ajout_deux_entiers(malist,x,y);
    affiche_liste(malist);
    printf("entrer un element:\t");
    scanf("%d",&a);
    recherche_derniere_occurence(malist,a);

}
