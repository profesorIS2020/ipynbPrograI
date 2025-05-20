// Inventario.cpp
#include "stocktracking.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <sstream>

// Implementación de InventarioException
InventarioException::InventarioException(const std::string& mensaje) 
    : std::runtime_error(mensaje) {
}

// Implementación de Producto
Producto::Producto(int id, const std::string& nombre, double precio, int stock)
    : id(id), nombre(nombre), precio(precio), stock(stock) {
    
    if (id <= 0) {
        throw InventarioException("El ID del producto debe ser un valor positivo");
    }
    
    if (nombre.empty()) {
        throw InventarioException("El nombre del producto no puede estar vacío");
    }
    
    if (precio < 0) {
        throw InventarioException("El precio del producto no puede ser negativo");
    }
    
    if (stock < 0) {
        throw InventarioException("El stock del producto no puede ser negativo");
    }
}

Producto::Producto(const Producto& otro)
    : id(otro.id), nombre(otro.nombre), precio(otro.precio), stock(otro.stock) {
}

Producto::~Producto() {
    // No hay recursos que liberar en esta clase base
}

int Producto::getId() const {
    return id;
}

std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

int Producto::getStock() const {
    return stock;
}

void Producto::setNombre(const std::string& nuevoNombre) {
    if (nuevoNombre.empty()) {
        throw InventarioException("El nombre del producto no puede estar vacío");
    }
    nombre = nuevoNombre;
}

void Producto::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio < 0) {
        throw InventarioException("El precio del producto no puede ser negativo");
    }
    precio = nuevoPrecio;
}

void Producto::setStock(int nuevoStock) {
    if (nuevoStock < 0) {
        throw InventarioException("El stock del producto no puede ser negativo");
    }
    stock = nuevoStock;
}

void Producto::mostrar() const {
    std::cout << "ID: " << id << " | "
              << "Nombre: " << nombre << " | "
              << "Precio: $" << std::fixed << std::setprecision(2) << precio << " | "
              << "Stock: " << stock << std::endl;
}

bool Producto::hayStock() const {
    return stock > 0;
}

void Producto::actualizarStock(int cantidad) {
    // Verificamos que no quede stock negativo
    if (stock + cantidad < 0) {
        throw InventarioException("No hay suficiente stock disponible");
    }
    stock += cantidad;
}

double Producto::calcularValorTotal() const {
    return precio * stock;
}

// Implementación de ProductoPerecedero
ProductoPerecedero::ProductoPerecedero(int id, const std::string& nombre, double precio, int stock, const std::string& fechaCaducidad)
    : Producto(id, nombre, precio, stock), fechaCaducidad(fechaCaducidad) {
    
    if (fechaCaducidad.empty()) {
        throw InventarioException("La fecha de caducidad no puede estar vacía");
    }
}

std::string ProductoPerecedero::getFechaCaducidad() const {
    return fechaCaducidad;
}

void ProductoPerecedero::setFechaCaducidad(const std::string& nuevaFecha) {
    if (nuevaFecha.empty()) {
        throw InventarioException("La fecha de caducidad no puede estar vacía");
    }
    fechaCaducidad = nuevaFecha;
}

void ProductoPerecedero::mostrar() const {
    Producto::mostrar();
    std::cout << "Fecha de caducidad: " << fechaCaducidad << std::endl;
}

double ProductoPerecedero::calcularValorTotal() const {
    // Ejemplo: los productos perecederos tienen un valor reducido en un 10%
    return Producto::calcularValorTotal() * 0.9;
}

// Implementación de Inventario
Inventario::Inventario() {
    // No hay recursos que inicializar específicamente
}

Inventario::~Inventario() {
    // Los unique_ptr se encargan de liberar la memoria automáticamente
}

int Inventario::contarProductos() const {
    return static_cast<int>(productos.size());
}

void Inventario::mostrarInventario() const {
    std::cout << "=== INVENTARIO (" << contarProductos() << " productos) ===" << std::endl;
    
    if (productos.empty()) {
        std::cout << "El inventario está vacío." << std::endl;
        return;
    }
    
    for (const auto& producto : productos) {
        producto->mostrar();
        std::cout << "---------------------------" << std::endl;
    }
}

void Inventario::agregarProducto(Producto* producto) {
    if (producto == nullptr) {
        throw InventarioException("No se puede agregar un producto nulo");
    }
    
    // Verificamos si ya existe un producto con el mismo ID
    for (const auto& p : productos) {
        if (p->getId() == producto->getId()) {
            throw InventarioException("Ya existe un producto con el ID " + std::to_string(producto->getId()));
        }
    }
    
    // Transferimos la propiedad del puntero a un unique_ptr
    productos.push_back(std::unique_ptr<Producto>(producto));
}

void Inventario::eliminarProducto(int id) {
    auto it = std::find_if(productos.begin(), productos.end(),
                          [id](const std::unique_ptr<Producto>& p) {
                              return p->getId() == id;
                          });
                          
    if (it == productos.end()) {
        throw InventarioException("No se encontró ningún producto con el ID " + std::to_string(id));
    }
    
    productos.erase(it);  // El unique_ptr se encarga de liberar la memoria
}

Producto* Inventario::buscarProducto(int id) {
    for (auto& p : productos) {
        if (p->getId() == id) {
            return p.get();  // Devolvemos un puntero raw sin transferir propiedad
        }
    }
    
    return nullptr;  // No se encontró el producto
}

