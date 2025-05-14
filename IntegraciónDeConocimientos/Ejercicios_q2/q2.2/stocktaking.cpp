#include "stocktaking.h"
#include <iostream>
#include <iomanip>

// Constructor
Inventario::Inventario() : numProductos(0) {
    // Inicializar el array de productos con valores por defecto
    for (auto& producto : productos) {
        producto = Producto();
    }
}

// M�todo para agregar un producto al inventario
void Inventario::agregarProducto(const Producto& producto) {
    try {
        if (numProductos >= MAX_PRODUCTOS) {
            throw InventarioException("Error: Capacidad m�xima del inventario alcanzada");
        }
        
        // Verificar si ya existe un producto con el mismo ID
        for (int i = 0; i < numProductos; i++) {
            if (productos[i].id == producto.id && producto.id != 0) {
                throw InventarioException("Error: Ya existe un producto con el ID " + std::to_string(producto.id));
            }
        }
        
        // Validar que el precio no sea negativo
        if (producto.precio < 0) {
            throw InventarioException("Error: El precio no puede ser negativo");
        }
        
        // Validar que la cantidad no sea negativa
        if (producto.cantidad < 0) {
            throw InventarioException("Error: La cantidad no puede ser negativa");
        }
        
        // Agregar el producto al inventario
        productos[numProductos] = producto;
        numProductos++;
        std::cout << "Producto \"" << producto.nombre << "\" agregado con �xito." << std::endl;
    }
    catch (const InventarioException& e) {
        std::cerr << e.what() << std::endl;
        throw; // Re-lanzar la excepci�n
    }
    catch (const std::exception& e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
        throw InventarioException("Error interno al agregar producto");
    }
}

// M�todo para actualizar la cantidad de un producto
void Inventario::actualizarCantidad(int id, int nuevaCantidad) {
    try {
        if (nuevaCantidad < 0) {
            throw InventarioException("Error: La cantidad no puede ser negativa");
        }
        
        bool encontrado = false;
        
        for (int i = 0; i < numProductos; i++) {
            if (productos[i].id == id) {
                encontrado = true;
                productos[i].cantidad = nuevaCantidad;
                std::cout << "Cantidad del producto \"" << productos[i].nombre 
                          << "\" actualizada a " << nuevaCantidad << "." << std::endl;
                break;
            }
        }
        
        if (!encontrado) {
            throw InventarioException("Error: No se encontr� un producto con el ID " + std::to_string(id));
        }
    }
    catch (const InventarioException& e) {
        std::cerr << e.what() << std::endl;
        throw; // Re-lanzar la excepci�n
    }
}

// M�todo para actualizar el precio de un producto
void Inventario::actualizarPrecio(int id, double nuevoPrecio) {
    try {
        if (nuevoPrecio < 0) {
            throw InventarioException("Error: El precio no puede ser negativo");
        }
        
        bool encontrado = false;
        
        for (int i = 0; i < numProductos; i++) {
            if (productos[i].id == id) {
                encontrado = true;
                productos[i].precio = nuevoPrecio;
                std::cout << "Precio del producto \"" << productos[i].nombre 
                          << "\" actualizado a " << nuevoPrecio << "." << std::endl;
                break;
            }
        }
        
        if (!encontrado) {
            throw InventarioException("Error: No se encontr� un producto con el ID " + std::to_string(id));
        }
    }
    catch (const InventarioException& e) {
        std::cerr << e.what() << std::endl;
        throw; // Re-lanzar la excepci�n
    }
}

// M�todo para eliminar un producto del inventario
void Inventario::eliminarProducto(int id) {
    try {
        bool encontrado = false;
        int posicion = -1;
        
        for (int i = 0; i < numProductos; i++) {
            if (productos[i].id == id) {
                encontrado = true;
                posicion = i;
                break;
            }
        }
        
        if (!encontrado) {
            throw InventarioException("Error: No se encontr� un producto con el ID " + std::to_string(id));
        }
        
        // Eliminar el producto desplazando los elementos
        std::string nombreProducto = productos[posicion].nombre;
        for (int i = posicion; i < numProductos - 1; i++) {
            productos[i] = productos[i + 1];
        }
        numProductos--;
        
        std::cout << "Producto \"" << nombreProducto << "\" eliminado con �xito." << std::endl;
    }
    catch (const InventarioException& e) {
        std::cerr << e.what() << std::endl;
        throw; // Re-lanzar la excepci�n
    }
}

// M�todo para buscar un producto por su ID
Producto Inventario::buscarPorId(int id) const {
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].id == id) {
            return productos[i];
        }
    }
    throw InventarioException("Error: No se encontr� un producto con el ID " + std::to_string(id));
}

// M�todo para mostrar todo el inventario
void Inventario::mostrarInventario() const {
    if (numProductos == 0) {
        std::cout << "El inventario est� vac�o." << std::endl;
        return;
    }
    
    std::cout << "=== INVENTARIO DE PRODUCTOS ===" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(20) << "Nombre" 
              << std::setw(10) << "Precio" 
              << std::setw(10) << "Cantidad" 
              << "Categor�a" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    
    for (int i = 0; i < numProductos; i++) {
        std::cout << std::left << std::setw(5) << productos[i].id 
                  << std::setw(20) << productos[i].nombre 
                  << std::setw(10) << std::fixed << std::setprecision(2) << productos[i].precio 
                  << std::setw(10) << productos[i].cantidad 
                  << categoriaToString(productos[i].categoria) << std::endl;
    }
}

// M�todo para mostrar productos por categor�a
void Inventario::mostrarPorCategoria(Categoria cat) const {
    bool hayProductos = false;
    
    std::cout << "=== PRODUCTOS DE CATEGOR�A: " << categoriaToString(cat) << " ===" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(20) << "Nombre" 
              << std::setw(10) << "Precio" 
              << std::setw(10) << "Cantidad" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].categoria == cat) {
            std::cout << std::left << std::setw(5) << productos[i].id 
                      << std::setw(20) << productos[i].nombre 
                      << std::setw(10) << std::fixed << std::setprecision(2) << productos[i].precio 
                      << std::setw(10) << productos[i].cantidad << std::endl;
            hayProductos = true;
        }
    }
    
    if (!hayProductos) {
        std::cout << "No hay productos en esta categor�a." << std::endl;
    }
}

// M�todo para calcular el valor total del inventario
double Inventario::calcularValorTotal() const {
    double total = 0.0;
    
    for (int i = 0; i < numProductos; i++) {
        total += productos[i].precio * productos[i].cantidad;
    }
    
    return total;
}

// M�todo para convertir Categoria a string
std::string Inventario::categoriaToString(Categoria cat) {
    switch (cat) {
        case Categoria::ELECTRONICA:
            return "Electr�nica";
        case Categoria::ROPA:
            return "Ropa";
        case Categoria::ALIMENTOS:
            return "Alimentos";
        case Categoria::HOGAR:
            return "Hogar";
        case Categoria::OTRO:
            return "Otro";
        default:
            return "Desconocida";
    }
}
