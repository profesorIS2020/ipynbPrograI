#include <iostream>
#include <limits>
#include "stocktracking.h"

using namespace std;

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n=== SISTEMA DE STOCKTRACKING ===" << endl;
    cout << "1. Agregar producto al inventario" << endl;
    cout << "2. Eliminar producto del inventario" << endl;
    cout << "3. Buscar producto por ID" << endl;
    cout << "4. Listar todos los productos" << endl;
    cout << "5. Agregar producto a la cola de entrantes" << endl;
    cout << "6. Procesar producto entrante" << endl;
    cout << "7. Mostrar productos entrantes" << endl;
    cout << "8. Devolver producto reciente al inventario" << endl;
    cout << "9. Mostrar productos recientes" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opción: ";
}

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // Crear un objeto StockTracking con capacidad para 100 productos
    StockTracking stock(100);
    
    int opcion;
    bool salir = false;
    
    cout << "Bienvenido al Sistema de StockTracking" << endl;
    
    while (!salir) {
        mostrarMenu();
        cin >> opcion;
        limpiarBuffer();
        
        switch (opcion) {
            case 1: { // Agregar producto al inventario
                Producto nuevoProducto;
                cout << "Ingrese ID del producto: ";
                cin >> nuevoProducto.id;
                limpiarBuffer();
                
                cout << "Ingrese nombre del producto: ";
                getline(cin, nuevoProducto.nombre);
                
                cout << "Ingrese cantidad: ";
                cin >> nuevoProducto.cantidad;
                
                cout << "Ingrese precio: ";
                cin >> nuevoProducto.precio;
                
                stock.agregarProducto(nuevoProducto);
                break;
            }
            case 2: { // Eliminar producto
                int id;
                cout << "Ingrese ID del producto a eliminar: ";
                cin >> id;
                
                stock.eliminarProducto(id);
                break;
            }
            case 3: { // Buscar producto
                int id;
                cout << "Ingrese ID del producto a buscar: ";
                cin >> id;
                
                Producto* producto = stock.buscarProducto(id);
                
                if (producto != nullptr) {
                    cout << "\n--- PRODUCTO ENCONTRADO ---" << endl;
                    cout << "ID: " << producto->id << endl;
                    cout << "Nombre: " << producto->nombre << endl;
                    cout << "Cantidad: " << producto->cantidad << endl;
                    cout << "Precio: $" << producto->precio << endl;
                } else {
                    cout << "No se encontró un producto con ID " << id << endl;
                }
                break;
            }
            case 4: { // Listar productos
                stock.listarProductos();
                break;
            }
            case 5: { // Agregar producto a la cola de entrantes
                Producto nuevoProducto;
                cout << "Ingrese ID del producto entrante: ";
                cin >> nuevoProducto.id;
                limpiarBuffer();
                
                cout << "Ingrese nombre del producto: ";
                getline(cin, nuevoProducto.nombre);
                
                cout << "Ingrese cantidad: ";
                cin >> nuevoProducto.cantidad;
                
                cout << "Ingrese precio: ";
                cin >> nuevoProducto.precio;
                
                stock.agregarProductoEntrante(nuevoProducto);
                break;
            }
            case 6: { // Procesar producto entrante
                stock.procesarProductoEntrante();
                break;
            }
            case 7: { // Mostrar productos entrantes
                stock.mostrarProductosEntrantes();
                break;
            }
            case 8: { // Devolver producto reciente
                stock.devolverProductoReciente();
                break;
            }
            case 9: { // Mostrar productos recientes
                stock.mostrarProductosRecientes();
                break;
            }
            case 0: { // Salir
                cout << "Gracias por usar el Sistema de StockTracking. ¡Hasta pronto!" << endl;
                salir = true;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
                break;
            }
        }
    }
    
    return 0;
}