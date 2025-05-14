#include <iostream>
#include <iomanip>
#include "grades.h"
/*g++ -std=c++11 grades.cpp main.cpp -o grades*/
int main() {
    try {
        SistemaCalificaciones sistema;

        // Agregar estudiantes
        sistema.agregarEstudiante(Estudiante(1, "Juan", "Pérez"));
        sistema.agregarEstudiante(Estudiante(2, "María", "González"));
        sistema.agregarEstudiante(Estudiante(3, "Carlos", "Rodríguez"));

        std::cout << "\nListado de estudiantes:" << std::endl;
        sistema.mostrarTodosLosEstudiantes();

        std::cout << "\nAgregando asignaturas:" << std::endl;
        sistema.agregarAsignatura(1, "Matemáticas");
        sistema.agregarAsignatura(1, "Física");
        sistema.agregarAsignatura(1, "Programación");

        sistema.agregarAsignatura(2, "Matemáticas");
        sistema.agregarAsignatura(2, "Literatura");

        sistema.agregarAsignatura(3, "Matemáticas");
        sistema.agregarAsignatura(3, "Historia");
        sistema.agregarAsignatura(3, "Inglés");

        std::cout << "\nAgregando calificaciones:" << std::endl;
        sistema.agregarCalificacion(1, "Matemáticas", 8.5);
        sistema.agregarCalificacion(1, "Matemáticas", 7.0);
        sistema.agregarCalificacion(1, "Física", 9.0);
        sistema.agregarCalificacion(1, "Programación", 10.0);

        sistema.agregarCalificacion(2, "Matemáticas", 9.5);
        sistema.agregarCalificacion(2, "Matemáticas", 9.0);
        sistema.agregarCalificacion(2, "Literatura", 8.0);
        sistema.agregarCalificacion(2, "Literatura", 8.5);

        sistema.agregarCalificacion(3, "Matemáticas", 7.0);
        sistema.agregarCalificacion(3, "Historia", 8.0);
        sistema.agregarCalificacion(3, "Inglés", 9.5);

        std::cout << "\nCalificaciones detalladas de Juan:" << std::endl;
        sistema.mostrarCalificacionesEstudiante(1);

        std::cout << "\nPromedios generales:" << std::endl;
        sistema.mostrarPromedioGeneral(1);
        sistema.mostrarPromedioGeneral(2);
        sistema.mostrarPromedioGeneral(3);

        std::cout << "\nMejores estudiantes:" << std::endl;
        sistema.mostrarMejoresEstudiantes();

        std::cout << "\nIntentando agregar calificación inválida:" << std::endl;
        try {
            sistema.agregarCalificacion(1, "Matemáticas", 11.0); // Inválida
        } catch (const CalificacionesException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }

        std::cout << "\nIntentando agregar asignatura duplicada:" << std::endl;
        try {
            sistema.agregarAsignatura(1, "Matemáticas");
        } catch (const CalificacionesException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }

        std::cout << "\nEliminando estudiante con ID 3:" << std::endl;
        sistema.eliminarEstudiante(3);

        std::cout << "\nListado actualizado de estudiantes:" << std::endl;
        sistema.mostrarTodosLosEstudiantes();

        std::cout << "\nBuscando estudiante eliminado:" << std::endl;
        try {
            Estudiante est = sistema.buscarEstudiante(3);
            std::cout << "Estudiante encontrado: " << est.nombre << " " << est.apellido << std::endl;
        } catch (const CalificacionesException& e) {
            std::cerr << "Error controlado: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error general: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
