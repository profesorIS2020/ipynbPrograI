#include <iostream>
#include <iomanip>
#include "library_management.h"

/*g++ -std=c++11 q1.cpp main.cpp -o electoral_analysis */
int main() {
    try {
        // Crear colecciones de bibliotecas
        LibraryCollection biblioteca1("Biblioteca Central", 5000);
        LibraryCollection biblioteca2("Biblioteca Universitaria", 7500);
        LibraryCollection biblioteca3("Biblioteca Municipal", 3000);

        // Agregar libros por categor�a en cada biblioteca
        biblioteca1.addBooksByCategory(1000);  // Ciencia
        biblioteca1.addBooksByCategory(1500);  // Literatura
        biblioteca1.addBooksByCategory(750);   // Historia

        biblioteca2.addBooksByCategory(2000);  // Ciencia
        biblioteca2.addBooksByCategory(2500);  // Literatura
        biblioteca2.addBooksByCategory(1000);  // Historia

        biblioteca3.addBooksByCategory(600);   // Ciencia
        biblioteca3.addBooksByCategory(1200);  // Literatura
        biblioteca3.addBooksByCategory(300);   // Historia

        // Arreglo de bibliotecas para procesamiento
        LibraryCollection bibliotecas[] = {biblioteca1, biblioteca2, biblioteca3};

        // An�lisis de resultados
        std::cout << "An�lisis de Colecciones de Bibliotecas\n";
        std::cout << "======================================\n";

        for (const auto& biblioteca : bibliotecas) {
            std::cout << "Biblioteca: " << biblioteca.getCollectionName() << std::endl;
            
            // Calcular y mostrar ratio de diversidad
            double diversityRatio = biblioteca.calculateCategoryDiversityRatio();
            std::cout << "Ratio de Diversidad: " 
                      << std::fixed << std::setprecision(2) 
                      << (diversityRatio * 100) << "%" << std::endl;

            // Verificar umbral de diversidad
            std::cout << "Cumple Umbral de Diversidad: " 
                      << (biblioteca.meetsDiversityThreshold() ? "S�" : "No") << std::endl;

            // Encontrar categor�a m�s popular
            int mostPopularIndex = biblioteca.findMostPopularCategoryIndex();
            std::cout << "Categor�a M�s Popular (�ndice): " << mostPopularIndex << std::endl;
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
