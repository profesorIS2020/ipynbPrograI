#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <string>
#include <vector>

class LibraryCollection {
private:
    std::string collectionName;
    int totalBooks;
    std::vector<int> booksByCategory;
    const double MINIMUM_DIVERSITY_THRESHOLD;

public:
    // Constructor
    LibraryCollection(const std::string& name, int initialBooks);

    // M�todo para agregar libros por categor�a
    void addBooksByCategory(int books);

    // M�todo para calcular la diversidad de la colecci�n
    double calculateCategoryDiversityRatio() const;

    // M�todo para verificar si la colecci�n cumple con el umbral de diversidad
    bool meetsDiversityThreshold() const;

    // M�todo para encontrar la categor�a con m�s libros
    int findMostPopularCategoryIndex() const;

    // Getter para el nombre de la colecci�n
    std::string getCollectionName() const;
};

#endif // LIBRARY_MANAGEMENT_H
