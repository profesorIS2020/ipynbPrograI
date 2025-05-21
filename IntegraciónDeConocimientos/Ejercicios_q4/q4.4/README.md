# 🎓 Proyecto C++: Sistema de Gestión de Calificaciones con Pilas y Colas

##  Objetivos

Al completar este proyecto, los estudiantes:
- Comprenderán la estructura y el uso de **pilas (LIFO)** y **colas (FIFO)**
- Aplicarán contenedores estándar de C++ (`std::stack`, `std::queue`) en flujos de trabajo de datos
- Gestionarán el diseño de menús interactivos y la validación robusta de entradas
- Calcularán estadísticas agregadas (p. ej., calificaciones promedio)
- Utilizarán la copia de contenedores para mostrar elementos de forma segura

---

##  Archivos del Proyecto

| Archivo | Propósito |
|-------------|---------------------------------------------------|
| `grades.h` | Declaraciones para `Student` y `GradeManager` |
| `grades.cpp` | Implementación de la lógica de pilas y colas |
| `main.cpp` | Menú de interacción del usuario con control de entrada/salida |

---

##  Conceptos cubiertos

| Concepto | Demostrado en |
|-----------------------------|--------------------------------------------------|
| Operaciones de pila | `recentGrades` para las últimas calificaciones enviadas |
| Operaciones de cola | `gradeQueue` para procesar el orden |
| Modelado basado en estructuras | `Student` con `name` y `grade` |
| Validación de datos | Entrada de calificación limitada de 0 a 10 |
| Visualización segura de contenedores | Copias temporales de la pila y la cola |
| Estadísticas y borrado de datos | `calculateAverageGrade()` y `clearAllData()` |

---

##  Ejercicios para estudiantes

###  Práctica básica

1. Agregue 3 estudiantes usando la opción 1. Verifique que se inserten en la pila y se pongan en cola.
2. Use las opciones 2 y 5 para verificar la parte superior de la pila y la parte delantera de la cola. 3. Visualice y muestre todos los elementos con las opciones 4 y 7.

---

###  Tareas intermedias

4. Elimine la última calificación introducida (opción 3) y explique por qué la cola no se ve afectada.
5. Procese y elimine el primer elemento de la cola (opción 6).
6. Verifique los promedios con la opción 8 y valide los resultados manualmente.

---

###  Tareas avanzadas

7. Utilice `clearAllData()` y muestre que todo está vacío después.
8. Explique los métodos LIFO y FIFO mediante el orden mostrado. 9. Añadir funcionalidad para listar estudiantes con calificaciones superiores a 7.

---

##  Desafío adicional

- Añadir compatibilidad con la ordenación alfabética de estudiantes (usando una copia `std::vector`)
- Guardar todos los datos actuales en un archivo `.txt` antes de salir
- Permitir deshacer la última extracción de la cola (con una cola de respaldo adicional)

---

##  Rúbrica de evaluación (10 pts)

| Criterios | Puntos |
|-----------------------------------------------|--------|
| Operaciones de pila y cola | 3 |
| Manejo y validación de entrada | 2 |
| Visualización de la corrección con copias de contenedor | 2 |
| Estadísticas y funciones de borrado de estado | 2 |
| Implementación adicional | 1 |
| **Total** | **10** |

---

##  Diseño de carpeta sugerido