#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVES 10
#define TAILLE_MAX 100

// Fonction pour initialiser le mot affiché avec des caractères de remplacement
void initialiserMotAffiche(const char* mot, char* motAffiche) {
    while (*mot) {
        if (isalpha(*mot)) {
            *motAffiche = '_';
        }
        else {
            *motAffiche = *mot;
        }
        mot++;
        motAffiche++;
    }
    *motAffiche = '\0'; // Ajouter le caractère nul de fin de chaîne
}

// Fonction pour afficher le mot actuel avec les lettres trouvées
void afficherMotAffiche(const char* motAffiche) {
    printf("Mot actuel : %s\n", motAffiche);
}

// Fonction pour mettre à jour le mot affiché avec la lettre trouvée
void mettreAJourMotAffiche(const char* mot, char lettre, char* motAffiche) {
    for (int i = 0; mot[i] != '\0'; i++) {
        if (toupper(mot[i]) == toupper(lettre)) {
            motAffiche[i] = mot[i];
        }
    }
}

// Fonction pour vérifier si le mot a été entièrement trouvé
int motTrouve(const char* motAffiche) {
    return strchr(motAffiche, '_') == NULL;
}

int main() {
    char mot[TAILLE_MAX];
    char motAffiche[TAILLE_MAX];
    char lettre;
    int tentativesRestantes = MAX_TENTATIVES;
    int lettreTrouvee;

    printf("Joueur 1, entrez le mot cache (ne pas afficher aux autres joueurs) : ");
    scanf("%s", mot);

    // Initialiser le mot affiché avec des underscores
    initialiserMotAffiche(mot, motAffiche);

    while (tentativesRestantes > 0) {
        afficherMotAffiche(motAffiche);

        printf("Joueur 2, entrez une lettre : ");
        scanf(" %c", &lettre); // Notez l'espace avant %c pour ignorer les espaces

        lettreTrouvee = 0;
        for (int i = 0; mot[i] != '\0'; i++) {
            if (toupper(mot[i]) == toupper(lettre)) {
                lettreTrouvee = 1;
                mettreAJourMotAffiche(mot, lettre, motAffiche);
            }
        }

        if (lettreTrouvee) {
            printf("Bonne lettre!\n");
        }
        else {
            tentativesRestantes--;
            printf("Mauvaise lettre! Tentatives restantes : %d\n", tentativesRestantes);
        }

        // Vérifier si le mot a été entièrement trouvé
        if (motTrouve(motAffiche)) {
            afficherMotAffiche(motAffiche);
            printf("Felicitations! Vous avez trouve le mot.\n");
            break;
        }
    }

    if (tentativesRestantes == 0) {
        printf("Dommage! Vous avez perdu. Le mot etait : %s\n", mot);
    }

    return 0;
}

