//
//  numlines.h
//  ProjetDictionnaire
//
//  Created by Hadjer Bekhira on 12/12/2020.
//

#ifndef numlines_h
#define numlines_h


struct element {
    int  numero_ligne;
    struct element *suivant;
};
typedef struct element* element;


struct liste_numero_ligne {
  element premier;
  element dernier;
  int taille;
};
typedef struct liste_numero_ligne* liste_numero_ligne;


element creer_element(int num_ligne);
void free_element(element e);
liste_numero_ligne creer_liste(void);
int liste_est_vide(liste_numero_ligne l);
void liste_ajouter_fin(liste_numero_ligne l, element e);
element liste_extraire_fin(liste_numero_ligne l);
void liste_detruire(liste_numero_ligne l);

#endif /* numlines_h */
