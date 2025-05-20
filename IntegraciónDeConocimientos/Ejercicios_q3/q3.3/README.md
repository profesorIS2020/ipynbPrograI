# Estructura del proyecto

1. Estructura correcta con archivos .h, .cpp y main.cpp
2. Uso apropiado de punteros y referencias
3. Manejo de excepciones
4. Progresión de métodos simples a complejos


1. **biblioteca.h**: Contiene las declaraciones de las clases y métodos.
2. **biblioteca.cpp**: Implementación de las clases y métodos.  
3. **main.cpp**: Programa principal que demuestra todas las funcionalidades.

## Características implementadas

### Estructura de archivos
Estructura estándar de C++ con archivos separados para encabezados (.h), implementación (.cpp) y programa principal (main.cpp).

### Uso de punteros y referencias
El programa demuestra diferentes usos de punteros y referencias:

- **Punteros crudos**: Para navegar y manipular objetos (`Libro*`)
- **Punteros inteligentes**: `std::unique_ptr` para gestión automática de memoria
- **Referencias**: Para parámetros (`const std::string&`) y retornos (`std::string&`)
- **Reference wrappers**: `std::reference_wrapper<Libro>` para colecciones de referencias

### Manejo de excepciones
- Clase personalizada `BibliotecaException` que hereda de `std::runtime_error`
- Bloques try-catch para manejar errores en operaciones como búsqueda o inserción
- Propagación de excepciones entre métodos

### Evolución de métodos
Los métodos evolucionan en complejidad:
1. **Métodos simples**: `agregarLibro()`, `mostrarCatalogo()`
2. **Métodos intermedios**: Con punteros (`obtenerLibro()`) y referencias (`prestarLibro()`)
3. **Métodos complejos**: Con manejo de excepciones (`buscarLibroPorTitulo()`)
4. **Métodos muy complejos**: Con algoritmos, punteros a funciones y manipulación avanzada (`reorganizarColeccion()`)

## Explicación de conceptos clave

### Punteros vs Referencias

**Punteros**:
- Pueden ser nulos (`nullptr`)
- Pueden cambiar a qué objeto apuntan
- Requieren desreferenciación (`*ptr` o `ptr->miembro`)
- En el código: `Libro* libro = miBiblioteca.obtenerLibro(4);`

**Referencias**:
- No pueden ser nulas
- No pueden cambiar a qué objeto se refieren
- Sintaxis como variables normales
- En el código: `void cambiarDisponibilidad(bool& estado)`

### Punteros inteligentes
- `std::unique_ptr`: Garantiza que solo hay un dueño del objeto
- No requiere `delete` manual, libera la memoria automáticamente
- En el código: `std::unique_ptr<Libro> nuevoLibro = std::make_unique<Libro>(...)`

### Manejo de excepciones
El programa utiliza excepciones para evitar que errores graves terminen la ejecución, permitiendo recuperarse de situaciones como búsquedas fallidas o violaciones de reglas de negocio.

## Ejecución del programa

Al ejecutar este programa verás una demostración completa de todas las funcionalidades:
1. Creación de libros
2. Manipulación mediante punteros
3. Préstamo y devolución con referencias
4. Búsquedas con manejo de excepciones
5. Ordenamiento mediante punteros a funciones