/*Con referencias */
/* Producto* Inventario::buscarProducto(const std::string& nombre) {
    for (auto& producto : productos) { // assuming productos is a std::vector<Producto*>
        if (producto->getNombre() == nombre) {
            return producto;
        }
    }
    return nullptr;
}*/

const Producto* Inventario::buscarProducto(int id) const {
    for (const auto& p : productos) {
        if (p->getId() == id) {
            return p.get();  // Devolvemos un puntero raw constante
        }
    }
    
    return nullptr;  // No se encontró el producto
}

double Inventario::calcularValorInventario() const {
    double valorTotal = 0.0;
    
    for (const auto& producto : productos) {
        valorTotal += producto->calcularValorTotal();
    }
    
    return valorTotal;
}

void Inventario::actualizarStockMultiple(const std::vector<std::pair<int, int>>& actualizaciones) {
    // Vector para almacenar excepciones
    std::vector<std::string> errores;
    
    for (const auto& par : actualizaciones) {
        int id = par.first;
        int cantidad = par.second;
        
        try {
            Producto* producto = buscarProducto(id);
            
            if (producto == nullptr) {
                std::ostringstream oss;
                oss << "No se encontró el producto con ID " << id;
                errores.push_back(oss.str());
                continue;
            }
            
            producto->actualizarStock(cantidad);
        } catch (const InventarioException& e) {
            std::ostringstream oss;
            oss << "Error al actualizar producto con ID " << id << ": " << e.what();
            errores.push_back(oss.str());
        }
    }
    
    // Si hubo errores, lanzamos una excepción con todos ellos
    if (!errores.empty()) {
        std::ostringstream oss;
        oss << "Se produjeron los siguientes errores:\n";
        
        for (const auto& error : errores) {
            oss << "- " << error << "\n";
        }
        
        throw InventarioException(oss.str());
    }
}

void Inventario::ordenarInventario(OrdenInventario tipo) {
    switch (tipo) {
        case OrdenInventario::POR_ID:
            std::sort(productos.begin(), productos.end(),
                      [](const std::unique_ptr<Producto>& a, const std::unique_ptr<Producto>& b) {
                          return a->getId() < b->getId();
                      });
            break;
            
        case OrdenInventario::POR_NOMBRE:
            std::sort(productos.begin(), productos.end(),
                      [](const std::unique_ptr<Producto>& a, const std::unique_ptr<Producto>& b) {
                          return a->getNombre() < b->getNombre();
                      });
            break;
            
        case OrdenInventario::POR_PRECIO_ASC:
            std::sort(productos.begin(), productos.end(),
                      [](const std::unique_ptr<Producto>& a, const std::unique_ptr<Producto>& b) {
                          return a->getPrecio() < b->getPrecio();
                      });
            break;
            
        case OrdenInventario::POR_PRECIO_DESC:
            std::sort(productos.begin(), productos.end(),
                      [](const std::unique_ptr<Producto>& a, const std::unique_ptr<Producto>& b) {
                          return a->getPrecio() > b->getPrecio();
                      });
            break;
            
        case OrdenInventario::POR_STOCK:
            std::sort(productos.begin(), productos.end(),
                      [](const std::unique_ptr<Producto>& a, const std::unique_ptr<Producto>& b) {
                          return a->getStock() < b->getStock();
                      });
            break;
    }
}

std::vector<Producto*> Inventario::filtrarProductosBajosStock(int umbral) const {
    if (umbral < 0) {
        throw InventarioException("El umbral de stock no puede ser negativo");
    }
    
    std::vector<Producto*> resultado;
    
    for (const auto& producto : productos) {
        if (producto->getStock() <= umbral) {
            resultado.push_back(producto.get());
        }
    }
    
    return resultado;
}

std::pair<const Producto*, const Producto*> Inventario::encontrarProductosMayorMenorPrecio() const {
    if (productos.empty()) {
        return { nullptr, nullptr };
    }
    
    // Iteradores para los productos con mayor y menor precio
    auto maxPrecioIt = productos.begin();
    auto minPrecioIt = productos.begin();
    
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if ((*it)->getPrecio() > (*maxPrecioIt)->getPrecio()) {
            maxPrecioIt = it;
        }
        
        if ((*it)->getPrecio() < (*minPrecioIt)->getPrecio()) {
            minPrecioIt = it;
        }
    }
    
    return { maxPrecioIt->get(), minPrecioIt->get() };
}

std::map<std::string, double> Inventario::generarInformePorCategoria(
    const std::function<std::string(const Producto*)>& categorizador) const {
    
    if (!categorizador) {
        throw InventarioException("La función de categorización no puede ser nula");
    }
    
    std::map<std::string, double> informe;
    
    for (const auto& producto : productos) {
        try {
            std::string categoria = categorizador(producto.get());
            double valorProducto = producto->calcularValorTotal();
            
            // Actualizamos el valor para esta categoría
            informe[categoria] += valorProducto;
        } catch (const std::exception& e) {
            // Si hay un error con un producto, continuamos con los demás
            std::cerr << "Error al categorizar producto ID " << producto->getId() 
                      << ": " << e.what() << std::endl;
        }
    }
    
    return informe;
}