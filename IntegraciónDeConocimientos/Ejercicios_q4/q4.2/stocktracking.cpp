#include "stocktracking.h"
#include <iostream>

// Constructor
StockTracking::StockTracking(int capacidad) {
    capacidadInventario = capacidad;
    cantidadProductos = 0;
    inventario = new Producto[capacidadInventario];
}

// Destructor
StockTracking::~StockTracking() {
    delete[] inventario;
}

// Agregar un producto al inventario
bool StockTracking::agregarProducto(const Producto& producto) {
    // Verificar si hay espacio en el inventario
    if (cantidadProductos >= capacidadInventario) {
        std::cout << "Error: Inventario lleno." << std::endl;
        return false;
    }
    
    // Verificar si el producto ya existe (mismo ID)
    for (int i = 0; i < cantidadProductos; i++) {
        if (inventario[i].id == producto.id) {
            std::cout << "Error: Ya existe un producto con el ID " << producto.id << std::endl;
            return false;
        }
    }
    
    // Agregar el producto al inventario
    inventario[cantidadProductos] = producto;
    cantidadProductos++;
    
    std::cout << "Producto '" << producto.nombre << "' agregado al inventario." << std::endl;
    return true;
}

// Eliminar un producto del inventario por ID
bool StockTracking::eliminarProducto(int id) {
    int posicion = -1;
    
    // Buscar la posición del producto
    for (int i = 0; i < cantidadProductos; i++) {
        if (inventario[i].id == id) {
            posicion = i;
            break;
        }
    }
    
    // Si no se encontró el producto
    if (posicion == -1) {
        std::cout << "Error: No se encontró un producto con el ID " << id << std::endl;
        return false;
    }
    
    // Guardar el producto eliminado en la pila de productos recientes
    agregarProductoReciente(inventario[posicion]);
    
    // Desplazar los productos para llenar el hueco
    for (int i = posicion; i < cantidadProductos - 1; i++) {
        inventario[i] = inventario[i + 1];
    }
    
    cantidadProductos--;
    std::cout << "Producto con ID " << id << " eliminado del inventario." << std::endl;
    return true;
}

// Buscar un producto por ID
Producto* StockTracking::buscarProducto(int id) {
    for (int i = 0; i < cantidadProductos; i++) {
        if (inventario[i].id == id) {
            return &inventario[i];
        }
    }
    
    return nullptr; // No se encontró el producto
}

// Listar todos los productos en el inventario
void StockTracking::listarProductos() {
    if (cantidadProductos == 0) {
        std::cout << "El inventario está vacío." << std::endl;
        return;
    }
    
    std::cout << "\n--- INVENTARIO ACTUAL ---" << std::endl;
    std::cout << "ID\tNombre\t\tCantidad\tPrecio" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    for (int i = 0; i < cantidadProductos; i++) {
        std::cout << inventario[i].id << "\t" 
                 << inventario[i].nombre << "\t\t" 
                 << inventario[i].cantidad << "\t\t" 
                 << inventario[i].precio << std::endl;
    }
    
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Total de productos: " << cantidadProductos << std::endl;
    std::cout << "Valor total del inventario: $" << calcularValorTotal() << std::endl;
}

// Agregar un producto a la cola de productos entrantes
void StockTracking::agregarProductoEntrante(const Producto& producto) {
    productosEntrantes.push(producto);
    std::cout << "Producto '" << producto.nombre << "' agregado a la cola de productos entrantes." << std::endl;
}

// Procesar el próximo producto entrante (sacarlo de la cola y agregarlo al inventario)
bool StockTracking::procesarProductoEntrante() {
    if (productosEntrantes.empty()) {
        std::cout << "No hay productos entrantes para procesar." << std::endl;
        return false;
    }
    
    Producto producto = productosEntrantes.front();
    productosEntrantes.pop();
    
    std::cout << "Procesando producto entrante: " << producto.nombre << std::endl;
    
    // Intentar agregar el producto al inventario
    return agregarProducto(producto);
}

// Mostrar todos los productos en la cola de productos entrantes
void StockTracking::mostrarProductosEntrantes() {
    if (productosEntrantes.empty()) {
        std::cout << "No hay productos entrantes en espera." << std::endl;
        return;
    }
    
    std::cout << "\n--- PRODUCTOS ENTRANTES ---" << std::endl;
    std::cout << "Cantidad de productos en espera: " << productosEntrantes.size() << std::endl;
    
    // Crear una copia de la cola para mostrar los elementos sin modificar la original
    std::queue<Producto> copiaCola = productosEntrantes;
    
    int posicion = 1;
    while (!copiaCola.empty()) {
        Producto p = copiaCola.front();
        copiaCola.pop();
        
        std::cout << posicion << ". ID: " << p.id 
                 << ", Nombre: " << p.nombre 
                 << ", Cantidad: " << p.cantidad 
                 << ", Precio: " << p.precio << std::endl;
        
        posicion++;
    }
}

// Agregar un producto a la pila de productos recientes
void StockTracking::agregarProductoReciente(const Producto& producto) {
    productosRecientes.push(producto);
    std::cout << "Producto '" << producto.nombre << "' agregado a la pila de productos recientes." << std::endl;
}

// Devolver el producto más reciente al inventario
bool StockTracking::devolverProductoReciente() {
    if (productosRecientes.empty()) {
        std::cout << "No hay productos recientes para devolver." << std::endl;
        return false;
    }
    
    Producto producto = productosRecientes.top();
    productosRecientes.pop();
    
    std::cout << "Devolviendo el producto más reciente al inventario: " << producto.nombre << std::endl;
    
    // Intentar agregar el producto al inventario
    return agregarProducto(producto);
}

// Mostrar todos los productos en la pila de productos recientes
void StockTracking::mostrarProductosRecientes() {
    if (productosRecientes.empty()) {
        std::cout << "No hay productos recientes." << std::endl;
        return;
    }
    
    std::cout << "\n--- PRODUCTOS RECIENTES ---" << std::endl;
    std::cout << "Cantidad de productos recientes: " << productosRecientes.size() << std::endl;
    
    // Crear una copia de la pila para mostrar los elementos sin modificar la original
    std::stack<Producto> copiaPila = productosRecientes;
    
    int posicion = 1;
    while (!copiaPila.empty()) {
        Producto p = copiaPila.top();
        copiaPila.pop();
        
        std::cout << posicion << ". ID: " << p.id 
                 << ", Nombre: " << p.nombre 
                 << ", Cantidad: " << p.cantidad 
                 << ", Precio: " << p.precio << std::endl;
        
        posicion++;
    }
}

// Contar el número total de productos en el inventario
int StockTracking::contarProductos() {
    return cantidadProductos;
}

// Calcular el valor total del inventario
double StockTracking::calcularValorTotal() {
    double total = 0.0;
    
    for (int i = 0; i < cantidadProductos; i++) {
        total += inventario[i].cantidad * inventario[i].precio;
    }
    
    return total;
}