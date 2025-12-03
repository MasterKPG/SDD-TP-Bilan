# SDD-TP-Bilan

Ce projet est un travail pratique (TP) sur les **Structures de Données Dynamiques** (SDD) en langage C. Il implémente une liste chaînée avec diverses opérations fondamentales.

## 📋 Description

Ce programme démontre l'implémentation d'une liste chaînée simple en C avec plusieurs méthodes pour manipuler et afficher les éléments. Il illustre différentes approches de programmation :
- Programmation impérative avec modification en place (MIS)
- Programmation fonctionnelle sans modification
- Approches récursives (enveloppée et terminale)

## 🗂️ Structure du projet

```
.
├── liste.h       # Fichier d'en-tête avec les définitions de types et prototypes
├── liste.c       # Implémentation des fonctions et programme principal
└── README.md     # Ce fichier
```

## 🔧 Fonctionnalités implémentées

### Création et ajout
- `creer_liste()` - Créer une liste vide
- `ajout_entete_liste()` - Ajouter un élément en tête (approche MIS)
- `ajouter_entete_fonc()` - Ajouter un élément en tête (approche fonctionnelle)

### Affichage
- `afficher_liste()` - Affichage itératif
- `fafficher_dir_liste()` - Affichage récursif dans l'ordre
- `fafficher_inv_liste()` - Affichage récursif dans l'ordre inverse

### Inversion
- `inv_mis_liste()` - Inversion itérative (approche MIS)
- `inv_fonc_liste()` - Inversion itérative (approche fonctionnelle)
- `inversion_rec_env()` - Inversion récursive enveloppée
- `inversion_rec_term()` - Inversion récursive terminale

### Utilitaires
- `long_env()` - Calcul de longueur (récursion enveloppée)
- `long_ter()` - Calcul de longueur (récursion terminale)
- `liberer_liste()` - Libération de la mémoire

## 🚀 Compilation et exécution

### Compilation

Avec GCC :
```bash
gcc -Wall -Wextra -o liste liste.c
```

Avec des options de débogage :
```bash
gcc -Wall -Wextra -g -o liste liste.c
```

Ou avec MinGW sous Windows :
```bash
gcc -Wall -Wextra -o liste.exe liste.c
```

### Exécution

Sous Linux/macOS :
```bash
./liste
```

Sous Windows :
```bash
liste.exe
```

## 📝 Exemple de sortie

Le programme principal crée une liste avec les valeurs 1, 2, 3, 4, 5 et démontre toutes les opérations disponibles :
- Affichage de la liste
- Inversion de la liste (plusieurs méthodes)
- Calcul de la longueur
- Libération de la mémoire

## 🎓 Concepts pédagogiques

Ce projet illustre :
- La gestion dynamique de la mémoire en C (`malloc`, `free`)
- Les pointeurs et structures
- Les listes chaînées
- La récursivité (enveloppée vs terminale)
- Différentes approches de programmation (impérative vs fonctionnelle)

## 📚 Prérequis

- Compilateur C (GCC, Clang, MinGW, etc.) compatible C99 ou supérieur
- Connaissance de base en C
- Compréhension des pointeurs et de l'allocation dynamique

## 🔍 Notes techniques

- Le type `T_liste` est un pointeur vers un `T_Maillon`
- Chaque maillon contient un entier et un pointeur vers le maillon suivant
- La liste vide est représentée par `NULL`
- La mémoire doit être libérée explicitement pour éviter les fuites mémoires

## 📄 Licence

Ce projet est un travail pratique à but éducatif.
