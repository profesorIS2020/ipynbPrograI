#include <iostream>
#include <string>
#include <limits>
#include "grades.h"

// Función para limpiar el buffer de entrada
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Función para mostrar el menú principal
void displayMenu() {
    std::cout << "\n=== SISTEMA DE GESTIÓN DE CALIFICACIONES ===" << std::endl;
    std::cout << "1. Agregar calificación a la pila y cola" << std::endl;
    std::cout << "2. Ver última calificación ingresada (pila)" << std::endl;
    std::cout << "3. Eliminar última calificación ingresada (pila)" << std::endl;
    std::cout << "4. Mostrar todas las calificaciones recientes (pila)" << std::endl;
    std::cout << "5. Ver siguiente calificación por procesar (cola)" << std::endl;
    std::cout << "6. Procesar siguiente calificación (cola)" << std::endl;
    std::cout << "7. Mostrar todas las calificaciones en cola" << std::endl;
    std::cout << "8. Calcular promedio de calificaciones en cola" << std::endl;
    std::cout << "9. Limpiar todos los datos" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main() {
    GradeManager gradeManager;
    int option;
    bool running = true;
    
    std::cout << "Bienvenido al Sistema de Gestión de Calificaciones" << std::endl;
    
    while (running) {
        displayMenu();
        
        // Verificar que la entrada sea un número
        if (!(std::cin >> option)) {
            std::cout << "Error: Ingrese un número válido." << std::endl;
            clearInputBuffer();
            continue;
        }
        
        // Limpiar el buffer después de leer la opción
        clearInputBuffer();
        
        switch (option) {
            case 1: {
                // Agregar calificación a la pila y cola
                Student student;
                std::cout << "Ingrese el nombre del estudiante: ";
                std::getline(std::cin, student.name);
                
                std::cout << "Ingrese la calificación: ";
                while (!(std::cin >> student.grade) || student.grade < 0 || student.grade > 10) {
                    std::cout << "Error: Ingrese una calificación válida (0-10): ";
                    clearInputBuffer();
                }
                clearInputBuffer();
                
                // Agregar a ambas estructuras
                gradeManager.addGradeToStack(student);
                gradeManager.addGradeToQueue(student);
                
                std::cout << "Calificación agregada correctamente." << std::endl;
                break;
            }
            
            case 2: {
                // Ver última calificación ingresada (pila)
                if (gradeManager.isStackEmpty()) {
                    std::cout << "No hay calificaciones en la pila." << std::endl;
                } else {
                    Student lastStudent = gradeManager.viewLastGrade();
                    std::cout << "Última calificación ingresada:" << std::endl;
                    std::cout << "Nombre: " << lastStudent.name << ", Calificación: " << lastStudent.grade << std::endl;
                }
                break;
            }
            
            case 3: {
                // Eliminar última calificación ingresada (pila)
                if (gradeManager.isStackEmpty()) {
                    std::cout << "No hay calificaciones en la pila para eliminar." << std::endl;
                } else {
                    gradeManager.removeLastGrade();
                    std::cout << "Última calificación eliminada de la pila." << std::endl;
                }
                break;
            }
            
            case 4: {
                // Mostrar todas las calificaciones recientes (pila)
                gradeManager.displayStack();
                break;
            }
            
            case 5: {
                // Ver siguiente calificación por procesar (cola)
                if (gradeManager.isQueueEmpty()) {
                    std::cout << "No hay calificaciones en la cola." << std::endl;
                } else {
                    Student nextStudent = gradeManager.viewNextGrade();
                    std::cout << "Siguiente calificación en cola:" << std::endl;
                    std::cout << "Nombre: " << nextStudent.name << ", Calificación: " << nextStudent.grade << std::endl;
                }
                break;
            }
            
            case 6: {
                // Procesar siguiente calificación (cola)
                if (gradeManager.isQueueEmpty()) {
                    std::cout << "No hay calificaciones en la cola para procesar." << std::endl;
                } else {
                    Student nextStudent = gradeManager.viewNextGrade();
                    gradeManager.processNextGrade();
                    std::cout << "Calificación de " << nextStudent.name << " procesada y eliminada de la cola." << std::endl;
                }
                break;
            }
            
            case 7: {
                // Mostrar todas las calificaciones en cola
                gradeManager.displayQueue();
                break;
            }
            
            case 8: {
                // Calcular promedio de calificaciones en cola
                if (gradeManager.isQueueEmpty()) {
                    std::cout << "No hay calificaciones en la cola para calcular el promedio." << std::endl;
                } else {
                    double average = gradeManager.calculateAverageGrade();
                    std::cout << "El promedio de calificaciones en cola es: " << average << std::endl;
                }
                break;
            }
            
            case 9: {
                // Limpiar todos los datos
                gradeManager.clearAllData();
                std::cout << "Todos los datos han sido eliminados." << std::endl;
                break;
            }
            
            case 0: {
                // Salir
                std::cout << "Gracias por usar el Sistema de Gestión de Calificaciones." << std::endl;
                running = false;
                break;
            }
            
            default: {
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
            }
        }
    }
    
    return 0;
}