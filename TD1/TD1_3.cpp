#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction de comparaison pour qsort
int comparer(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    // Allocation dynamique du tableau
    int* tableau = (int*)malloc(n * sizeof(int));
    if (tableau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    // Initialisation de la graine pour le générateur de nombres aléatoires
    srand(time(NULL));

    // Remplissage du tableau avec des valeurs aléatoires
    for (int i = 0; i < n; i++) {
        tableau[i] = rand() % 100; // Valeurs aléatoires entre 0 et 99
    }

    // Affichage des valeurs non triées
    printf("Tableau non trie :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Tri du tableau
    qsort(tableau, n, sizeof(int), comparer);

    // Affichage des valeurs triées
    printf("Tableau trié :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Libération de la mémoire allouée
    free(tableau);

    return 0;
}
