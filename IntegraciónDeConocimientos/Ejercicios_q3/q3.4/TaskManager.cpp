#include "TaskManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

// Implementación de la clase Task
Task::Task(int taskId, const std::string& taskTitle, const std::string& taskDesc,
           const Date& taskDueDate, Priority taskPriority, Status taskStatus)
    : id(taskId), title(taskTitle), description(taskDesc), 
      dueDate(taskDueDate), priority(taskPriority), status(taskStatus) {
    
    // Validación del título
    if (title.empty()) {
        throw std::invalid_argument("El título de la tarea no puede estar vacío");
    }
}

// Getters
int Task::getId() const { 
    return id; 
}

const std::string& Task::getTitle() const { 
    return title; 
}

const std::string& Task::getDescription() const { 
    return description; 
}

const Date& Task::getDueDate() const { 
    return dueDate; 
}

Priority Task::getPriority() const { 
    return priority; 
}

Status Task::getStatus() const { 
    return status; 
}

// Setters
void Task::setTitle(const std::string& newTitle) {
    if (newTitle.empty()) {
        throw std::invalid_argument("El título de la tarea no puede estar vacío");
    }
    title = newTitle;
}

void Task::setDescription(const std::string& newDesc) {
    description = newDesc;
}

void Task::setDueDate(const Date& newDate) {
    dueDate = newDate;
}

void Task::setPriority(Priority newPriority) {
    priority = newPriority;
}

void Task::setStatus(Status newStatus) {
    status = newStatus;
}

// Métodos para convertir enumeraciones a string
std::string Task::priorityToString(Priority p) {
    switch (p) {
        case Priority::LOW: return "Baja";
        case Priority::MEDIUM: return "Media";
        case Priority::HIGH: return "Alta";
        case Priority::URGENT: return "Urgente";
        default: return "Desconocida";
    }
}

std::string Task::statusToString(Status s) {
    switch (s) {
        case Status::PENDING: return "Pendiente";
        case Status::IN_PROGRESS: return "En progreso";
        case Status::COMPLETED: return "Completada";
        case Status::CANCELLED: return "Cancelada";
        default: return "Desconocido";
    }
}

// Método para mostrar la tarea
std::string Task::toString() const {
    std::stringstream ss;
    ss << "ID: " << id << "\n"
       << "Título: " << title << "\n";
    
    if (!description.empty()) {
        ss << "Descripción: " << description << "\n";
    }
    
    ss << "Fecha límite: " << dueDate.toString() << "\n"
       << "Prioridad: " << priorityToString(priority) << "\n"
       << "Estado: " << statusToString(status);
    
    return ss.str();
}

// Implementación de la clase TaskManager
TaskManager::TaskManager() : nextTaskId(1) {}

std::vector<std::unique_ptr<Task>>::iterator TaskManager::findTaskById(int id) {
    return std::find_if(tasks.begin(), tasks.end(), 
                       [id](const std::unique_ptr<Task>& task) {
                           return task->getId() == id;
                       });
}

// Método simple: Añadir una tarea básica
void TaskManager::addTask(const std::string& title) {
    try {
        // Creamos una nueva tarea con valores por defecto
        auto newTask = std::make_unique<Task>(nextTaskId, title);
        tasks.push_back(std::move(newTask));  // Transferimos la propiedad al vector
        nextTaskId++;
    } catch (const std::exception& e) {
        std::cerr << "Error al crear la tarea: " << e.what() << std::endl;
        throw;  // Relanzamos la excepción para que sea manejada por el llamador
    }
}

// Método intermedio: Añadir una tarea con más detalles
void TaskManager::addDetailedTask(const std::string& title, const std::string& description, 
                           const Date& dueDate, Priority priority) {
    try {
        // Usamos new para demostrar el uso de punteros raw (que luego convertimos a unique_ptr)
        Task* taskPtr = new Task(nextTaskId, title, description, dueDate, priority);
        tasks.push_back(std::unique_ptr<Task>(taskPtr));  // Convertimos el puntero raw a unique_ptr
        nextTaskId++;
    } catch (const std::exception& e) {
        std::cerr << "Error al crear la tarea detallada: " << e.what() << std::endl;
        throw;
    }
}

// Método avanzado: Añadir una tarea utilizando referencias y con validación
void TaskManager::addTaskWithValidation(const std::string& title, const std::string& description, 
                             const Date& dueDate, Priority priority, Status status) {
    try {
        // Validaciones adicionales
        if (title.length() < 3) {
            throw std::invalid_argument("El título debe tener al menos 3 caracteres");
        }
        
        // Verificamos que la fecha no sea pasada (ejemplo sencillo)
        Date today;  // Asumiendo que el constructor por defecto da la fecha actual
        if (dueDate.year < today.year || 
            (dueDate.year == today.year && dueDate.month < today.month) ||
            (dueDate.year == today.year && dueDate.month == today.month && dueDate.day < today.day)) {
            throw std::invalid_argument("La fecha límite no puede ser en el pasado");
        }
        
        // Creamos y añadimos la tarea
        tasks.push_back(std::make_unique<Task>(nextTaskId, title, description, dueDate, priority, status));
        nextTaskId++;
    } catch (const std::exception& e) {
        std::cerr << "Error en la validación de la tarea: " << e.what() << std::endl;
        throw;  // Relanzamos para manejo en el nivel superior
    }
}

