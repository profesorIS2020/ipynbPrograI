#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <fstream>

// Enumeración para prioridad de tareas
enum class Priority {
    LOW,
    MEDIUM,
    HIGH,
    URGENT
};

// Enumeración para el estado de las tareas
enum class Status {
    PENDING,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
};

// Estructura para representar una fecha
struct Date {
    int day;
    int month;
    int year;
    
    // Constructor por defecto
    Date() : day(1), month(1), year(2025) {}
    
    // Constructor con parámetros
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        // Validación básica de fecha
        if (d < 1 || d > 31 || m < 1 || m > 12 || y < 2000) {
            throw std::invalid_argument("Fecha inválida");
        }
    }
    
    // Método para convertir a string
    std::string toString() const {
        return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    }
};

// Clase para las tareas
class Task {
private:
    int id;
    std::string title;
    std::string description;
    Date dueDate;
    Priority priority;
    Status status;

public:
    // Constructor
    Task(int taskId, const std::string& taskTitle, const std::string& taskDesc = "", 
         const Date& taskDueDate = Date(), Priority taskPriority = Priority::MEDIUM, 
         Status taskStatus = Status::PENDING);
    
    // Getters
    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const Date& getDueDate() const;
    Priority getPriority() const;
    Status getStatus() const;
    
    // Setters
    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDesc);
    void setDueDate(const Date& newDate);
    void setPriority(Priority newPriority);
    void setStatus(Status newStatus);
    
    // Métodos para convertir enumeraciones a string
    static std::string priorityToString(Priority p);
    static std::string statusToString(Status s);
    
    // Método para mostrar la tarea
    std::string toString() const;
};

// Clase principal para gestionar las tareas
class TaskManager {
private:
    std::vector<std::unique_ptr<Task>> tasks;  // Vector de punteros únicos a tareas
    int nextTaskId;  // Para generar IDs únicos
    
    // Método privado para encontrar una tarea por ID
    std::vector<std::unique_ptr<Task>>::iterator findTaskById(int id);
    
public:
    // Constructor
    TaskManager();
    
    // Método simple: Añadir una tarea básica
    void addTask(const std::string& title);
    
    // Método intermedio: Añadir una tarea con más detalles
    void addDetailedTask(const std::string& title, const std::string& description, 
                         const Date& dueDate, Priority priority);
    
    // Método avanzado: Añadir una tarea utilizando referencias y con validación
    void addTaskWithValidation(const std::string& title, const std::string& description, 
                               const Date& dueDate, Priority priority, Status status);
    
    // Métodos simples
    void displayAllTasks() const;
    bool removeTask(int id);
    bool markTaskAsCompleted(int id);
    
    // Métodos intermedios
    Task* getTaskById(int id) const;  // Retorna un puntero a tarea
    void updateTaskStatus(int id, Status newStatus);
    std::vector<Task*> getTasksByStatus(Status status) const;
    
    // Métodos avanzados
    void sortTasksByPriority();
    void filterTasksByDueDate(const Date& date, std::vector<const Task*>& result) const;
    void saveTasks(const std::string& filename) const;
    void loadTasks(const std::string& filename);
    
    // Método complejo que utiliza punteros, referencias y manejo de excepciones
    template<typename Predicate>
    std::vector<std::reference_wrapper<const Task>> findTasksIf(Predicate pred) const {
        std::vector<std::reference_wrapper<const Task>> result;
        
        for (const auto& taskPtr : tasks) {
            if (pred(*taskPtr)) {
                result.push_back(std::cref(*taskPtr));
            }
        }
        
        return result;
    }
};

#endif // TASK_MANAGER_H