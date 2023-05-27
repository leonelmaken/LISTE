#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
/*Définition du type Booleen */
typedef enum
{
    false,
    true
}Bool;

/*Définition d'une Liste */
typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *List,*element;
/*prototypes */
List new_list(void);
Bool is_empty_list(List li);//vérifie si la liste est vide
int list_length(List li);//remplie une liste
void affiche_liste(List li);//permet d'afficher une liste
Bool rechercher_element(List li, int z);
List ajout_deux_entiers(List li,int x,int y);
void recherche_derniere_occurence(List li,int x);
 element * supprimer_premier_occurence(element *head,int index);
//List ajoute_element_fin(List li,int x);//ajoute un élément en fin de liste
void ajoute_debut(List li,int y);//ajoiute un element en debut de liste
List retirer_dernier(List li);//retier le dernier element de la liste
List supprimer(List li , int x);//retier le dernier element de la liste
//List retirer_devant(List li);//retirer le premier element d'une liste
#endif // LIST_H_INCLUDED
