#include "q1.h"
#include <stdexcept>
#include <algorithm>

// Constructor
ElectoralDistrict::ElectoralDistrict(const std::string& name, int voters) 
    : districtName(name), 
      totalVoters(voters), 
      MINIMUM_PARTICIPATION_THRESHOLD(0.5) {
    if (totalVoters <= 0) {
        throw std::invalid_argument("El número de votantes debe ser positivo");
    }
}

// Método para agregar votos de un candidato
void ElectoralDistrict::addCandidateVotes(int votes) {
    if (votes < 0) {
        throw std::invalid_argument("Los votos no pueden ser negativos");
    }
    votesPerCandidate.push_back(votes);
}

// Método para calcular el porcentaje de participación
double ElectoralDistrict::calculateParticipationRate() const {
    int totalCastedVotes = 0;
    for (int votes : votesPerCandidate) {
        totalCastedVotes += votes;
    }
    return static_cast<double>(totalCastedVotes) / totalVoters;
}

// Método para determinar si el distrito cumple con el umbral mínimo de participación
bool ElectoralDistrict::meetsParticipationThreshold() const {
    return calculateParticipationRate() >= MINIMUM_PARTICIPATION_THRESHOLD;
}

// Método para encontrar al candidato con más votos
int ElectoralDistrict::findWinningCandidateIndex() const {
    if (votesPerCandidate.empty()) {
        throw std::runtime_error("No hay votos registrados");
    }

    return std::max_element(votesPerCandidate.begin(), votesPerCandidate.end()) - votesPerCandidate.begin();
}

// Getter para el nombre del distrito
std::string ElectoralDistrict::getDistrictName() const {
    return districtName;
}