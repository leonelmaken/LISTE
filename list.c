#include <stdio.h>
#include  <stdlib.h>
#include  "list.h"

List new_list(void)
{
    List liste = malloc(sizeof(*liste));
    liste->value = 0;
    liste->next = NULL;
    return liste;
}
Bool is_empty_list(List li)//vérifie si la liste est vide
{
    if(li == NULL)
        return true;
    return false;
}
int list_length(List li)//la taille de la liste
{
    int size = 0;

    if(!is_empty_list(li)){
        ListElement *actuel = li->next;
        while(actuel != NULL)
        {
            ++size;
            actuel = actuel->next;
        }
        return size;
    }else{
        return 0;
    }
}
void affiche_liste(List li)//permet d'afficher une list
{
    if(is_empty_list(li))
    {
        printf("Cette liste est vide.\n");
        return ;
    }
    ListElement *element = li->next;
    while(element != NULL)
    {
        printf("[%d] ",element ->value);
        element = element ->next;
    }
    printf("\n");
}
Bool rechercher_element(List li, int z)//permet de rechercher un element dans une list
{
    if(is_empty_list(li))
    {
        printf("Cette liste est vide.\n");
        return ;
    }
    int position = -1, compteur = 0;
    ListElement *element = li->next;
    while(element != NULL)
    {
        if (element ->value == z){
            position = compteur;
            break;
        }
        element = element ->next;
        compteur++;
    }
    if(position > -1)
    {
       // printf("Element trouve a la position %d", position);
       return 1;
    }
    else
    {
        //printf("Element non trouve");
        return 0;
    }
}
List ajoute_element_fin(List li,int x)
{
    ListElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr,"Erreur : probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element -> value = x;
    element -> next = NULL;
    if(is_empty_list(li))
        return element;
    ListElement *temp;
    temp = li;
    while(temp ->next != NULL)
        temp = temp->next;
    temp->next = element;
    return li;
}
void ajoute_debut(List li,int y)//ajoute un element dans une liste
{
    ListElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr,"Erreur : probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element -> value = y;
    element -> next = NULL;
    if(li->next == NULL)
        li->next = element;
    else{
        ListElement* first = li->next;
        element->next = first;
        li->next = element;
    }

}
/*List retirer_dernier(List li)
{
    if(is_empty_list(li))
        return new_list();
    if(li->next == NULL)
    {
        free(li);
        li = NULL;
        return new_list();
    }
    ListElement *temp = li;
    ListElement *before = li;
    while(temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }
    before ->next  = NULL;
    free(temp);
    temp = NULL;
    return li;
}*/
List retirer_devant(List li)
{
    if (is_empty_list(li))
    {
        return li;
    }
    ListElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr,"liste vide.\n");
        exit(EXIT_FAILURE);
    }
    element = li->next;
    free(li);
    li = NULL;
    return element;
}
List supprimer(List li , int x){
    if(li!=NULL){
        if(li->value == x)
            retirer_devant(li);
        ListElement *element = li, *precedent;
        while(element->next != NULL || element->value != x){
            precedent = element;
            element = element->next;
        }
        if(element->next!=NULL){
            precedent->next = NULL;
        }else{
            precedent->next = element->next;
        }
        free(element);
        return li;

    }
}

List ajout_deux_entiers(List li,int x,int y)
{
        ListElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr,"Erreur : probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element -> value = y;
    element -> next = NULL;
    if(li->next == NULL)
        li->next = element;
    else{
        ListElement* first = li->next;
        element->next = first;
        li->next = element;
    }
    element = malloc(sizeof(*element));
    element -> value = x;
    element -> next = NULL;
    if(li->next == NULL)
        li->next = element;
    else{
        ListElement* first = li->next;
        element->next = first;
        li->next = element;
    }
}
void n_element(int nbr)
{
    int element,i;
    List li;
        for(int i = 0;i < nbr; i++)
    {

        printf("element :\t");
        scanf("%d",&element);
        ajoute_debut(li,element);
    }
     affiche_liste(li);
}
void recherche_derniere_occurence(List li,int x)
{
     if(is_empty_list(li))
    {
        printf("Cette liste est vide.\n");
        return ;
    }
    int index = 0,i = 0;
    ListElement *element = li->next;
    while(element != NULL)
    {
        if (element ->value == x){

            index = i;
        }
        element = element ->next;
        i++;
    }
        printf("la derniere occurence est a la position: %d", index);
}
