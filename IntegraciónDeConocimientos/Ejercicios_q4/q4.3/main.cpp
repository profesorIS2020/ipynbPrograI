// main.cpp
// Este archivo contiene la función principal que inicializa y ejecuta el TaskManager

#include "taskmanager.h"
#include <iostream>

int main() {
    std::cout << "Bienvenido al Gestor de Tareas\n";
    std::cout << "Este programa demuestra el uso de pilas y colas en C++\n\n";
    
    // Crear una instancia del gestor de tareas
    TaskManager taskManager;
    
    // Agregar algunas tareas de ejemplo (opcional)
    taskManager.addTask("Terminar informe", "Completar el informe de laboratorio", true);
    taskManager.addTask("Estudiar para examen", "Repasar capítulos 1-3", true);
    taskManager.addTask("Revisar correo", "Leer emails pendientes", false);
    taskManager.addTask("Actualizar repositorio", "Subir cambios al repositorio Git", false);
    
    // Mostrar explicación sobre pilas y colas
    std::cout << "\n==== EXPLICACIÓN ====\n";
    std::cout << "PILA (Stack): Las tareas prioritarias se manejan como una pila (LIFO).\n";
    std::cout << "  - La última tarea añadida es la primera en procesarse.\n";
    std::cout << "  - Operaciones principales: push (añadir), pop (quitar), top (consultar).\n\n";
    
    std::cout << "COLA (Queue): Las tareas regulares se manejan como una cola (FIFO).\n";
    std::cout << "  - La primera tarea añadida es la primera en procesarse.\n";
    std::cout << "  - Operaciones principales: push (añadir), pop (quitar), front (consultar).\n";
    std::cout << "===================\n\n";
    
    // Mostrar el menú principal
    taskManager.showMenu();
    
    return 0;
}