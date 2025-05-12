#ifndef ELECTORAL_ANALYSIS_H
#define ELECTORAL_ANALYSIS_H

#include <string>
#include <vector>

class ElectoralDistrict {
private:
    std::string districtName;
    int totalVoters;
    std::vector<int> votesPerCandidate;
    const double MINIMUM_PARTICIPATION_THRESHOLD;

public:
    // Constructor
    ElectoralDistrict(const std::string& name, int voters);

    // Método para agregar votos de un candidato
    void addCandidateVotes(int votes);

    // Método para calcular el porcentaje de participación
    double calculateParticipationRate() const;

    // Método para determinar si el distrito cumple con el umbral mínimo de participación
    bool meetsParticipationThreshold() const;

    // Método para encontrar al candidato con más votos
    int findWinningCandidateIndex() const;

    // Getter para el nombre del distrito
    std::string getDistrictName() const;
};

#endif // ELECTORAL_ANALYSIS_H