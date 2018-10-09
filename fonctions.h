struct element_t{float x; float y; struct element_t* suivant;};
typedef struct element_t element;

struct liste_t{element* premier;};
typedef struct liste_t liste;
//Va pointer sur le premier element de la liste

liste* lecture(liste *list);
liste* ajouter_en_tete(liste *list, float v1, float v2);
liste* insertion(liste *list, element* courant, float v1, float v2);
liste* supprimer(liste *list);
liste* trier(liste *list);
void afficher(liste *list);
void sauvegarder(liste *list);
void rechercher(liste *list);
