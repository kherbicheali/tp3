#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{   liste *list;
    list=malloc(sizeof(liste));
    list->premier=NULL;
    list=lecture(list);
    afficher(list);
    //sauvegarder(list);
    //list=ajouter_en_tete(list, 235, 236);
    //list=supprimer(list);
    //printf("\nLa liste avec le premier element supprime :\n");
    //afficher(list);
    //rechercher(list);
    list=trier(list);
    sauvegarder(list);
    system("PAUSE");	
    return 0;
}
