# 🧾 C++ Project: Object-Oriented Inventory System

## 🧠 Objectives
Students will:
- Use class hierarchies, virtual methods, and inheritance
- Understand ownership and lifetime with smart pointers (`unique_ptr`)
- Pass pointers, references, and use dynamic memory safely
- Implement polymorphism and function overriding
- Build and test an inventory management system with exception handling

---

## 📂 Project Structure

| File             | Purpose                                      |
|------------------|----------------------------------------------|
| `stocktaking.h`  | Class declarations for inventory system      |
| `stocktaking.cpp`| Full implementation                          |
| `main.cpp`       | 🧑‍💻 *Students will create this*              |

---

## 📚 Concepts Covered

| Topic                           | Examples in Code                        |
|----------------------------------|-----------------------------------------|
| Inheritance & virtual methods   | `Producto` & `ProductoPerecedero`       |
| Smart pointers (`unique_ptr`)   | Ownership in `Inventario::productos`    |
| Function overriding             | `calcularValorTotal()` in subclasses    |
| Dynamic allocation              | `Producto* producto = new Producto(...)`|
| References & const correctness  | `buscarProducto()`, `mostrar()`         |
| Exception handling              | Custom `InventarioException`            |

---

## 🧪 Student Exercises

### 🛠️ Basic Practice
1. Create a `main.cpp` to add at least **3 products**, including **1 perishable**.
2. Display the inventory using `mostrarInventario()`.
3. Delete a product using `eliminarProducto(id)` and verify.
4. Use `buscarProducto()` to retrieve and display a product.

### ⚙️ Intermediate Tasks
5. Use `actualizarStockMultiple()` to modify stock of multiple products.
6. Use `ordenarInventario()` by price and by stock.
7. Call `calcularValorInventario()` and display the result.

### 📊 Advanced Logic
8. Use `filtrarProductosBajosStock(umbral)` to get low-stock items.
9. Use `encontrarProductosMayorMenorPrecio()` and print both.
10. Use `generarInformePorCategoria()` passing a lambda that groups products as `"perecedero"` or `"regular"`.

---

## 🎯 Bonus Challenge
- Create a subclass `ProductoElectronico` and override `calcularValorTotal()` with warranty fee.
- Track categories like `"alimento"`, `"ropa"` using the category lambda and produce a full report.

---

## ✅ Evaluation Criteria

| Criteria                             | Points |
|--------------------------------------|--------|
| Correct class usage (constructors, inheritance) | 2 |
| Pointer management (`unique_ptr`, raw pointers safely) | 2 |
| Reference and const correctness      | 1 |
| Exception handling and validation    | 2 |
| Correct function outputs & structure | 3 |
| **Total**                            | **10** |

---

## 📂 Suggested File Setup

g++ -std=c++17 main.cpp stocktaking.cpp -o main