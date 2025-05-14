#include "grades.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cmath> // for std::abs

// Constructor de Asignatura
Asignatura::Asignatura(std::string _nombre) : nombre(_nombre), numCalificaciones(0) {
    calificaciones.fill(0.0);
}

// Método para agregar una calificación a una asignatura
void Asignatura::agregarCalificacion(double calificacion) {
    if (numCalificaciones >= MAX_CALIFICACIONES) {
        throw CalificacionesException("Error: Número máximo de calificaciones alcanzado para esta asignatura");
    }

    if (calificacion < 0.0 || calificacion > 10.0) {
        throw CalificacionesException("Error: La calificación debe estar entre 0 y 10");
    }

    calificaciones[numCalificaciones++] = calificacion;
}

// Método para calcular el promedio de calificaciones de una asignatura
double Asignatura::calcularPromedio() const {
    if (numCalificaciones == 0) return 0.0;

    double suma = 0.0;
    for (int i = 0; i < numCalificaciones; ++i)
        suma += calificaciones[i];

    return suma / numCalificaciones;
}

// Método para obtener la calificación más alta
double Asignatura::obtenerCalificacionMasAlta() const {
    if (numCalificaciones == 0) return 0.0;

    double maxCal = calificaciones[0];
    for (int i = 1; i < numCalificaciones; ++i)
        if (calificaciones[i] > maxCal)
            maxCal = calificaciones[i];

    return maxCal;
}

// Método para obtener la calificación más baja
double Asignatura::obtenerCalificacionMasBaja() const {
    if (numCalificaciones == 0) return 0.0;

    double minCal = calificaciones[0];
    for (int i = 1; i < numCalificaciones; ++i)
        if (calificaciones[i] < minCal)
            minCal = calificaciones[i];

    return minCal;
}

// Constructor del sistema
SistemaCalificaciones::SistemaCalificaciones() : numEstudiantes(0) {
    numAsignaturasPorEstudiante.fill(0);
}

// Agrega un estudiante
void SistemaCalificaciones::agregarEstudiante(const Estudiante& estudiante) {
    if (numEstudiantes >= MAX_ESTUDIANTES)
        throw CalificacionesException("Error: Número máximo de estudiantes alcanzado");

    for (int i = 0; i < numEstudiantes; ++i)
        if (estudiantes[i].id == estudiante.id && estudiante.id != 0)
            throw CalificacionesException("Error: Ya existe un estudiante con el ID " + std::to_string(estudiante.id));

    estudiantes[numEstudiantes] = estudiante;
    numAsignaturasPorEstudiante[numEstudiantes] = 0;
    ++numEstudiantes;

    std::cout << "Estudiante " << estudiante.nombre << " " << estudiante.apellido << " agregado con éxito." << std::endl;
}

// Elimina un estudiante
void SistemaCalificaciones::eliminarEstudiante(int idEstudiante) {
    int idx = buscarIndiceEstudiante(idEstudiante);
    std::string nombre = estudiantes[idx].nombre + " " + estudiantes[idx].apellido;

    for (int i = idx; i < numEstudiantes - 1; ++i) {
        estudiantes[i] = estudiantes[i + 1];
        asignaturasEstudiantes[i] = asignaturasEstudiantes[i + 1];
        numAsignaturasPorEstudiante[i] = numAsignaturasPorEstudiante[i + 1];
    }

    --numEstudiantes;
    std::cout << "Estudiante " << nombre << " eliminado con éxito." << std::endl;
}

// Buscar estudiante por ID
Estudiante SistemaCalificaciones::buscarEstudiante(int id) const {
    for (int i = 0; i < numEstudiantes; ++i)
        if (estudiantes[i].id == id)
            return estudiantes[i];

    throw CalificacionesException("Error: No se encontró un estudiante con el ID " + std::to_string(id));
}

// Buscar índice del estudiante
int SistemaCalificaciones::buscarIndiceEstudiante(int id) const {
    for (int i = 0; i < numEstudiantes; ++i)
        if (estudiantes[i].id == id)
            return i;

    throw CalificacionesException("Error: No se encontró un estudiante con el ID " + std::to_string(id));
}

// Agregar asignatura a un estudiante
void SistemaCalificaciones::agregarAsignatura(int idEstudiante, const std::string& nombreAsignatura) {
    int idx = buscarIndiceEstudiante(idEstudiante);

    if (numAsignaturasPorEstudiante[idx] >= MAX_ASIGNATURAS)
        throw CalificacionesException("Error: Número máximo de asignaturas alcanzado");

    for (int i = 0; i < numAsignaturasPorEstudiante[idx]; ++i)
        if (asignaturasEstudiantes[idx][i].nombre == nombreAsignatura)
            throw CalificacionesException("Error: La asignatura ya existe para este estudiante");

    asignaturasEstudiantes[idx][numAsignaturasPorEstudiante[idx]++] = Asignatura(nombreAsignatura);

    std::cout << "Asignatura " << nombreAsignatura << " agregada al estudiante " << estudiantes[idx].nombre << " " << estudiantes[idx].apellido << std::endl;
}

