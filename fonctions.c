#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

liste* lecture(liste *list)
{   FILE* fichier;
    int i=0;
    float x,y;
    element *e;
    fichier=fopen("data.txt","r");
    if(fichier==NULL)
    {    printf("Fichier vide\n");
         exit(1);
    }
    if(list==NULL)
    {    printf("Liste vide\n");
         exit(1);
    }
    while(fscanf(fichier,"%f %f\n",&x,&y)!=EOF)
    {    e=malloc(sizeof(element));
         e->x=x;
         e->y=y;
         e->suivant=NULL;
         if(list->premier==NULL)
         {    list->premier=e;}
         else
         {   e->suivant=list->premier;
             list->premier=e;
         }
    }     
    fclose(fichier);
    return list;
}

liste* ajouter_en_tete(liste *list, float v1, float v2)
{   element* nouveau=(element*)malloc(sizeof(element));
    nouveau->x=v1;
    nouveau->y=v2;
    nouveau->suivant=list->premier;
    list->premier=nouveau;
    return list;
}

liste* insertion(liste *list, element* courant, float v1, float v2)
{      element* nouveau=(element*)malloc(sizeof(element));
       nouveau->x=v1;
       nouveau->y=v2;
       nouveau->suivant=courant->suivant;
       courant->suivant=nouveau;
       return list;
}

void afficher(liste *list)
{     element *p=list->premier;
      printf("\nAffichage de la liste\n");
      while(p!=NULL)
      {    printf("%3.1f %3.1f\n",p->x,p->y);
           p=p->suivant;
      }
}

void sauvegarder(liste *list)
{   FILE* fichier;
    element *p=list->premier;
    fichier=fopen("sauvegarde_liste.txt","w");
    while(p!=NULL)
    {     fprintf(fichier,"%f %f\n",p->x,p->y);
          p=p->suivant;
    }
    fclose(fichier);
}

liste* supprimer(liste *list)
// Supprime le premier element de la liste
{    element *p=list->premier;
     p=p->suivant;
     free(list->premier);     
     list->premier=p;
     return list;
}

liste* trier(liste *list)
// Trie par selection, ordre croissant sur les x
{      liste* list_triee;
       list_triee=malloc(sizeof(liste));
       list_triee->premier=NULL;
       // Creation d'une nouvelle liste qui va correspondre à la list triée
       element *p=list->premier;
       float minimum=p->x;
       list_triee=ajouter_en_tete(list_triee,p->x,p->y);
       element *courant=list_triee->premier;
       element *nouveau=malloc(sizeof(element));
       element *nouveau2=malloc(sizeof(element));
       p=p->suivant;
       while(p!=NULL)
       {    if((p->x)<=minimum)
            // L'element de la liste est inferieur au minimum
            // On le place en tete de la liste triee
            {    minimum=p->x;
                 list_triee=ajouter_en_tete(list_triee,p->x,p->y);
            }
            else if(courant->suivant==NULL)
            // L'element de la liste est superieur au minimum
            // Le prochain élément est la fin de la liste
            // On le place juste avant la fin
            {      nouveau->x=p->x;
                   nouveau->y=p->y;
                   nouveau->suivant=NULL;
                   courant->suivant=nouveau;
            }
            else
            // L'element de la liste est superieur au minimum
            // On le place juste avant celui qui lui est supérieur
            {   while( (courant->suivant->x) < (p->x) )
                {     courant=courant->suivant;
                }
                list_triee=insertion(list_triee,courant,p->x,p->y);
            }
            courant=list_triee->premier;
            p=p->suivant;
       }
       printf("\nVoici la liste triee sur les x:\n");
       afficher(list_triee);
       return list_triee;
}

void rechercher(liste *list)
//Demande l'élement à rechercher parmi x ou y, indique s'il est présent ou non
{        int choix,i=0;
         float rch;
         element *p=list->premier;
         printf("Rechercher un x (tapez 0) ou un y (tapez 1) :\n");
         scanf("%d",&choix);
         switch(choix)
         {    case 0 : printf("Quel element ?\n");
                       scanf("%f",&rch);
                       while(p!=NULL)
                       {    if(p->x==rch)
                            {   i+=1;
                            }
                            p=p->suivant; 
                       } 
                       if(i>0)
                            printf("Votre element apparait dans la liste\n");
                       else 
                            printf("Votre element n'apparait pas dans la liste\n");
                       break;            
                       
              case 1 : printf("Quel element ?\n");
                       scanf("%f",&rch);
                       while(p!=NULL)
                       {    if(p->y==rch)
                            {   i+=1;
                            }
                            p=p->suivant;
                       }  
                       if(i>0)
                              printf("Votre element apparait dans la liste\n");
                       else 
                            printf("Votre element n'apparait pas dans la liste\n");
                       break;               
         }
}
