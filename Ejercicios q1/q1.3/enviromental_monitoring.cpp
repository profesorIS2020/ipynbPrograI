#include "enviromental_monitoring.h"
#include <stdexcept>
#include <algorithm>
#include <numeric>

// Constructor
EnvironmentalZone::EnvironmentalZone(const std::string& name, int maxMeasurements) 
    : zoneName(name), 
      totalMeasurements(maxMeasurements), 
      MAXIMUM_POLLUTION_THRESHOLD(7.5) {
    if (maxMeasurements <= 0) {
        throw std::invalid_argument("El n�mero de mediciones debe ser positivo");
    }
}

// M�todo para agregar niveles de contaminaci�n
void EnvironmentalZone::addPollutionMeasurement(double pollutionLevel) {
    if (pollutionLevel < 0) {
        throw std::invalid_argument("El nivel de contaminaci�n no puede ser negativo");
    }
    pollutionLevels.push_back(pollutionLevel);
}

// M�todo para calcular promedio de contaminaci�n
double EnvironmentalZone::calculateAveragePollutiionLevel() const {
    if (pollutionLevels.empty()) {
        return 0.0;
    }
    return std::accumulate(pollutionLevels.begin(), pollutionLevels.end(), 0.0) / pollutionLevels.size();
}

// M�todo para verificar si la zona supera el umbral de contaminaci�n
bool EnvironmentalZone::exceedsPollutionThreshold() const {
    return calculateAveragePollutiionLevel() > MAXIMUM_POLLUTION_THRESHOLD;
}

// M�todo para encontrar el nivel m�ximo de contaminaci�n
double EnvironmentalZone::findMaximumPollutionLevel() const {
    if (pollutionLevels.empty()) {
        throw std::runtime_error("No hay mediciones registradas");
    }

    return *std::max_element(pollutionLevels.begin(), pollutionLevels.end());
}

// Getter para el nombre de la zona
std::string EnvironmentalZone::getZoneName() const {
    return zoneName;
}
