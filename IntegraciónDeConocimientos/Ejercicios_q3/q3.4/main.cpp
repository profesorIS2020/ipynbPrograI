#include "TaskManager.h"
#include <iostream>
#include <limits>
#include <stdexcept>
/*g++ -std=c++14 main.cpp TaskManager.cpp -o TaskManager */
// Función auxiliar para limpiar buffer de entrada
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Función para mostrar el menú principal
void showMenu() {
    std::cout << "\n===== TASK MANAGER =====\n"
              << "1. Añadir tarea simple\n"
              << "2. Añadir tarea detallada\n"
              << "3. Añadir tarea con validación\n"
              << "4. Mostrar todas las tareas\n"
              << "5. Marcar tarea como completada\n"
              << "6. Eliminar tarea\n"
              << "7. Buscar tarea por ID\n"
              << "8. Filtrar tareas por estado\n"
              << "9. Ordenar tareas por prioridad\n"
              << "10. Filtrar tareas por fecha\n"
              << "11. Guardar tareas en archivo\n"
              << "12. Cargar tareas desde archivo\n"
              << "13. Buscar tareas avanzado\n"
              << "0. Salir\n"
              << "Seleccione una opción: ";
}

// Función para leer una fecha desde la entrada estándar
Date readDate() {
    int day, month, year;
    std::cout << "Ingrese día: ";
    std::cin >> day;
    std::cout << "Ingrese mes: ";
    std::cin >> month;
    std::cout << "Ingrese año: ";
    std::cin >> year;
    
    try {
        return Date(day, month, year);
    } catch (const std::invalid_argument& e) {
        std::cout << "Error en la fecha: " << e.what() << ". Usando fecha por defecto.\n";
        return Date(); // Usamos fecha por defecto
    }
}

// Función para leer una prioridad desde la entrada estándar
Priority readPriority() {
    int choice;
    std::cout << "Seleccione prioridad:\n"
              << "1. Baja\n"
              << "2. Media\n"
              << "3. Alta\n"
              << "4. Urgente\n"
              << "Opción: ";
    std::cin >> choice;
    
    switch (choice) {
        case 1: return Priority::LOW;
        case 2: return Priority::MEDIUM;
        case 3: return Priority::HIGH;
        case 4: return Priority::URGENT;
        default: 
            std::cout << "Opción inválida. Usando prioridad media por defecto.\n";
            return Priority::MEDIUM;
    }
}

// Función para leer un estado desde la entrada estándar
Status readStatus() {
    int choice;
    std::cout << "Seleccione estado:\n"
              << "1. Pendiente\n"
              << "2. En progreso\n"
              << "3. Completada\n"
              << "4. Cancelada\n"
              << "Opción: ";
    std::cin >> choice;
    
    switch (choice) {
        case 1: return Status::PENDING;
        case 2: return Status::IN_PROGRESS;
        case 3: return Status::COMPLETED;
        case 4: return Status::CANCELLED;
        default: 
            std::cout << "Opción inválida. Usando estado pendiente por defecto.\n";
            return Status::PENDING;
    }
}

