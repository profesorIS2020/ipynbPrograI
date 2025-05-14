#ifndef Q2_H
#define Q2_H

#include <string>
#include <array>
#include <stdexcept>

// Enumeraci¢n para las categor¡as de productos
enum class Categoria {
    ELECTRONICA,
    ROPA,
    ALIMENTOS,
    HOGAR,
    OTRO
};

// Estructura que representa un producto
struct Producto {
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    Categoria categoria;
    
    // Constructor con valores por defecto
    Producto(int _id = 0, std::string _nombre = "", double _precio = 0.0, 
             int _cantidad = 0, Categoria _categoria = Categoria::OTRO)
        : id(_id), nombre(_nombre), precio(_precio), 
          cantidad(_cantidad), categoria(_categoria) {}
};

// Excepci¢n personalizada para errores del inventario
class InventarioException : public std::runtime_error {
public:
    InventarioException(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

// Clase principal para gestionar el inventario
class Inventario {
private:
    static const int MAX_PRODUCTOS = 200;
    std::array<Producto, MAX_PRODUCTOS> productos;
    int numProductos;
    
public:
    // Constructor
    Inventario();
    
    // M‚todos para gestionar el inventario
    void agregarProducto(const Producto& producto);
    void actualizarCantidad(int id, int nuevaCantidad);
    void actualizarPrecio(int id, double nuevoPrecio);
    void eliminarProducto(int id);
    Producto buscarPorId(int id) const;
    void mostrarInventario() const;
    void mostrarPorCategoria(Categoria cat) const;
    double calcularValorTotal() const;
    
    // M‚todo para convertir Categoria a string
    static std::string categoriaToString(Categoria cat);
};

#endif // Q2_H
