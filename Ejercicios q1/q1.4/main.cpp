#include <iostream>
#include <iomanip>
#include "sales_analysis.h"
/*g++ -std=c++11 sales_analysis.cpp main.cpp -o sales_analysis
*/
int main() {
    try {
        // Crear departamentos de ventas
        SalesDepartment departamento1("Ventas Tecnolog�a", 15);
        SalesDepartment departamento2("Ventas Automotriz", 20);
        SalesDepartment departamento3("Ventas Farmac�utica", 12);

        // Agregar ventas por empleado en cada departamento
        departamento1.addEmployeeSales(65000.50);
        departamento1.addEmployeeSales(55000.75);
        departamento1.addEmployeeSales(48000.25);

        departamento2.addEmployeeSales(72000.90);
        departamento2.addEmployeeSales(60000.60);
        departamento2.addEmployeeSales(55000.30);

        departamento3.addEmployeeSales(45000.20);
        departamento3.addEmployeeSales(52000.80);
        departamento3.addEmployeeSales(38000.45);

        // Arreglo de departamentos para procesamiento
        SalesDepartment departamentos[] = {departamento1, departamento2, departamento3};

        // An�lisis de resultados
        std::cout << "An�lisis de Rendimiento de Ventas\n";
        std::cout << "==================================\n";

        for (const auto& departamento : departamentos) {
            std::cout << "Departamento: " << departamento.getDepartmentName() << std::endl;
            
            // Calcular y mostrar promedio de ventas
            double avgSales = departamento.calculateAverageSales();
            std::cout << "Promedio de Ventas: $" 
                      << std::fixed << std::setprecision(2) 
                      << avgSales << std::endl;

            // Verificar umbral de rendimiento
            std::cout << "Cumple Umbral de Rendimiento: " 
                      << (departamento.meetsPerformanceThreshold() ? "S�" : "No") << std::endl;

            // Encontrar mejor empleado
            int topPerformerIndex = departamento.findTopPerformingEmployeeIndex();
            std::cout << "Mejor Empleado (�ndice): " << topPerformerIndex << std::endl;
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
