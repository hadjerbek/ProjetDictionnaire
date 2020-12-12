//
//  main.c
//  ProjetDictionnaire
//
//  Created by Hadjer Bekhira on 04/12/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "tableaux_LT.h"
#include <unistd.h>


void affiche_LT(tab_LT tab_lt )
{
    int i;
    for (i=0; i< tab_lt->taille_T; i++)
    {
        printf("%c",tab_lt->T[i]);
    }
    printf("\n\n");
    for (i=1; i<=tab_lt->taille_L;i++)
    {
        printf("%d %c\n", tab_lt->L[i], tab_lt->T[tab_lt->L[i]]);
    }
    
}



/**
 * cette fonction compte le nombre de caratectre du fichier
 *  @arg file : le fichier a compter le nombre de caractrere
 *  @return le nombre de caractere en octet
 */
long long count_file_size(char* file)
{
    FILE *F;
    
    long long la_taille;
    F = fopen(file,"r");
    if(F) {
        // On se place à la fin du fichier
        fseek (F, 0, SEEK_END);
        // On récupère le décalage par rapport au début
        la_taille = ftell (F);
        fclose (F);
        return la_taille;
    }
        
    return -1; // S'il y a erreur
}

/**
 cette fonction compte le nombre de lignes du fichier
 */
int count_number_lines(char* file)
{
    FILE *F;
    F=fopen(file, "r");
    int l=0;
    char c;
    if (F)
    {
        c = fgetc(F);
        while(c != EOF) {
            if(c == '\n') l++;
            c = fgetc(F);
        }
        return l;
        
    }
    return -1; // S'il y a erreur
}



/**
 * Cette fonction lot le texte dans le fichier d’entrée et le stocke dans un tableau T faisant exactement la taille du fichier
 * Elle construit aussi un tableau d’entier L, tel que L[i] contienne la position du premier caractère de la ième ligne dans T.
 * @param file : le fichier a  convertir
 * @return : une structure qui contient les tableaux T & L
 */
tab_LT file_to_tab(char* file)
{
    // creation d'un tableau de taille taille du fichier
    tab_LT lt = malloc(sizeof(struct tableaux_LT));
    lt->taille_T = count_file_size( file);
    lt->taille_L = count_number_lines(file);
    if(lt->taille_T <0 || lt->taille_L < 0) {
        printf("Erreur lors de la lecture du fichier %s\n", file);
        exit(1);
    }

    lt->T = (char*)malloc(sizeof(char)*lt->taille_T);
    // creation d'un tableau de taille nombre de lignes du fichier
    lt->L = (int*)malloc(sizeof(int)*lt->taille_L);
    
    // Lecture du fichier
    FILE *F;
    F=fopen(file, "r");
    int c; // Compteur des chars du fichier
    lt->L[1] = 0;   // Nous avons opté de commencer par 1 dans les indices de L car
                  // la numérotation des lignes commence à 1
    int l = 2; // Compteur des lignes du fichier
    int nwline = 0;
    for (c=0; c<lt->taille_T; c++ /* :) */)
    {
        lt->T[c] = fgetc(F);
        if(nwline)
        {
            // on stock l'indice du premier carectere de la ligne qui est le ccarectere actuel
            // dans L
            lt->L[l]=c;
            // on incremete l'indice de l 
            l++;
        }
        // nouvelle ligne
        if(lt->T[c] == '\n') nwline = 1;
        else nwline = 0;
    }
    
    return lt;
}


int main(int argc, char* argv[])
{
    tab_LT lt = file_to_tab("test_files/pg31469.txt");
    affiche_LT(lt);
}
