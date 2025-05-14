#ifndef Q2_H
#define Q2_H

#include <string>
#include <stdexcept>

// Definici¢n de excepciones personalizadas
class TareaException : public std::runtime_error {
public:
    TareaException(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

// Definici¢n de la estructura Tarea
struct Tarea {
    int id;
    std::string titulo;
    std::string descripcion;
    enum Estado {PENDIENTE, EN_PROGRESO, COMPLETADA} estado;
    int prioridad; // 1 (baja) a 5 (alta)
    
    // Constructor por defecto
    Tarea();
    
    // Constructor con par metros
    Tarea(int id, const std::string& titulo, const std::string& descripcion, int prioridad);
    
    // M‚todo para convertir estado a string
    std::string estadoToString() const;
};

// Clase principal para gestionar tareas
class GestorTareas {
private:
    static const int MAX_TAREAS = 100;
    Tarea tareas[MAX_TAREAS]; // Array de tareas
    int contador;
    
public:
    // Constructor
    GestorTareas();
    
    // M‚todo para agregar una nueva tarea
    void agregarTarea(const std::string& titulo, const std::string& descripcion, int prioridad);
    
    // M‚todo para buscar una tarea por ID
    int buscarTarea(int id) const;
    
    // M‚todo para listar todas las tareas
    void listarTareas() const;
    
    // M‚todo para actualizar el estado de una tarea
    void actualizarEstado(int id, Tarea::Estado nuevoEstado);
    
    // M‚todo para eliminar una tarea
    void eliminarTarea(int id);
    
    // M‚todo para filtrar tareas por estado
    void filtrarPorEstado(Tarea::Estado estado) const;
    
    // M‚todo para obtener el n£mero total de tareas
    int obtenerTotalTareas() const;
};

#endif // Q2_H
