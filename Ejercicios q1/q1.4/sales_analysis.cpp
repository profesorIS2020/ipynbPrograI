#include "sales_analysis.h"
#include <stdexcept>
#include <algorithm>
#include <numeric>

// Constructor
SalesDepartment::SalesDepartment(const std::string& name, int employees) 
    : departmentName(name), 
      totalEmployees(employees), 
      MINIMUM_PERFORMANCE_THRESHOLD(50000.0) {
    if (employees <= 0) {
        throw std::invalid_argument("El n�mero de empleados debe ser positivo");
    }
}

// M�todo para agregar ventas de un empleado
void SalesDepartment::addEmployeeSales(double sales) {
    if (sales < 0) {
        throw std::invalid_argument("Las ventas no pueden ser negativas");
    }
    salesPerEmployee.push_back(sales);
}

// M�todo para calcular el promedio de ventas
double SalesDepartment::calculateAverageSales() const {
    if (salesPerEmployee.empty()) {
        return 0.0;
    }
    return std::accumulate(salesPerEmployee.begin(), salesPerEmployee.end(), 0.0) / salesPerEmployee.size();
}

// M�todo para verificar si el departamento cumple con el umbral de rendimiento
bool SalesDepartment::meetsPerformanceThreshold() const {
    return calculateAverageSales() >= MINIMUM_PERFORMANCE_THRESHOLD;
}

// M�todo para encontrar el mejor empleado en ventas
int SalesDepartment::findTopPerformingEmployeeIndex() const {
    if (salesPerEmployee.empty()) {
        throw std::runtime_error("No hay registros de ventas");
    }

    return std::max_element(salesPerEmployee.begin(), salesPerEmployee.end()) - salesPerEmployee.begin();
}

// Getter para el nombre del departamento
std::string SalesDepartment::getDepartmentName() const {
    return departmentName;
}
