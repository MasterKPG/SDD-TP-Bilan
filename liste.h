/* En-tete de liste
   ----------------
   objectif : définir le TAA liste */
   
#ifndef _Liste_h
#define _Liste_h

// définir le type T_liste (typedef ...)

typedef struct maillon
{
    int element;
    struct maillon * psuivant;
} T_Maillon;

typedef T_Maillon* T_liste;

    
// prototypes des méthodes

// creation liste vide
T_liste creer_liste();
// ajout en tete de liste de element avec modification de la liste
void ajout_entete_liste(T_liste *, int);
// ajout en tete selon une approche fonctionnelle sans modification de la liste
T_liste ajouter_entete_fonc(T_liste, int);

// affichages
// itératif
void afficher_liste(T_liste);
// récursif dans l ordre de la liste
void fafficher_dir_liste(T_liste);
// récursif dans l ordre inverse de la liste
void fafficher_inv_liste(T_liste);



// inversion iterative d'une liste selon une approche MIS
void inv_mis_liste(T_liste *);
// inversion iterative d'une liste selon une approche fonctionnelle
T_liste inv_fonc_liste(T_liste);

// comptage du nombre d'elements d'une liste
// selon une approche recursive enveloppee
int long_env(T_liste);
// selon une approche recursive terminale
int long_ter(T_liste, int);

// inversion recursive enveloppee d'une liste
T_liste inversion_rec_env(T_liste);
// inversion recursive terminale d'une liste
T_liste inversion_rec_term(T_liste, T_liste aux);

// liberation de la mémoire
void liberer_liste(T_liste *);
#endif
