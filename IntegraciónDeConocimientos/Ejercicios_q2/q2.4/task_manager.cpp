#include "task_manager.h"
#include <iostream>
#include <iomanip>

// Implementaci�n de constructor por defecto de Tarea
Tarea::Tarea() : id(0), titulo(""), descripcion(""), estado(PENDIENTE), prioridad(1) {
}

// Implementaci�n de constructor con par�metros de Tarea
Tarea::Tarea(int id, const std::string& titulo, const std::string& descripcion, int prioridad) 
    : id(id), titulo(titulo), descripcion(descripcion), estado(PENDIENTE) {
    
    if (prioridad < 1 || prioridad > 5) {
        throw TareaException("La prioridad debe estar entre 1 y 5");
    }
    this->prioridad = prioridad;
}

// Implementaci�n del m�todo para convertir estado a string
std::string Tarea::estadoToString() const {
    switch (estado) {
        case PENDIENTE:
            return "Pendiente";
        case EN_PROGRESO:
            return "En Progreso";
        case COMPLETADA:
            return "Completada";
        default:
            return "Desconocido";
    }
}

// Implementaci�n del constructor de GestorTareas
GestorTareas::GestorTareas() : contador(0) {
}

// Implementaci�n del m�todo para agregar una nueva tarea
void GestorTareas::agregarTarea(const std::string& titulo, const std::string& descripcion, int prioridad) {
    if (contador >= MAX_TAREAS) {
        throw TareaException("No se pueden agregar m�s tareas. L�mite alcanzado.");
    }
    
    if (titulo.empty()) {
        throw TareaException("El t�tulo no puede estar vac�o");
    }
    
    int nuevoId = contador + 1;
    tareas[contador] = Tarea(nuevoId, titulo, descripcion, prioridad);
    contador++;
    
    std::cout << "Tarea agregada con ID: " << nuevoId << std::endl;
}

// Implementaci�n del m�todo para buscar una tarea por ID
int GestorTareas::buscarTarea(int id) const {
    for (int i = 0; i < contador; i++) {
        if (tareas[i].id == id) {
            return i;
        }
    }
    return -1; // No encontrado
}

// Implementaci�n del m�todo para listar todas las tareas
void GestorTareas::listarTareas() const {
    if (contador == 0) {
        std::cout << "No hay tareas registradas." << std::endl;
        return;
    }
    
    std::cout << "\n--- LISTA DE TAREAS ---" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(20) << "T�tulo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (int i = 0; i < contador; i++) {
        std::cout << std::left << std::setw(5) << tareas[i].id 
                  << std::setw(20) << tareas[i].titulo 
                  << std::setw(15) << tareas[i].estadoToString() 
                  << std::setw(10) << tareas[i].prioridad << std::endl;
    }
    std::cout << std::endl;
}

// Implementaci�n del m�todo para actualizar el estado de una tarea
void GestorTareas::actualizarEstado(int id, Tarea::Estado nuevoEstado) {
    int indice = buscarTarea(id);
    
    if (indice == -1) {
        throw TareaException("No se encontr� la tarea con ID: " + std::to_string(id));
    }
    
    tareas[indice].estado = nuevoEstado;
    std::cout << "Estado de la tarea " << id << " actualizado a: " 
              << tareas[indice].estadoToString() << std::endl;
}

// Implementaci�n del m�todo para eliminar una tarea
void GestorTareas::eliminarTarea(int id) {
    int indice = buscarTarea(id);
    
    if (indice == -1) {
        throw TareaException("No se encontr� la tarea con ID: " + std::to_string(id));
    }
    
    // Desplazar las tareas para eliminar la seleccionada
    for (int i = indice; i < contador - 1; i++) {
        tareas[i] = tareas[i + 1];
    }
    
    contador--;
    std::cout << "Tarea con ID " << id << " eliminada correctamente." << std::endl;
}

// Implementaci�n del m�todo para filtrar tareas por estado
void GestorTareas::filtrarPorEstado(Tarea::Estado estado) const {
    bool encontrado = false;
    
    std::cout << "\n--- TAREAS " << Tarea(0, "", "", 1).estadoToString() << " ---" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(20) << "T�tulo" 
              << std::setw(10) << "Prioridad" << std::endl;
    std::cout << std::string(35, '-') << std::endl;
    
    for (int i = 0; i < contador; i++) {
        if (tareas[i].estado == estado) {
            std::cout << std::left << std::setw(5) << tareas[i].id 
                      << std::setw(20) << tareas[i].titulo 
                      << std::setw(10) << tareas[i].prioridad << std::endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        std::cout << "No hay tareas en este estado." << std::endl;
    }
    std::cout << std::endl;
}

// Implementaci�n del m�todo para obtener el n�mero total de tareas
int GestorTareas::obtenerTotalTareas() const {
    return contador;
}