// Agregar calificación a una asignatura de un estudiante
void SistemaCalificaciones::agregarCalificacion(int idEstudiante, const std::string& nombreAsignatura, double calificacion) {
    int idx = buscarIndiceEstudiante(idEstudiante);
    int iAsig = -1;

    for (int i = 0; i < numAsignaturasPorEstudiante[idx]; ++i) {
        if (asignaturasEstudiantes[idx][i].nombre == nombreAsignatura) {
            iAsig = i;
            break;
        }
    }

    if (iAsig == -1)
        throw CalificacionesException("Error: No se encontró la asignatura " + nombreAsignatura + " para el estudiante con ID " + std::to_string(idEstudiante));

    asignaturasEstudiantes[idx][iAsig].agregarCalificacion(calificacion);

    std::cout << "Calificación " << calificacion << " agregada a " << nombreAsignatura << " de " << estudiantes[idx].nombre << " " << estudiantes[idx].apellido << std::endl;
}

// Mostrar calificaciones de un estudiante
void SistemaCalificaciones::mostrarCalificacionesEstudiante(int idEstudiante) const {
    int idx = buscarIndiceEstudiante(idEstudiante);
    const Estudiante& est = estudiantes[idx];

    std::cout << "\n=== CALIFICACIONES DE " << est.nombre << " " << est.apellido << " ===" << std::endl;

    for (int i = 0; i < numAsignaturasPorEstudiante[idx]; ++i) {
        const Asignatura& a = asignaturasEstudiantes[idx][i];
        std::cout << "Asignatura: " << a.nombre << "\n  Calificaciones: ";

        if (a.numCalificaciones == 0) {
            std::cout << "Sin calificaciones.\n";
        } else {
            for (int j = 0; j < a.numCalificaciones; ++j) {
                std::cout << a.calificaciones[j];
                if (j < a.numCalificaciones - 1) std::cout << ", ";
            }

            std::cout << "\n  Promedio: " << std::fixed << std::setprecision(2) << a.calcularPromedio()
                      << "\n  Más alta: " << a.obtenerCalificacionMasAlta()
                      << "\n  Más baja: " << a.obtenerCalificacionMasBaja() << "\n";
        }
        std::cout << std::endl;
    }
}

// Mostrar promedio general de un estudiante
void SistemaCalificaciones::mostrarPromedioGeneral(int idEstudiante) const {
    int idx = buscarIndiceEstudiante(idEstudiante);

    double suma = 0.0;
    int n = 0;

    for (int i = 0; i < numAsignaturasPorEstudiante[idx]; ++i) {
        const Asignatura& a = asignaturasEstudiantes[idx][i];
        if (a.numCalificaciones > 0) {
            suma += a.calcularPromedio();
            ++n;
        }
    }

    if (n == 0) {
        std::cout << "El estudiante no tiene calificaciones.\n";
    } else {
        std::cout << "Promedio general de " << estudiantes[idx].nombre << " " << estudiantes[idx].apellido
                  << ": " << std::fixed << std::setprecision(2) << (suma / n) << std::endl;
    }
}

// Mostrar mejores estudiantes
void SistemaCalificaciones::mostrarMejoresEstudiantes() const {
    if (numEstudiantes == 0) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    std::array<double, MAX_ESTUDIANTES> promedios{};
    std::array<bool, MAX_ESTUDIANTES> tieneCalificaciones{};

    double maxPromedio = -1.0;

    for (int i = 0; i < numEstudiantes; ++i) {
        double suma = 0.0;
        int n = 0;
        for (int j = 0; j < numAsignaturasPorEstudiante[i]; ++j) {
            const Asignatura& a = asignaturasEstudiantes[i][j];
            if (a.numCalificaciones > 0) {
                suma += a.calcularPromedio();
                ++n;
            }
        }
        if (n > 0) {
            double promedio = suma / n;
            promedios[i] = promedio;
            tieneCalificaciones[i] = true;
            if (promedio > maxPromedio) maxPromedio = promedio;
        }
    }

    if (maxPromedio < 0) {
        std::cout << "Ningún estudiante tiene calificaciones.\n";
        return;
    }

    std::cout << "=== MEJORES ESTUDIANTES (Promedio: " << std::fixed << std::setprecision(2) << maxPromedio << ") ===\n";
    for (int i = 0; i < numEstudiantes; ++i) {
        if (tieneCalificaciones[i] && std::abs(promedios[i] - maxPromedio) < 0.001) {
            std::cout << estudiantes[i].nombre << " " << estudiantes[i].apellido << std::endl;
        }
    }
}

// Mostrar todos los estudiantes
void SistemaCalificaciones::mostrarTodosLosEstudiantes() const {
    std::cout << "\n=== LISTA DE ESTUDIANTES ===\n";
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(20) << "Nombre"
              << std::setw(20) << "Apellido"
              << "Asignaturas\n"
              << std::string(60, '-') << std::endl;

    for (int i = 0; i < numEstudiantes; ++i) {
        std::cout << std::left << std::setw(5) << estudiantes[i].id
                  << std::setw(20) << estudiantes[i].nombre
                  << std::setw(20) << estudiantes[i].apellido
                  << numAsignaturasPorEstudiante[i] << std::endl;
    }
}
