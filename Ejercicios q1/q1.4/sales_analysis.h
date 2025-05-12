#ifndef SALES_ANALYSIS_H
#define SALES_ANALYSIS_H

#include <string>
#include <vector>

class SalesDepartment {
private:
    std::string departmentName;
    int totalEmployees;
    std::vector<double> salesPerEmployee;
    const double MINIMUM_PERFORMANCE_THRESHOLD;

public:
    // Constructor
    SalesDepartment(const std::string& name, int employees);

    // M‚todo para agregar ventas de un empleado
    void addEmployeeSales(double sales);

    // M‚todo para calcular el promedio de ventas
    double calculateAverageSales() const;

    // M‚todo para verificar si el departamento cumple con el umbral de rendimiento
    bool meetsPerformanceThreshold() const;

    // M‚todo para encontrar el mejor empleado en ventas
    int findTopPerformingEmployeeIndex() const;

    // Getter para el nombre del departamento
    std::string getDepartmentName() const;
};

#endif // SALES_ANALYSIS_H
