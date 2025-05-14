#ifndef Q2_H
#define Q2_H

#include <string>
#include <stdexcept>
#include <array>

// Definici¢n de una estructura para representar un libro
struct Libro {
    int id;
    std::string titulo;
    std::string autor;
    bool disponible;
    
    // Constructor con valores por defecto
    Libro(int _id = 0, std::string _titulo = "", std::string _autor = "", bool _disponible = true)
        : id(_id), titulo(_titulo), autor(_autor), disponible(_disponible) {}
};

// Excepci¢n personalizada para errores de la biblioteca
class BibliotecaException : public std::runtime_error {
public:
    BibliotecaException(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

// Clase principal para gestionar la biblioteca
class Biblioteca {
private:
    static const int MAX_LIBROS = 100;
    std::array<Libro, MAX_LIBROS> catalogo;
    int numLibros;
    
public:
    // Constructor
    Biblioteca();
    
    // M‚todos para gestionar la biblioteca
    void agregarLibro(const Libro& libro);
    void prestarLibro(int id);
    void devolverLibro(int id);
    Libro buscarPorId(int id) const;
    void mostrarCatalogo() const;
    int contarDisponibles() const;
};

#endif // Q2_H
