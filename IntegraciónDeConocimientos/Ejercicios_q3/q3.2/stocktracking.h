// Inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <functional>
#include <map>

// Declaración anticipada
class Producto;

// Clase para las excepciones personalizadas
class InventarioException : public std::runtime_error {
public:
    explicit InventarioException(const std::string& mensaje);
};

// Clase para productos del inventario
class Producto {
private:
    int id;
    std::string nombre;
    double precio;
    int stock;
    
public:
    // Constructores
    Producto(int id, const std::string& nombre, double precio, int stock);
    Producto(const Producto& otro);
    
    // Destructor virtual (buena práctica para clases base)
    virtual ~Producto();
    
    // Getters y setters
    int getId() const;
    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;
    
    void setNombre(const std::string& nuevoNombre);
    void setPrecio(double nuevoPrecio);
    void setStock(int nuevoStock);
    
    // Métodos simples
    virtual void mostrar() const;
    virtual bool hayStock() const;
    
    // Métodos intermedios
    virtual void actualizarStock(int cantidad);
    virtual double calcularValorTotal() const;
};

// Clase derivada para productos perecederos
class ProductoPerecedero : public Producto {
private:
    std::string fechaCaducidad;
    
public:
    // Constructor
    ProductoPerecedero(int id, const std::string& nombre, double precio, int stock, const std::string& fechaCaducidad);
    
    // Getter y setter
    std::string getFechaCaducidad() const;
    void setFechaCaducidad(const std::string& nuevaFecha);
    
    // Métodos sobrescritos
    void mostrar() const override;
    double calcularValorTotal() const override;
};

// Enumeración para tipo de ordenamiento
enum class OrdenInventario {
    POR_ID,
    POR_NOMBRE,
    POR_PRECIO_ASC,
    POR_PRECIO_DESC,
    POR_STOCK
};

// Clase principal para gestionar el inventario
class Inventario {
private:
    std::vector<std::unique_ptr<Producto>> productos;  // Vector de punteros inteligentes a productos
    
public:
    // Constructor y destructor
    Inventario();
    ~Inventario();
    
    // Métodos simples
    int contarProductos() const;
    void mostrarInventario() const;
    
    // Métodos intermedios
    void agregarProducto(Producto* producto);  // Toma propiedad del puntero
    void eliminarProducto(int id);
    Producto* buscarProducto(int id);  // Devuelve un puntero sin transferir propiedad
    const Producto* buscarProducto(int id) const;  // Versión constante
    
    // Métodos avanzados
    double calcularValorInventario() const;
    void actualizarStockMultiple(const std::vector<std::pair<int, int>>& actualizaciones);
    void ordenarInventario(OrdenInventario tipo);
    
    // Métodos complejos
    std::vector<Producto*> filtrarProductosBajosStock(int umbral) const;
    std::pair<const Producto*, const Producto*> encontrarProductosMayorMenorPrecio() const;
    std::map<std::string, double> generarInformePorCategoria(const std::function<std::string(const Producto*)>& categorizador) const;
};

#endif // INVENTARIO_H