#include <iostream>
#include "stocktracking.h"

int main() {
    Inventario stock;
    int id = 1;
    int option;
    do {
        std::cout << "\n--- Sistema de Inventario ---\n";
        std::cout << "1. Agregar producto\n";
        std::cout << "2. Mostrar inventario\n";
        std::cout << "3. Buscar producto\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;

        switch(option) {
            case 1: {
                std::string nombre;
                double precio;
                int cantidad;
                std::cout << "Nombre del producto: ";
                std::cin >> nombre;
                std::cout << "Precio: ";
                std::cin >> precio;
                std::cout << "Cantidad: ";
                std::cin >> cantidad;
                Producto* nuevoProducto = new Producto(id++, nombre, precio, cantidad);
                stock.agregarProducto(nuevoProducto);
                break;
            }
            case 2:
                stock.mostrarInventario();
                break;
            case 3: {
                std::string nombre;
                std::cout << "Nombre del producto a buscar: ";
                std::cin >> nombre;
                Producto* encontrado = stock.buscarProducto(id);
                if (encontrado != nullptr) {
                    std::cout << "Producto encontrado: " << encontrado->getNombre() << ", Cantidad: " << encontrado->getNombre() << std::endl;
                } else {
                    std::cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while(option != 4);

    return 0;
}