# Estructura del Proyecto

1. **TaskManager.h**: Contiene las declaraciones de clases, estructuras y enumeraciones.
2. **TaskManager.cpp**: Implementa las funciones definidas en el header.
3. **main.cpp**: Contiene la función principal que inicia el programa y el menú interactivo.

## Características del Task Manager

### Estructura del proyecto
- **Organización modular**: Separación clara entre interfaz (.h) e implementación (.cpp).
- **Encapsulamiento**: Atributos privados y métodos públicos.
- **Diseño orientado a objetos**: Clases con responsabilidades bien definidas.

### Uso de punteros y referencias
- **Punteros únicos (std::unique_ptr)**: Para gestionar la memoria de las tareas de forma segura.
- **Referencias (std::reference_wrapper)**: En el método findTasksIf para evitar copias.
- **Punteros crudos (raw pointers)**: En los métodos getTaskById y getTasksByStatus.
- **Paso de referencias**: Para parámetros, evitando copias innecesarias.

### Manejo de excepciones
- **try-catch**: En la función main y en métodos que realizan operaciones arriesgadas.
- **std::invalid_argument**: Para validar parámetros incorrectos.
- **std::runtime_error**: Para errores de tiempo de ejecución.

### Progresión de complejidad en los métodos
1. **Métodos simples**: 
   - addTask: Solo añade una tarea con título.
   - displayAllTasks: Muestra todas las tareas.
   - removeTask: Elimina una tarea por ID.

2. **Métodos intermedios**:
   - addDetailedTask: Añade tarea con más campos.
   - getTaskById: Busca tarea por ID.
   - updateTaskStatus: Actualiza estado de una tarea.

3. **Métodos avanzados**:
   - addTaskWithValidation: Validación completa de parámetros.
   - sortTasksByPriority: Ordena tareas utilizando std::sort.
   - filterTasksByDueDate: Filtra tareas por fecha.
   - saveTasks/loadTasks: Persistencia en archivos.

4. **Método complejo**:
   - findTasksIf: Utiliza plantillas, referencias y funciones lambda para búsquedas avanzadas.

### Características adicionales
- **Enumeraciones**: Para definir prioridades y estados.
- **Manejo de archivos**: Para guardar/cargar tareas.
- **Estructura Date**: Para manejar fechas.
- **Interfaz interactiva por consola**: Menú completo con todas las funcionalidades.

## Compilación y ejecución

Para compilar el programa, puedes usar g++ o cualquier compilador de C++:

```bash
g++ -std=c++14 main.cpp TaskManager.cpp -o TaskManager
```

Luego ejecuta el programa:

```bash
./TaskManager
```
