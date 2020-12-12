//
//  numlines.c
//  ProjetDictionnaire
//
//  Created by Hadjer Bekhira on 12/12/2020.
//

#include <stdlib.h>
#
#include "numlines.h"

element creer_element(int num_ligne){
    element res = (element)malloc(sizeof(element));
    res->numero_ligne = num_ligne;
    res->suivant = NULL;
    return res;
}

void free_element(element e){
    free(e);
}

liste_numero_ligne creer_liste(void)
{
    liste_numero_ligne liste = (liste_numero_ligne)malloc(sizeof(liste));
    liste->premier = NULL;
    liste->dernier = NULL;
    liste->taille = 0;
    return liste;
}


int liste_est_vide(liste_numero_ligne l){
    return l->taille == 0;
}

void liste_ajouter_fin(liste_numero_ligne l, element e){
    // Cas de la liste vide
    if (liste_est_vide(l)) {
        l->premier=e;
        l->dernier=e;
    }
    else
    {
        // Cas général
        l->dernier->suivant=e;
        // Déplacer l->dernier, pour qu'il pointe
        // sur le  nouveau dernier élément de la liste
        l->dernier=e;
    }
}
   

element liste_extraire_fin(liste_numero_ligne l){
    // a compelter 
    return NULL;
}

void liste_detruire(liste_numero_ligne l){
    element e = l->premier;
    element suiv = l->premier;
    while (e!=NULL)
    {
        suiv = e->suivant;
        free_element(e);
        e = suiv;
    }
}
