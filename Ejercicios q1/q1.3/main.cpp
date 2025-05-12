#include <iostream>
#include <iomanip>
#include "enviromental_monitoring.h"
/*g++ -std=c++11 q1.cpp main.cpp -o electoral_analysis */
int main() {
    try {
        // Crear zonas ambientales
        EnvironmentalZone zona1("Zona Industrial", 10);
        EnvironmentalZone zona2("Zona Residencial", 10);
        EnvironmentalZone zona3("Zona Rural", 10);

        // Agregar mediciones de contaminaci�n
        zona1.addPollutionMeasurement(8.5);
        zona1.addPollutionMeasurement(9.2);
        zona1.addPollutionMeasurement(7.8);

        zona2.addPollutionMeasurement(5.6);
        zona2.addPollutionMeasurement(6.1);
        zona2.addPollutionMeasurement(4.9);

        zona3.addPollutionMeasurement(3.2);
        zona3.addPollutionMeasurement(2.7);
        zona3.addPollutionMeasurement(3.5);

        // Arreglo de zonas para procesamiento
        EnvironmentalZone zonas[] = {zona1, zona2, zona3};

        // An�lisis de resultados
        std::cout << "An�lisis de Niveles de Contaminaci�n\n";
        std::cout << "====================================\n";

        for (const auto& zona : zonas) {
            std::cout << "Zona: " << zona.getZoneName() << std::endl;
            
            // Calcular y mostrar nivel promedio de contaminaci�n
            double avgPollution = zona.calculateAveragePollutiionLevel();
            std::cout << "Nivel Promedio de Contaminaci�n: " 
                      << std::fixed << std::setprecision(2) 
                      << avgPollution << std::endl;

            // Verificar umbral de contaminaci�n
            std::cout << "Supera Umbral de Contaminaci�n: " 
                      << (zona.exceedsPollutionThreshold() ? "S�" : "No") << std::endl;

            // Encontrar nivel m�ximo de contaminaci�n
            double maxPollution = zona.findMaximumPollutionLevel();
            std::cout << "Nivel M�ximo de Contaminaci�n: " 
                      << std::fixed << std::setprecision(2) 
                      << maxPollution << std::endl;
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
