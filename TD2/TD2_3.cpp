#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

int main() {
    std::ifstream file("texte.txt"); // Assurez-vous que ce fichier existe
    if (!file) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    std::string line;
    int lineCount = 0;
    int wordCount = 0;
    int letterCount = 0;

    while (std::getline(file, line)) {
        lineCount++; // Compter les lignes

        // Utiliser stringstream pour analyser les mots
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            wordCount++; // Compter les mots
            letterCount += word.size(); // Compter les lettres dans le mot
        }
    }

    file.close(); // Fermer le fichier

    std::cout << "Nombre de lignes : " << lineCount << std::endl;
    std::cout << "Nombre de mots : " << wordCount << std::endl;
    std::cout << "Nombre de lettres : " << letterCount << std::endl;

    return 0;
}
