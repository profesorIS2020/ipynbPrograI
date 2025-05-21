 Proyecto C++: Gestión de Bibliotecas con Pilas y Colas

##  Objetivos

Al completar esta tarea, los estudiantes podrán:

- Implementar y manipular pilas (LIFO) y colas (FIFO) en C++
- Aplicar conceptos de memoria dinámica mediante punteros sin formato
- Usar estructuras y estructuras de datos personalizadas basadas en nodos
- Diseñar una aplicación basada en menús
- Modelar operaciones reales con estructuras de datos

---

##  Estructura de Archivos

| Archivo | Propósito |
|--------------|------------------------------------------|
| `library.h` | Contiene las clases `Libro`, `Nodo`, `Pila`, `Cola` y `Biblioteca` |
| `library.cpp` | Implementa todas las operaciones de pila y cola |
| `main.cpp` | Menú de usuario para simular transacciones de biblioteca |

---

##  Conceptos Cubiertos

| Tema | Dónde se demuestra |
|---------------------------|-----------------------------------------------|
| Pila (Pila) - LIFO | `librosDevueltos` usado en `Biblioteca` |
| Cola (Cola) - FIFO | `librosReservados` usado en `Biblioteca` |
| Punteros sin procesar | Manipulación de nodos con `Nodo* siguiente` |
| Gestión manual de memoria | `delete temp` en destructores y métodos pop |
| Estructuras | `Libro`, `Nodo` |
| E/S interactiva | `main.cpp` gestiona un menú de texto |

---

##  Ejercicios para el estudiante

###  Práctica básica

1. Ejecuta el menú y usa:
- Opción 1 para añadir al menos 3 libros devueltos (pila)
- Opción 4 para reservar al menos 3 libros (cola)
- Opciones 3 y 6 para mostrar ambas

2. Verifica:
- Pila (pila) muestra el último libro devuelto al principio
- Cola (cola) muestra el primer libro reservado al principio

---

###  Tareas intermedias

3. Usa la opción 2 para simular el procesamiento de libros devueltos con `pop()`.
4. Usa la opción 5 para entregar libros reservados con `desencolar()`.
5. Monitoriza el tamaño interno de la pila y la cola con `obtenerTamaño()`.

---

###  Lógica avanzada

6. Modifica `Biblioteca` para que devuelva un puntero al último libro entregado. 7. Añadir un método en `Pila` o `Cola` que busque un libro por su `ID`.
8. Mostrar la seguridad de la memoria explicando cómo se limpian los nodos en los destructores.

---

##  Desafío Extra

- Añadir un método `idLibroMásReciente()` a las clases `Pila` y `Cola`.
- Almacenar automáticamente los registros de las acciones procesadas mediante un vector.

---

##  Rúbrica de Evaluación (10 pts)

| Criterios | Puntos |
|----------------------------------------|--------|
| Comportamiento de la pila (funciones de `Pila`) | 2 |
| Comportamiento de la cola (funciones de `Cola`) | 2 |
| Memoria dinámica y manejo de nodos | 2 |
| Interacción y validación del menú | 2 |
| Estructura del código y convenciones de nomenclatura | 2 |
| **Total** | **10** |

---

##  Carpeta de proyecto sugerida