#include "library_management.h"
#include <stdexcept>
#include <algorithm>

// Constructor
LibraryCollection::LibraryCollection(const std::string& name, int initialBooks) 
    : collectionName(name), 
      totalBooks(initialBooks), 
      MINIMUM_DIVERSITY_THRESHOLD(0.3) {
    if (totalBooks < 0) {
        throw std::invalid_argument("El n�mero de libros no puede ser negativo");
    }
}

// M�todo para agregar libros por categor�a
void LibraryCollection::addBooksByCategory(int books) {
    if (books < 0) {
        throw std::invalid_argument("El n�mero de libros no puede ser negativo");
    }
    booksByCategory.push_back(books);
}

// M�todo para calcular la diversidad de la colecci�n
double LibraryCollection::calculateCategoryDiversityRatio() const {
    int totalCategoryBooks = 0;
    for (int books : booksByCategory) {
        totalCategoryBooks += books;
    }
    return static_cast<double>(booksByCategory.size()) / totalCategoryBooks;
}

// M�todo para verificar si la colecci�n cumple con el umbral de diversidad
bool LibraryCollection::meetsDiversityThreshold() const {
    return calculateCategoryDiversityRatio() >= MINIMUM_DIVERSITY_THRESHOLD;
}

// M�todo para encontrar la categor�a con m�s libros
int LibraryCollection::findMostPopularCategoryIndex() const {
    if (booksByCategory.empty()) {
        throw std::runtime_error("No hay categor�as registradas");
    }

    return std::max_element(booksByCategory.begin(), booksByCategory.end()) - booksByCategory.begin();
}

// Getter para el nombre de la colecci�n
std::string LibraryCollection::getCollectionName() const {
    return collectionName;
}
