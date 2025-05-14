#include <iostream>
#include <limits>
#include "task_manager.h"
/*g++ -std=c++11 q1.cpp main.cpp -o library*/
// Funci�n para mostrar el men� principal
void mostrarMenu() {
    std::cout << "\n==== GESTOR DE TAREAS ====" << std::endl;
    std::cout << "1. Agregar nueva tarea" << std::endl;
    std::cout << "2. Listar todas las tareas" << std::endl;
    std::cout << "3. Actualizar estado de una tarea" << std::endl;
    std::cout << "4. Eliminar una tarea" << std::endl;
    std::cout << "5. Filtrar tareas por estado" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opci�n: ";
}

// Funci�n para limpiar el buffer de entrada
void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    GestorTareas gestor;
    int opcion = -1;
    
    // Ejemplos de tareas predefinidas para empezar
    try {
        gestor.agregarTarea("Estudiar C++", "Repasar conceptos de arrays y estructuras", 5);
        gestor.agregarTarea("Hacer compras", "Ir al supermercado por v�veres", 3);
        gestor.agregarTarea("Ejercicio", "30 minutos de cardio", 4);
    } catch (const TareaException& e) {
        std::cerr << "Error al inicializar: " << e.what() << std::endl;
    }
    
    while (opcion != 0) {
        mostrarMenu();
        
        try {
            if (!(std::cin >> opcion)) {
                throw TareaException("Entrada inv�lida. Ingrese un n�mero.");
            }
            
            limpiarBuffer();
            
            switch (opcion) {
                case 1: {
                    std::string titulo, descripcion;
                    int prioridad;
                    
                    std::cout << "\n--- AGREGAR NUEVA TAREA ---" << std::endl;
                    std::cout << "T�tulo: ";
                    std::getline(std::cin, titulo);
                    
                    std::cout << "Descripci�n: ";
                    std::getline(std::cin, descripcion);
                    
                    std::cout << "Prioridad (1-5): ";
                    if (!(std::cin >> prioridad)) {
                        limpiarBuffer();
                        throw TareaException("La prioridad debe ser un n�mero");
                    }
                    limpiarBuffer();
                    
                    gestor.agregarTarea(titulo, descripcion, prioridad);
                    break;
                }
                
                case 2:
                    gestor.listarTareas();
                    break;
                    
                case 3: {
                    int id, estadoInt;
                    
                    std::cout << "\n--- ACTUALIZAR ESTADO DE TAREA ---" << std::endl;
                    gestor.listarTareas();
                    
                    std::cout << "ID de la tarea a actualizar: ";
                    if (!(std::cin >> id)) {
                        limpiarBuffer();
                        throw TareaException("ID inv�lido");
                    }
                    
                    std::cout << "Nuevo estado (0: Pendiente, 1: En Progreso, 2: Completada): ";
                    if (!(std::cin >> estadoInt) || estadoInt < 0 || estadoInt > 2) {
                        limpiarBuffer();
                        throw TareaException("Estado inv�lido");
                    }
                    limpiarBuffer();
                    
                    gestor.actualizarEstado(id, static_cast<Tarea::Estado>(estadoInt));
                    break;
                }
                
                case 4: {
                    int id;
                    
                    std::cout << "\n--- ELIMINAR TAREA ---" << std::endl;
                    gestor.listarTareas();
                    
                    std::cout << "ID de la tarea a eliminar: ";
                    if (!(std::cin >> id)) {
                        limpiarBuffer();
                        throw TareaException("ID inv�lido");
                    }
                    limpiarBuffer();
                    
                    gestor.eliminarTarea(id);
                    break;
                }
                
                case 5: {
                    int estadoInt;
                    
                    std::cout << "\n--- FILTRAR TAREAS POR ESTADO ---" << std::endl;
                    std::cout << "Estado a filtrar (0: Pendiente, 1: En Progreso, 2: Completada): ";
                    if (!(std::cin >> estadoInt) || estadoInt < 0 || estadoInt > 2) {
                        limpiarBuffer();
                        throw TareaException("Estado inv�lido");
                    }
                    limpiarBuffer();
                    
                    gestor.filtrarPorEstado(static_cast<Tarea::Estado>(estadoInt));
                    break;
                }
                
                case 0:
                    std::cout << "Saliendo del programa. �Hasta pronto!" << std::endl;
                    break;
                    
                default:
                    std::cout << "Opci�n inv�lida. Intente nuevamente." << std::endl;
            }
        } catch (const TareaException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error inesperado: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
