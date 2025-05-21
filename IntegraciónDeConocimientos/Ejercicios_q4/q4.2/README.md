# Proyecto C++: Seguimiento de Stock con Inventario, Pila y Cola

##  Objetivos

Al finalizar esta tarea, los estudiantes:
- Manipularán el inventario usando arrays y punteros
- Utilizarán los contenedores de la biblioteca estándar: `std::queue` y `std::stack`
- Modelarán un proceso de inventario real con operaciones estructuradas
- Practicarán la gestión dinámica de memoria y la seguridad de punteros

---

##  Estructura de Archivos

| Archivo | Propósito |
|--------------------|-------------------------------------------------|
| `stocktracking.h` | Declaraciones: array de inventario + pila + cola |
| `stocktracking.cpp`| Lógica de inventario, gestión de pilas y colas |
| `main.cpp` | Menú de texto usando la clase `StockTracking`|

---

##  Conceptos Cubiertos

| Concepto | Visto en | |-------------------------------|--------------------------------------------|
| Arreglos dinámicos con `new[]` | Memoria manual en `inventario` |
| Uso de la pila (`std::stack`) | Productos recientemente eliminados (`productosRecientes`) |
| Uso de la cola (`std::queue`) | Stock entrante (`productosEntrantes`) |
| Retorno de puntero (`Producto*`) | `buscarProducto(id)` |
| Copia de contenedores STL | Para la visualización segura del contenido de la cola/pila|

---

##  Ejercicios del estudiante

###  Práctica básica

1. Agregue 3 productos al inventario usando la opción 1.
2. Use la opción 4 para listar todos los productos.
3. Agregue 2 más mediante la cola de stock entrante (opción 5) y proceselos (opción 6).

---

###  Tareas Intermedias

4. Eliminar un producto por ID (opción 2) y mostrar que se agregó a la pila.
5. Usar la opción 8 para restaurarlo de la pila al inventario.
6. Mostrar tanto `productosEntrantes` como `productosRecientes` usando las opciones 7 y 9.

---

###  Lógica Avanzada

7. Usar `buscarProducto()` para encontrar y mostrar un producto.
8. Demostrar qué sucede al intentar agregar un producto con ID duplicado.
9. Activar un mensaje de inventario lleno (límite de 100 productos) usando un bucle.

---

##  Desafío Extra

- Agregar el método `modificarProducto(int id)` para actualizar el precio/stock.
- Agregar la función `buscarPorNombre(std::string)`. - Refactorizar `Producto* inventario` a `std::vector<Producto>` para prácticas futuras.

---

##  Rúbrica de evaluación (10 pts)

| Criterios | Puntos |
|----------------------------------------|--------|
| Operaciones de inventario (añadir/eliminar/listar) | 2 |
| Comportamiento de cola (entrantes) | 2 |
| Comportamiento de pila (recientes) | 2 |
| Lógica de retorno/búsqueda de punteros | 2 |
| Estructura y validación de E/S limpias | 2 |
| **Total** | **10** |

---

##  Diseño de carpeta sugerido