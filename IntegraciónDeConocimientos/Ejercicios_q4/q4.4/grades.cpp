#include "grades.h"
#include <iostream>
#include <iomanip>

// Constructor
GradeManager::GradeManager() {
    // No es necesario inicializar la pila y la cola, ya están vacías por defecto
}

// Métodos para la pila (stack)
void GradeManager::addGradeToStack(const Student& student) {
    recentGrades.push(student);
}

void GradeManager::removeLastGrade() {
    if (!recentGrades.empty()) {
        recentGrades.pop();
    }
}

Student GradeManager::viewLastGrade() const {
    if (!recentGrades.empty()) {
        return recentGrades.top();
    }
    // Retornar un estudiante vacío si la pila está vacía
    return {"Sin datos", 0.0};
}

bool GradeManager::isStackEmpty() const {
    return recentGrades.empty();
}

int GradeManager::getStackSize() const {
    return recentGrades.size();
}

void GradeManager::displayStack() const {
    if (recentGrades.empty()) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }
    
    // Para mostrar la pila, necesitamos hacer una copia porque no podemos
    // recorrer directamente una pila sin modificarla
    std::stack<Student> tempStack = recentGrades;
    std::cout << "\n--- Calificaciones más recientes (pila) ---" << std::endl;
    std::cout << std::left << std::setw(20) << "Nombre" 
              << std::setw(10) << "Calificación" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    while (!tempStack.empty()) {
        Student student = tempStack.top();
        std::cout << std::left << std::setw(20) << student.name 
                  << std::setw(10) << student.grade << std::endl;
        tempStack.pop();
    }
    std::cout << "----------------------------------------" << std::endl;
}

// Métodos para la cola (queue)
void GradeManager::addGradeToQueue(const Student& student) {
    gradeQueue.push(student);
}

void GradeManager::processNextGrade() {
    if (!gradeQueue.empty()) {
        gradeQueue.pop();
    }
}

Student GradeManager::viewNextGrade() const {
    if (!gradeQueue.empty()) {
        return gradeQueue.front();
    }
    // Retornar un estudiante vacío si la cola está vacía
    return {"Sin datos", 0.0};
}

bool GradeManager::isQueueEmpty() const {
    return gradeQueue.empty();
}

int GradeManager::getQueueSize() const {
    return gradeQueue.size();
}

void GradeManager::displayQueue() const {
    if (gradeQueue.empty()) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }
    
    // Para mostrar la cola, necesitamos hacer una copia
    std::queue<Student> tempQueue = gradeQueue;
    std::cout << "\n--- Cola de calificaciones por procesar ---" << std::endl;
    std::cout << std::left << std::setw(20) << "Nombre" 
              << std::setw(10) << "Calificación" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    while (!tempQueue.empty()) {
        Student student = tempQueue.front();
        std::cout << std::left << std::setw(20) << student.name 
                  << std::setw(10) << student.grade << std::endl;
        tempQueue.pop();
    }
    std::cout << "----------------------------------------" << std::endl;
}

// Estadísticas y operaciones adicionales
double GradeManager::calculateAverageGrade() const {
    if (gradeQueue.empty()) {
        return 0.0;
    }
    
    double sum = 0.0;
    int count = 0;
    std::queue<Student> tempQueue = gradeQueue;
    
    while (!tempQueue.empty()) {
        sum += tempQueue.front().grade;
        count++;
        tempQueue.pop();
    }
    
    return sum / count;
}

void GradeManager::clearAllData() {
    // Limpiar la pila
    while (!recentGrades.empty()) {
        recentGrades.pop();
    }
    
    // Limpiar la cola
    while (!gradeQueue.empty()) {
        gradeQueue.pop();
    }
}