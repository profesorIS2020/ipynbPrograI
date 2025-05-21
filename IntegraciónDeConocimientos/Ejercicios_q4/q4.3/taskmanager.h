// taskmanager.h
// Este archivo contiene las declaraciones de la clase TaskManager y sus funciones

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <stack>
#include <queue>

// Estructura para representar una tarea
struct Task {
    std::string title;
    std::string description;
    bool isPriority;
    
    // Constructor para facilitar la creación de tareas
    Task(const std::string& t, const std::string& d, bool p) 
        : title(t), description(d), isPriority(p) {}
};

// Clase TaskManager que gestiona las tareas usando una pila y una cola
class TaskManager {
private:
    std::stack<Task> priorityTasks;    // Pila para tareas prioritarias
    std::queue<Task> regularTasks;     // Cola para tareas regulares

public:
    // Constructor y destructor
    TaskManager();
    ~TaskManager();
    
    // Funciones para añadir tareas
    void addTask(const std::string& title, const std::string& description, bool isPriority);
    
    // Funciones para procesar tareas
    bool processPriorityTask();
    bool processRegularTask();
    
    // Funciones para mostrar tareas
    void displayPriorityTasks() const;
    void displayRegularTasks() const;
    
    // Funciones para obtener información sobre tareas
    int getPriorityTaskCount() const;
    int getRegularTaskCount() const;
    bool hasPriorityTasks() const;
    bool hasRegularTasks() const;
    
    // Menú principal del gestor de tareas
    void showMenu();
};

#endif // TASKMANAGER_H