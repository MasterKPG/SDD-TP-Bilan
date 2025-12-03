/* ==================================== Include    =================================== */
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

/* ==================================== Functions and procedures =================================== */

T_liste creer_liste(void){
    return NULL;
}

void ajout_entete_liste(T_liste *pliste, int element){
    T_Maillon *nouveau = malloc(sizeof(T_Maillon));
    nouveau->element = element;
    nouveau->psuivant = *pliste;
    
    *pliste = nouveau;
    
}

T_liste ajouter_entete_fonc(T_liste liste, int element){
    T_Maillon *nouveau = malloc(sizeof(T_Maillon));
    nouveau->element = element;
    nouveau->psuivant = liste;

    return nouveau;
}

void afficher_liste(T_liste liste){
    T_Maillon *actuel;
    if (liste == NULL){
        printf("La liste est vide.\n");
    }
    actuel = liste;
    do{
        printf("%d\n", actuel->element);
        actuel = actuel->psuivant;
        if (actuel->psuivant == NULL){
            printf("%d\n",actuel->element);
            printf("L'affichage est terminé\n");
        }
    } while (actuel->psuivant != NULL);

}

void fafficher_dir_liste(T_liste liste){
    if (liste == NULL){
        printf("L'affichage est terminé\n");
    } else {
        printf("%d\n", liste->element);
        fafficher_dir_liste(liste->psuivant);
    }

}

void fafficher_inv_liste(T_liste liste){
    if (liste == NULL){
        printf("Affichage de la liste inversée:\n");
    } else {
        fafficher_inv_liste(liste->psuivant);
        printf("%d\n", liste->element);
    }
}

void inv_mis_liste(T_liste *pliste){
    T_Maillon *prec = NULL;
    T_Maillon *actu = *pliste;
    T_Maillon *suiv;
    while (actu != NULL){
        suiv = actu->psuivant;
        actu->psuivant = prec;
        prec = actu;
        actu = suiv;
    }
    *pliste = prec;
    printf("L'inversion est terminée\n");
}

T_liste inv_fonc_liste(T_liste liste){
    T_Maillon *prec = NULL;
    T_Maillon *actu = liste;
    T_Maillon *suiv;
    while (actu != NULL){
        suiv = actu->psuivant;
        actu->psuivant = prec;
        prec = actu;
        actu = suiv;
    }
    return prec;
}

int long_env(T_liste liste){
    if (liste == NULL){
        return 0;
    } else {
        return (long_env(liste->psuivant) + 1);
    }
}

int long_ter(T_liste liste, int aux){
    if (liste == NULL){
        return aux;
    } else {
        return (long_ter(liste->psuivant, aux + 1));
    }
}

T_liste inversion_rec_env(T_liste liste){
    if (liste == NULL || liste->psuivant == NULL){
        return liste;
    }
    
    T_liste nouvelle_tete = inversion_rec_env(liste->psuivant);

    liste->psuivant->psuivant = liste;
    liste->psuivant = NULL;
    
    return nouvelle_tete;
}

T_liste inversion_rec_term(T_liste liste, T_liste acc){
    if (liste == NULL){
        return acc;
    }
    T_liste suivant = liste->psuivant;
    liste->psuivant = acc;
    return inversion_rec_term(suivant, liste);
}

void liberer_liste(T_liste *pliste){
    T_Maillon *actuel = *pliste;
    T_Maillon *suivant;
    
    while (actuel != NULL){
        suivant = actuel->psuivant;
        free(actuel);
        actuel = suivant;
    }
    *pliste = NULL;
    printf("Mémoire libérée\n");
}

int main(void){
    T_liste liste = creer_liste();

    ajout_entete_liste(&liste, 5);
    ajout_entete_liste(&liste, 4);
    ajout_entete_liste(&liste, 3);
    ajout_entete_liste(&liste, 2);
    ajout_entete_liste(&liste, 1);

    printf("Affichage de la liste en utilisant afficher_liste\n");
    afficher_liste(liste);

    printf("Affichage de la liste en utilisant fafficher_dir_liste\n");
    fafficher_dir_liste(liste);

    printf("Affichage inverse de la liste en utilisant fafficher_inv_liste\n");
    fafficher_inv_liste(liste);

    printf("Inversion de la liste\n");
    inv_mis_liste(&liste);
    printf("Affichage de la liste inversée\n");
    afficher_liste(liste);

    printf("Affichage de la liste inversée en utilisant T_liste inv_fonc_liste\n");
    liste = inv_fonc_liste(liste);
    afficher_liste(liste);

    printf("Longueur de la liste en utilisant long_env : %d\n",long_env(liste));

    printf("Longueur de la liste en utilisant long_ter : %d\n",long_ter(liste,0));

    printf("Test inversion récursive enveloppée\n");
    liste = inversion_rec_env(liste);
    afficher_liste(liste);

    printf("Test inversion récursive terminale\n");
    liste = inversion_rec_term(liste, NULL);
    afficher_liste(liste);

    printf("Libération de la mémoire\n");
    liberer_liste(&liste);
    
    return EXIT_SUCCESS;
}