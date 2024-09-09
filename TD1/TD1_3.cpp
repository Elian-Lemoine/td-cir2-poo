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
        printf("Erreur d'allocation m�moire.\n");
        return 1;
    }

    // Initialisation de la graine pour le g�n�rateur de nombres al�atoires
    srand(time(NULL));

    // Remplissage du tableau avec des valeurs al�atoires
    for (int i = 0; i < n; i++) {
        tableau[i] = rand() % 100; // Valeurs al�atoires entre 0 et 99
    }

    // Affichage des valeurs non tri�es
    printf("Tableau non trie :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Tri du tableau
    qsort(tableau, n, sizeof(int), comparer);

    // Affichage des valeurs tri�es
    printf("Tableau tri� :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Lib�ration de la m�moire allou�e
    free(tableau);

    return 0;
}