int main() {
    TaskManager manager;
    int option;
    
    std::cout << "Bienvenido al Sistema de Gestión de Tareas" << std::endl;
    
    do {
        showMenu();
        std::cin >> option;
        clearInputBuffer();
        
        try {
            switch (option) {
                case 1: {
                    // Añadir tarea simple
                    std::string title;
                    std::cout << "Ingrese título de la tarea: ";
                    std::getline(std::cin, title);
                    
                    manager.addTask(title);
                    std::cout << "Tarea añadida correctamente." << std::endl;
                    break;
                }
                case 2: {
                    // Añadir tarea detallada
                    std::string title, description;
                    std::cout << "Ingrese título de la tarea: ";
                    std::getline(std::cin, title);
                    std::cout << "Ingrese descripción: ";
                    std::getline(std::cin, description);
                    
                    Date dueDate = readDate();
                    Priority priority = readPriority();
                    
                    manager.addDetailedTask(title, description, dueDate, priority);
                    std::cout << "Tarea detallada añadida correctamente." << std::endl;
                    break;
                }
                case 3: {
                    // Añadir tarea con validación completa
                    std::string title, description;
                    std::cout << "Ingrese título de la tarea: ";
                    std::getline(std::cin, title);
                    std::cout << "Ingrese descripción: ";
                    std::getline(std::cin, description);
                    
                    Date dueDate = readDate();
                    Priority priority = readPriority();
                    Status status = readStatus();
                    
                    manager.addTaskWithValidation(title, description, dueDate, priority, status);
                    std::cout << "Tarea validada añadida correctamente." << std::endl;
                    break;
                }
                case 4: {
                    // Mostrar todas las tareas
                    manager.displayAllTasks();
                    break;
                }
                case 5: {
                    // Marcar tarea como completada
                    int id;
                    std::cout << "Ingrese ID de la tarea a completar: ";
                    std::cin >> id;
                    
                    if (manager.markTaskAsCompleted(id)) {
                        std::cout << "Tarea marcada como completada." << std::endl;
                    } else {
                        std::cout << "No se encontró la tarea con ID " << id << std::endl;
                    }
                    break;
                }
                case 6: {
                    // Eliminar tarea
                    int id;
                    std::cout << "Ingrese ID de la tarea a eliminar: ";
                    std::cin >> id;
                    
                    if (manager.removeTask(id)) {
                        std::cout << "Tarea eliminada correctamente." << std::endl;
                    } else {
                        std::cout << "No se encontró la tarea con ID " << id << std::endl;
                    }
                    break;
                }
                case 7: {
                    // Buscar tarea por ID
                    int id;
                    std::cout << "Ingrese ID de la tarea a buscar: ";
                    std::cin >> id;
                    
                    Task* task = manager.getTaskById(id);
                    if (task != nullptr) {
                        std::cout << "Tarea encontrada:\n" << task->toString() << std::endl;
                    } else {
                        std::cout << "No se encontró la tarea con ID " << id << std::endl;
                    }
                    break;
                }
                case 8: {
                    // Filtrar tareas por estado
                    std::cout << "Filtrar tareas por estado:" << std::endl;
                    Status status = readStatus();
                    
                    std::vector<Task*> filteredTasks = manager.getTasksByStatus(status);
                    
                    if (filteredTasks.empty()) {
                        std::cout << "No hay tareas con el estado seleccionado." << std::endl;
                    } else {
                        std::cout << "Tareas encontradas:" << std::endl;
                        for (const Task* task : filteredTasks) {
                            std::cout << task->toString() << "\n" << std::endl;
                        }
                    }
                    break;
                }
                case 9: {
                    // Ordenar tareas por prioridad
                    manager.sortTasksByPriority();
                    std::cout << "Tareas ordenadas por prioridad." << std::endl;
                    manager.displayAllTasks();
                    break;
                }
                case 10: {
                    // Filtrar tareas por fecha
                    std::cout << "Ingrese fecha para filtrar:" << std::endl;
                    Date filterDate = readDate();
                    
                    std::vector<const Task*> filteredTasks;
                    manager.filterTasksByDueDate(filterDate, filteredTasks);
                    
                    if (filteredTasks.empty()) {
                        std::cout << "No hay tareas para la fecha " << filterDate.toString() << std::endl;
                    } else {
                        std::cout << "Tareas para la fecha " << filterDate.toString() << ":" << std::endl;
                        for (const Task* task : filteredTasks) {
                            std::cout << task->toString() << "\n" << std::endl;
                        }
                    }
                    break;
                }
                case 11: {
                    // Guardar tareas en archivo
                    std::string filename;
                    std::cout << "Ingrese nombre del archivo para guardar: ";
                    std::getline(std::cin, filename);
                    
                    manager.saveTasks(filename);
                    std::cout << "Tareas guardadas correctamente en " << filename << std::endl;
                    break;
                }
                case 12: {
                    // Cargar tareas desde archivo
                    std::string filename;
                    std::cout << "Ingrese nombre del archivo para cargar: ";
                    std::getline(std::cin, filename);
                    
                    manager.loadTasks(filename);
                    std::cout << "Tareas cargadas correctamente desde " << filename << std::endl;
                    break;
                }
                case 13: {
                    // Búsqueda avanzada usando el método findTasksIf con lambdas
                    int searchType;
                    std::cout << "Seleccione tipo de búsqueda:\n"
                              << "1. Tareas urgentes pendientes\n"
                              << "2. Tareas completadas\n"
                              << "3. Tareas con título que contenga texto\n"
                              << "Opción: ";
                    std::cin >> searchType;
                    clearInputBuffer();
                    
                    std::vector<std::reference_wrapper<const Task>> results;
                    
                    switch (searchType) {
                        case 1:
                            // Demostración de uso de punteros y referencias con lambda
                            results = manager.findTasksIf([](const Task& t) {
                                return t.getPriority() == Priority::URGENT && 
                                       t.getStatus() == Status::PENDING;
                            });
                            break;
                        case 2:
                            results = manager.findTasksIf([](const Task& t) {
                                return t.getStatus() == Status::COMPLETED;
                            });
                            break;
                        case 3: {
                            std::string searchText;
                            std::cout << "Ingrese texto a buscar en títulos: ";
                            std::getline(std::cin, searchText);
                            
                            results = manager.findTasksIf([&searchText](const Task& t) {
                                // Buscamos subcadena en el título (case sensitive)
                                return t.getTitle().find(searchText) != std::string::npos;
                            });
                            break;
                        }
                        default:
                            std::cout << "Opción inválida." << std::endl;
                            break;
                    }
                    
                    if (results.empty()) {
                        std::cout << "No se encontraron tareas con los criterios seleccionados." << std::endl;
                    } else {
                        std::cout << "Resultados de la búsqueda:" << std::endl;
                        for (const Task& task : results) {
                            // Usamos referencia para evitar copias
                            std::cout << task.toString() << "\n" << std::endl;
                        }
                    }
                    break;
                }
                case 0:
                    std::cout << "Saliendo del programa. ¡Hasta pronto!" << std::endl;
                    break;
                default:
                    std::cout << "Opción inválida. Por favor intente de nuevo." << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        
    } while (option != 0);
    
    return 0;
}