// taskmanager.cpp
// Este archivo contiene las implementaciones de las funciones de la clase TaskManager

#include "taskmanager.h"
#include <iostream>
#include <limits>

// Constructor
TaskManager::TaskManager() {
    // No hay inicialización especial necesaria (las pilas y colas ya se inicializan vacías)
}

// Destructor
TaskManager::~TaskManager() {
    // No hay operaciones especiales necesarias para la limpieza
}

// Añadir una nueva tarea
void TaskManager::addTask(const std::string& title, const std::string& description, bool isPriority) {
    Task newTask(title, description, isPriority);
    
    if (isPriority) {
        priorityTasks.push(newTask);
        std::cout << "Tarea prioritaria añadida.\n";
    } else {
        regularTasks.push(newTask);
        std::cout << "Tarea regular añadida.\n";
    }
}

// Procesar una tarea prioritaria (sacarla de la pila)
bool TaskManager::processPriorityTask() {
    if (priorityTasks.empty()) {
        std::cout << "No hay tareas prioritarias para procesar.\n";
        return false;
    }
    
    Task task = priorityTasks.top();
    priorityTasks.pop();
    
    std::cout << "Procesando tarea prioritaria: " << task.title << "\n";
    std::cout << "Descripción: " << task.description << "\n";
    std::cout << "Tarea completada y eliminada de la pila.\n";
    
    return true;
}

// Procesar una tarea regular (sacarla de la cola)
bool TaskManager::processRegularTask() {
    if (regularTasks.empty()) {
        std::cout << "No hay tareas regulares para procesar.\n";
        return false;
    }
    
    Task task = regularTasks.front();
    regularTasks.pop();
    
    std::cout << "Procesando tarea regular: " << task.title << "\n";
    std::cout << "Descripción: " << task.description << "\n";
    std::cout << "Tarea completada y eliminada de la cola.\n";
    
    return true;
}

// Mostrar todas las tareas prioritarias (sin modificar la pila)
void TaskManager::displayPriorityTasks() const {
    if (priorityTasks.empty()) {
        std::cout << "No hay tareas prioritarias.\n";
        return;
    }
    
    std::cout << "Tareas prioritarias (última añadida primero):\n";
    
    // Necesitamos crear una copia de la pila para mostrarla sin modificarla
    std::stack<Task> tempStack = priorityTasks;
    int count = 1;
    
    while (!tempStack.empty()) {
        Task task = tempStack.top();
        std::cout << count << ". " << task.title << " - " << task.description << "\n";
        tempStack.pop();
        count++;
    }
}

// Mostrar todas las tareas regulares (sin modificar la cola)
void TaskManager::displayRegularTasks() const {
    if (regularTasks.empty()) {
        std::cout << "No hay tareas regulares.\n";
        return;
    }
    
    std::cout << "Tareas regulares (primera añadida primero):\n";
    
    // Necesitamos crear una copia de la cola para mostrarla sin modificarla
    std::queue<Task> tempQueue = regularTasks;
    int count = 1;
    
    while (!tempQueue.empty()) {
        Task task = tempQueue.front();
        std::cout << count << ". " << task.title << " - " << task.description << "\n";
        tempQueue.pop();
        count++;
    }
}

// Obtener el número de tareas prioritarias
int TaskManager::getPriorityTaskCount() const {
    return priorityTasks.size();
}

// Obtener el número de tareas regulares
int TaskManager::getRegularTaskCount() const {
    return regularTasks.size();
}

// Verificar si hay tareas prioritarias
bool TaskManager::hasPriorityTasks() const {
    return !priorityTasks.empty();
}

// Verificar si hay tareas regulares
bool TaskManager::hasRegularTasks() const {
    return !regularTasks.empty();
}

// Menú principal del gestor de tareas
void TaskManager::showMenu() {
    int opcion;
    
    do {
        // Mostrar estadísticas actuales
        std::cout << "\n==== GESTOR DE TAREAS ====\n";
        std::cout << "Tareas prioritarias: " << getPriorityTaskCount() << "\n";
        std::cout << "Tareas regulares: " << getRegularTaskCount() << "\n";
        std::cout << "=========================\n\n";
        
        // Mostrar opciones
        std::cout << "1. Añadir nueva tarea\n";
        std::cout << "2. Procesar tarea prioritaria (PILA)\n";
        std::cout << "3. Procesar tarea regular (COLA)\n";
        std::cout << "4. Mostrar tareas prioritarias\n";
        std::cout << "5. Mostrar tareas regulares\n";
        std::cout << "0. Salir\n\n";
        
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        
        // Limpiar el buffer de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Procesar la opción seleccionada
        switch (opcion) {
            case 1: {
                std::string title, description;
                char tipo;
                
                std::cout << "Título de la tarea: ";
                std::getline(std::cin, title);
                
                std::cout << "Descripción: ";
                std::getline(std::cin, description);
                
                std::cout << "¿Es prioritaria? (s/n): ";
                std::cin >> tipo;
                
                bool isPriority = (tipo == 's' || tipo == 'S');
                addTask(title, description, isPriority);
                break;
            }
            case 2:
                processPriorityTask();
                break;
            case 3:
                processRegularTask();
                break;
            case 4:
                displayPriorityTasks();
                break;
            case 5:
                displayRegularTasks();
                break;
            case 0:
                std::cout << "¡Gracias por usar el gestor de tareas!\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
        
    } while (opcion != 0);
}