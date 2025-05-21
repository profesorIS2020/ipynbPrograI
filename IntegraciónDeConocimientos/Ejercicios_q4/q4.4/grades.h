#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <stack>
#include <queue>

// Estructura para representar un estudiante y su calificación
struct Student {
    std::string name;
    double grade;
};

class GradeManager {
private:
    std::stack<Student> recentGrades;  // Pila para las calificaciones más recientes
    std::queue<Student> gradeQueue;    // Cola para procesar calificaciones en orden de llegada
    
public:
    // Constructor
    GradeManager();
    
    // Métodos para la pila (stack)
    void addGradeToStack(const Student& student);
    void removeLastGrade();
    Student viewLastGrade() const;
    bool isStackEmpty() const;
    int getStackSize() const;
    void displayStack() const;
    
    // Métodos para la cola (queue)
    void addGradeToQueue(const Student& student);
    void processNextGrade();
    Student viewNextGrade() const;
    bool isQueueEmpty() const;
    int getQueueSize() const;
    void displayQueue() const;
    
    // Estadísticas y operaciones adicionales
    double calculateAverageGrade() const;
    void clearAllData();
};

#endif // GRADES_H