#ifndef ENVIRONMENTAL_MONITORING_H
#define ENVIRONMENTAL_MONITORING_H

#include <string>
#include <vector>

class EnvironmentalZone {
private:
    std::string zoneName;
    int totalMeasurements;
    std::vector<double> pollutionLevels;
    const double MAXIMUM_POLLUTION_THRESHOLD;

public:
    // Constructor
    EnvironmentalZone(const std::string& name, int maxMeasurements);

    // M‚todo para agregar niveles de contaminaci¢n
    void addPollutionMeasurement(double pollutionLevel);

    // M‚todo para calcular promedio de contaminaci¢n
    double calculateAveragePollutiionLevel() const;

    // M‚todo para verificar si la zona supera el umbral de contaminaci¢n
    bool exceedsPollutionThreshold() const;

    // M‚todo para encontrar el nivel m ximo de contaminaci¢n
    double findMaximumPollutionLevel() const;

    // Getter para el nombre de la zona
    std::string getZoneName() const;
};

#endif // ENVIRONMENTAL_MONITORING_H
