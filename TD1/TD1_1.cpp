/* Premier programme en C */
#include<stdlib.h>
#include<stdio.h>

#include <math.h>

char minuscule(char d) {
    if (d >= 'A' && d <= 'Z') {
        return d + ('a' - 'A');
    }
    return d; // Si le caractère n'est pas une majuscule, on le retourne tel quel
}
unsigned long long factorial_for(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Calcul du facteurielle en utilisant une boucle 'while'
unsigned long long factorial_while(int n) {
    unsigned long long result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

// Calcul du facteurielle de manière récursive
unsigned long long factorial_recursive(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial_recursive(n - 1);
    }
}

int main(){

	printf("Hello World\n");
    char caractere = 'D';
    printf("Le caractere minuscule de %c est %c\n", caractere, minuscule(caractere));

    int n;
    printf("Entrez un nombre entier positif: ");
    scanf("%d", &n);
    // Vérifier que le nombre est positif
    if (n < 0) {
        printf("Le nombre doit être un entier positif.\n");
        return 1;
    }

    // Calculer et afficher le résultat en utilisant les trois méthodes
    printf("Calcul du facteurielle de %d:\n", n);
    printf("Utilisation de la boucle 'for': %llu\n", factorial_for(n));
    printf("Utilisation de la boucle 'while': %llu\n", factorial_while(n));
    printf("Utilisation de la récursion: %llu\n", factorial_recursive(n));


    float a, b, c, discriminant, racine1, racine2, racine_imaginaire;

    // Entrée des coefficients a, b et c
    printf("Entrez les coefficients a, b et c :\n");
    scanf("%f %f %f", &a, &b, &c);

    // Calcul du discriminant
    discriminant = b * b - 4 * a * c;

    // Vérification du type de racines en fonction du discriminant
    if (discriminant > 0) {
        // Deux racines réelles distinctes
        racine1 = (-b + sqrt(discriminant)) / (2 * a);
        racine2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Les racines sont reelles et distinctes:\n");
        printf("Racine 1 = %.2f\n", racine1);
        printf("Racine 2 = %.2f\n", racine2);
    }
    else if (discriminant == 0) {
        // Une racine réelle double
        racine1 = -b / (2 * a);
        printf("Les racines sont reelles et identiques:\n");
        printf("Racine double = %.2f\n", racine1);
    }   
    else {
        // Racines complexes
        racine1 = -b / (2 * a);
        racine_imaginaire = sqrt(-discriminant) / (2 * a);
        printf("Les racines sont complexes et conjuguees:\n");
        printf("Racine 1 = %.2f + %.2fi\n", racine1, racine_imaginaire);
        printf("Racine 2 = %.2f - %.2fi\n", racine1, racine_imaginaire);
    }


    return EXIT_SUCCESS;
}