// Método simple para mostrar todas las tareas
void TaskManager::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "No hay tareas registradas." << std::endl;
        return;
    }
    
    std::cout << "=== LISTA DE TAREAS ===" << std::endl;
    for (const auto& task : tasks) {
        // Usamos el operador de dereferencia para acceder al objeto Task
        std::cout << task->toString() << "\n" << std::endl;
    }
}

// Método simple para eliminar una tarea
bool TaskManager::removeTask(int id) {
    auto it = findTaskById(id);
    if (it != tasks.end()) {
        tasks.erase(it);  // Esto liberará automáticamente la memoria (unique_ptr)
        return true;
    }
    return false;
}

// Método simple para marcar una tarea como completada
bool TaskManager::markTaskAsCompleted(int id) {
    auto it = findTaskById(id);
    if (it != tasks.end()) {
        (*it)->setStatus(Status::COMPLETED);
        return true;
    }
    return false;
}

// Método intermedio para obtener una tarea por ID
Task* TaskManager::getTaskById(int id) const {
    for (const auto& task : tasks) {
        if (task->getId() == id) {
            return task.get();  // Devolvemos un puntero raw (no transfiere propiedad)
        }
    }
    return nullptr;  // Retorna nullptr si no se encuentra
}

// Método intermedio para actualizar el estado de una tarea
void TaskManager::updateTaskStatus(int id, Status newStatus) {
    Task* task = getTaskById(id);
    if (task == nullptr) {
        throw std::runtime_error("Tarea no encontrada con ID: " + std::to_string(id));
    }
    task->setStatus(newStatus);
}

// Método intermedio para obtener tareas por estado
std::vector<Task*> TaskManager::getTasksByStatus(Status status) const {
    std::vector<Task*> result;
    for (const auto& task : tasks) {
        if (task->getStatus() == status) {
            result.push_back(task.get());  // Guardamos punteros raw a las tareas
        }
    }
    return result;
}

// Método avanzado para ordenar tareas por prioridad
void TaskManager::sortTasksByPriority() {
    // Ordenamos el vector usando una expresión lambda
    std::sort(tasks.begin(), tasks.end(), 
              [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b) {
                  // Ordenamos de mayor a menor prioridad
                  return static_cast<int>(a->getPriority()) > static_cast<int>(b->getPriority());
              });
}

// Método avanzado para filtrar tareas por fecha de vencimiento
void TaskManager::filterTasksByDueDate(const Date& date, std::vector<const Task*>& result) const {
    result.clear();  // Limpiamos el vector de resultados
    
    // Usamos referencias para evitar copias innecesarias
    for (const auto& task : tasks) {
        const Date& taskDate = task->getDueDate();
        
        if (taskDate.year == date.year && 
            taskDate.month == date.month && 
            taskDate.day == date.day) {
            result.push_back(task.get());
        }
    }
}

// Método avanzado para guardar tareas en un archivo
void TaskManager::saveTasks(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura: " + filename);
    }
    
    for (const auto& task : tasks) {
        file << task->getId() << "|"
             << task->getTitle() << "|"
             << task->getDescription() << "|"
             << task->getDueDate().day << "|"
             << task->getDueDate().month << "|"
             << task->getDueDate().year << "|"
             << static_cast<int>(task->getPriority()) << "|"
             << static_cast<int>(task->getStatus()) << std::endl;
    }
    
    file.close();
}

// Método avanzado para cargar tareas desde un archivo
void TaskManager::loadTasks(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para lectura: " + filename);
    }
    
    // Limpiamos las tareas existentes
    tasks.clear();
    nextTaskId = 1;
    
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        
        while (std::getline(ss, token, '|')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() != 8) {
            continue;  // Línea inválida, pasamos a la siguiente
        }
        
        try {
            int id = std::stoi(tokens[0]);
            std::string title = tokens[1];
            std::string desc = tokens[2];
            int day = std::stoi(tokens[3]);
            int month = std::stoi(tokens[4]);
            int year = std::stoi(tokens[5]);
            Priority priority = static_cast<Priority>(std::stoi(tokens[6]));
            Status status = static_cast<Status>(std::stoi(tokens[7]));
            
            Date dueDate(day, month, year);
            
            auto task = std::make_unique<Task>(id, title, desc, dueDate, priority, status);
            tasks.push_back(std::move(task));
            
            // Actualizamos nextTaskId para que sea mayor que cualquier ID cargado
            if (id >= nextTaskId) {
                nextTaskId = id + 1;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error al cargar tarea: " << e.what() << std::endl;
            // Continuamos con la siguiente línea
        }
    }
    
    file.close();
}