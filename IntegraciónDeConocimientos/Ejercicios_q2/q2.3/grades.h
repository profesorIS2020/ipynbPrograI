#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <array>
#include <stdexcept>

// Clase personalizada de excepción
class CalificacionesException : public std::runtime_error {
public:
    CalificacionesException(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

// Estructura para representar una asignatura con calificaciones
struct Asignatura {
    std::string nombre;
    static const int MAX_CALIFICACIONES = 5;
    std::array<double, MAX_CALIFICACIONES> calificaciones;
    int numCalificaciones;

    Asignatura(std::string _nombre = "");

    void agregarCalificacion(double calificacion);
    double calcularPromedio() const;
    double obtenerCalificacionMasAlta() const;
    double obtenerCalificacionMasBaja() const;
};

// Estructura para representar un estudiante
struct Estudiante {
    int id;
    std::string nombre;
    std::string apellido;

    Estudiante(int _id = 0, std::string _nombre = "", std::string _apellido = "")
        : id(_id), nombre(_nombre), apellido(_apellido) {}
};

// Clase principal del sistema de calificaciones
class SistemaCalificaciones {
private:
    static const int MAX_ESTUDIANTES = 50;
    static const int MAX_ASIGNATURAS = 10;

    std::array<Estudiante, MAX_ESTUDIANTES> estudiantes;
    int numEstudiantes;

    std::array<std::array<Asignatura, MAX_ASIGNATURAS>, MAX_ESTUDIANTES> asignaturasEstudiantes;
    std::array<int, MAX_ESTUDIANTES> numAsignaturasPorEstudiante;

public:
    SistemaCalificaciones();

    // Estudiantes
    void agregarEstudiante(const Estudiante& estudiante);
    void eliminarEstudiante(int idEstudiante);
    Estudiante buscarEstudiante(int idEstudiante) const;
    int buscarIndiceEstudiante(int idEstudiante) const;

    // Asignaturas y calificaciones
    void agregarAsignatura(int idEstudiante, const std::string& nombreAsignatura);
    void agregarCalificacion(int idEstudiante, const std::string& nombreAsignatura, double calificacion);

    // Consultas
    void mostrarCalificacionesEstudiante(int idEstudiante) const;
    void mostrarPromedioGeneral(int idEstudiante) const;
    void mostrarMejoresEstudiantes() const;
    void mostrarTodosLosEstudiantes() const;
};

#endif // GRADES_H
