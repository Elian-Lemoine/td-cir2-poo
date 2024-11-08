#include <iostream>
#include <iomanip>

int main() {
    int number;

    // Demander à l'utilisateur de saisir un chiffre entre 1 et 9
    std::cout << "Entrez un chiffre entre 1 et 9 : ";
    std::cin >> number;

    // Vérifier que le nombre est valide
    if (number < 1 || number > 9) {
        std::cout << "Veuillez entrer un chiffre valide entre 1 et 9." << std::endl;
        return 1; // Sortir avec une erreur
    }

    // Afficher la table de multiplication
    std::cout << "Table de multiplication de " << number << " :" << std::endl;
    for (int i = 1; i <= 9; i++) {
        std::cout << number << " x " << i << " = " << std::setw(5) << number * i << std::endl;
    }

    return 0;
}
