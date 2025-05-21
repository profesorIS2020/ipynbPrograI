# Proyecto C++: Administrador de tareas con pila y cola

##  Objetivos

Al completar esta lección, los estudiantes:

- Implementarán el modelado real de un **sistema de cola de tareas**
- Comprenderán la diferencia entre una **pila (LIFO)** y una **cola (FIFO)**
- Aplicarán los contenedores estándar `std::stack` y `std::queue`
- Diseñarán una aplicación **controlada por menús** con entrada dinámica
- Mostrarán datos de forma segura sin alterar el estado del contenedor

---

##  Resumen de archivos

| Archivo | Propósito |
|--------------|---------------------------------------------------------|
| `taskmanager.h` | Definiciones de clases: `Task`, `TaskManager` |
| `taskmanager.cpp` | Lógica de pila y cola para la gestión de tareas |
| `main.cpp` | Ejecuta el programa y muestra el menú principal|

---

##  Conceptos cubiertos

| Concepto | Demostración en |
|--------------------------|--------------------------------------------------|
| Comportamiento de pila (LIFO) | `priorityTasks` para el procesamiento de tareas urgentes |
| Comportamiento de cola (FIFO) | `regularTasks` para tareas no urgentes |
| Contenedores STL | `std::stack`, `std::queue` |
| Entrada segura en búfer | Uso de `std::cin.ignore()` en `showMenu()` |
| Modelado basado en estructuras | `Task` con título, descripción y bandera de prioridad |

---

##  Ejercicios para estudiantes

###  Práctica básica

1. Use el menú para agregar al menos 3 **tareas prioritarias** y 2 **tareas regulares**.
2. Use las opciones del menú para ver todas las tareas prioritarias (pila) y regulares (cola). 3. Demuestra que la pila imprime **último en entrar, primero en salir** y la cola **primero en entrar, primero en salir**.

---

###  Tareas intermedias

4. Procesa (completa) una tarea prioritaria: observa cómo se elimina la más reciente.
5. Procesa una tarea regular: observa cómo se elimina la más antigua.
6. Agrega una nueva tarea y verifica que aparezca en el lugar correcto (al principio de la pila o al final de la cola).

---

###  Lógica avanzada

7. Contabiliza el número total de tareas pendientes usando `getPriorityTaskCount()` y `getRegularTaskCount()`.
8. Muestra una visualización segura de la pila y la cola usando contenedores copiados.
9. Explica por qué la pila y la cola **no se modifican** al mostrar tareas.

---

##  Desafío adicional

- Agrega una marca de tiempo a cada tarea (usa `chrono` o una secuencia de enteros simple). - Añadir una función para marcar las tareas como "archivadas" después de procesarlas.
- Permitir guardar y cargar listas de tareas en/desde un archivo de texto.

---

##  Rúbrica de evaluación (10 pts)

| Criterios | Puntos |
|-----------------------------------|--------|
| Comportamiento de pila y cola (insertar/extraer) | 3 |
| Seguridad de memoria dinámica y E/S | 2 |
| Interfaz de menú clara y estructurada | 2 |
| Visualización precisa sin mutaciones | 2 |
| Implementación de función adicional | 1 |
| **Total** | **10** |

---

##  Diseño de carpeta sugerido