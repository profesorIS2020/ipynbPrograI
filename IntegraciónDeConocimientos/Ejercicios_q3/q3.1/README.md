# Plan de lección: Comprensión de punteros y referencias en C++

## Objetivos
Al finalizar esta lección, los estudiantes podrán:
- Distinguir entre referencias y punteros en C++ (Conferencia punteros campus virtual diapositivas 36 a 39)
- Usar referencias para modificar variables pasadas a funciones (Conferencia punteros campus virtual diapositivas 36 a 39)
- Usar punteros para crear y gestionar memoria dinámica
- Comprender la diferencia entre copia profunda y copia superficial(Conferencia punteros campus virtual diapositivas 31 a 35)
- Evitar fugas de memoria con `delete`

---

## Resumen de archivos

| Archivo | Descripción |
|-------------|-------------|
| `Vector.h` | Declaración de la clase Vector con uso de punteros sin formato |
| `Vector.cpp` | Implementación de los métodos de la clase |
| `main.cpp` | Demostración de punteros, referencias y copias profundas |

---

## Conceptos cubiertos

- `double* elementos;` → puntero a memoria
- `Vector&` vs `Vector*` → referencia vs. parámetros de función de puntero
- `new` y `delete[]` → gestión manual de memoria
- Constructor de copia y copia profunda
- Uso de referencias constantes por seguridad
- Devolución de puntero vs. devolución de referencia

---

## Ejercicios prácticos

### Parte 1: Comportamiento de la función
1. Cree una función que acepte un `Vector&` y lo modifique restando 1 a todos los valores.
2. Cree una función que acepte un `Vector*` y sume 1 a todos los valores.
3. Demuestre que ambas afectan al objeto original, pero usan una sintaxis diferente.

### Parte 2: Copia profunda vs. superficial
4. Copie un `Vector` usando el constructor de copia.
5. Modifique el vector original.
6. Demuestre que el vector copiado no se ve afectado.

### Parte 3: Gestión de memoria
7. Cree un `Vector` usando `new`.
8. Devuélvalo desde una función.
9. Recuerde usar `delete` después para evitar fugas de memoria.

### Parte 4: Ortogonalidad
10. Cree 3 vectores mutuamente ortogonales.
11. Use `sonOrtogonales()` para confirmar.
12. Modifique uno y vuelva a comprobar.

---

## Desafío (opcional)
- Cree una función que reciba `const Vector*[]` y devuelva el índice del primer par no ortogonal.
