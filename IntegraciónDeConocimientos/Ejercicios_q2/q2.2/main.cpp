#include <iostream>
#include <iomanip>
#include "stocktaking.h"
/*g++ -std=c++11 q1.cpp main.cpp -o library*/
int main() {
    try {
        // Crear instancia del inventario
        Inventario miInventario;
        
        // Agregar algunos productos
        miInventario.agregarProducto(Producto(1, "Laptop", 1200.50, 5, Categoria::ELECTRONICA));
        miInventario.agregarProducto(Producto(2, "Camiseta", 25.99, 50, Categoria::ROPA));
        miInventario.agregarProducto(Producto(3, "Arroz", 3.45, 100, Categoria::ALIMENTOS));
        miInventario.agregarProducto(Producto(4, "Silla", 85.00, 10, Categoria::HOGAR));
        miInventario.agregarProducto(Producto(5, "Smartphone", 800.00, 15, Categoria::ELECTRONICA));
        
        // Mostrar el inventario completo
        std::cout << "\nInventario completo:" << std::endl;
        miInventario.mostrarInventario();
        
        // Mostrar productos por categor�a
        std::cout << "\nProductos electr�nicos:" << std::endl;
        miInventario.mostrarPorCategoria(Categoria::ELECTRONICA);
        
        // Calcular y mostrar el valor total del inventario
        std::cout << "\nValor total del inventario: $" 
                  << std::fixed << std::setprecision(2) 
                  << miInventario.calcularValorTotal() << std::endl;
        
        // Actualizar cantidad de un producto
        std::cout << "\nActualizando cantidad del producto con ID 3:" << std::endl;
        try {
            miInventario.actualizarCantidad(3, 200);
        } catch (const InventarioException& e) {
            std::cerr << "Error al actualizar cantidad: " << e.what() << std::endl;
        }
        
        // Actualizar precio de un producto
        std::cout << "\nActualizando precio del producto con ID 2:" << std::endl;
        try {
            miInventario.actualizarPrecio(2, 29.99);
        } catch (const InventarioException& e) {
            std::cerr << "Error al actualizar precio: " << e.what() << std::endl;
        }
        
        // Intentar actualizar un producto inexistente
        std::cout << "\nIntentando actualizar producto inexistente:" << std::endl;
        try {
            miInventario.actualizarCantidad(10, 5);
        } catch (const InventarioException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }
        
        // Intentar agregar un producto con ID duplicado
        std::cout << "\nIntentando agregar producto con ID duplicado:" << std::endl;
        try {
            miInventario.agregarProducto(Producto(1, "TV", 500.00, 8, Categoria::ELECTRONICA));
        } catch (const InventarioException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }
        
        // Intentar agregar un producto con precio negativo
        std::cout << "\nIntentando agregar producto con precio negativo:" << std::endl;
        try {
            miInventario.agregarProducto(Producto(6, "Altavoz", -50.00, 10, Categoria::ELECTRONICA));
        } catch (const InventarioException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }
        
        // Eliminar un producto
        std::cout << "\nEliminando producto con ID 4:" << std::endl;
        try {
            miInventario.eliminarProducto(4);
        } catch (const InventarioException& e) {
            std::cerr << "Error al eliminar: " << e.what() << std::endl;
        }
        
        // Mostrar el inventario actualizado
        std::cout << "\nInventario actualizado:" << std::endl;
        miInventario.mostrarInventario();
        
        // Buscar un producto por ID
        std::cout << "\nBuscando producto con ID 5:" << std::endl;
        try {
            Producto prod = miInventario.buscarPorId(5);
            std::cout << "Producto encontrado: " << prod.nombre << ", Precio: $" 
                      << std::fixed << std::setprecision(2) << prod.precio 
                      << ", Cantidad: " << prod.cantidad << std::endl;
        } catch (const InventarioException& e) {
            std::cerr << "Error al buscar: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error general: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
