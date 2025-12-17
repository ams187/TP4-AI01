/*
 * tp4.h
 * Déclarations des structures et prototypes pour l'indexation de texte par ABR.
 */

#ifndef TP4_H
#define TP4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* --- Structures de données --- */

// Structure représentant une position unique d'un mot
typedef struct Position {
    int numeroLigne;
    int ordre;
    int numeroPhrase;
    struct Position* suivant;
} T_Position;

// Structure représentant un nœud de l'ABR
typedef struct Noeud {
    char* mot;
    int nbOccurences;
    T_Position* listePositions;
    struct Noeud* filsGauche;
    struct Noeud* filsDroit;
} T_Noeud;

// Structure représentant l'Index global
typedef struct Index {
    T_Noeud* racine;
    int nbMotsDistincts;
    int nbMotsTotal;
} T_Index;

/* --- Prototypes des fonctions --- */

// Gestion des positions
T_Position* ajouterPosition(T_Position* listeP, int ligne, int ordre, int phrase);

// Gestion de l'ABR
int ajouterOccurence(T_Index* index, char* mot, int ligne, int ordre, int phrase);

// Indexation du fichier
int indexerFichier(T_Index* index, char* filename);

// Affichage de l'index
void afficherIndex(T_Index index);

// Recherche
T_Noeud* rechercherMot(T_Index index, char* mot);

// Affichage des occurrences d'un mot (OPTIMISÉ)
void afficherOccurencesMot(T_Index index, char* mot);

// Reconstruction du texte
void construireTexte(T_Index index, char* filename);

// Gestion mémoire
void libererIndex(T_Index* index);

#endif
