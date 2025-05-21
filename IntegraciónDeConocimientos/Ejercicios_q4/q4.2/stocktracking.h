#ifndef STOCKTRACKING_H
#define STOCKTRACKING_H

#include <string>
#include <queue>
#include <stack>

// Estructura para almacenar información de un producto
struct Producto {
    int id;
    std::string nombre;
    int cantidad;
    double precio;
};

class StockTracking {
private:
    // Cola para los productos pendientes de recibir
    std::queue<Producto> productosEntrantes;
    
    // Pila para los productos que han sido entregados recientemente
    std::stack<Producto> productosRecientes;
    
    // Arreglo de productos en inventario
    Producto* inventario;
    int capacidadInventario;
    int cantidadProductos;

public:
    // Constructor y destructor
    StockTracking(int capacidad);
    ~StockTracking();
    
    // Métodos para manipular el inventario
    bool agregarProducto(const Producto& producto);
    bool eliminarProducto(int id);
    Producto* buscarProducto(int id);
    void listarProductos();
    
    // Métodos para manipular la cola de productos entrantes
    void agregarProductoEntrante(const Producto& producto);
    bool procesarProductoEntrante();
    void mostrarProductosEntrantes();
    
    // Métodos para manipular la pila de productos recientes
    void agregarProductoReciente(const Producto& producto);
    bool devolverProductoReciente();
    void mostrarProductosRecientes();
    
    // Métodos adicionales
    int contarProductos();
    double calcularValorTotal();
};

#endif // STOCKTRACKING_H