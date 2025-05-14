#include <iostream>
#include <iomanip>
#include "q1.h"

/*para compilar  g++ -std=c++11 q1.cpp main.cpp -o electoral_analysis*/

int main() {
    try {
        // Crear distritos electorales
        ElectoralDistrict distrito1("Norte", 1000);
        ElectoralDistrict distrito2("Sur", 1500);
        ElectoralDistrict distrito3("Centro", 800);

        // Agregar votos para múltiples candidatos en cada distrito
        distrito1.addCandidateVotes(350);  // Candidato 1
        distrito1.addCandidateVotes(250);  // Candidato 2
        distrito1.addCandidateVotes(200);  // Candidato 3

        distrito2.addCandidateVotes(550);  // Candidato 1
        distrito2.addCandidateVotes(450);  // Candidato 2
        distrito2.addCandidateVotes(300);  // Candidato 3

        distrito3.addCandidateVotes(300);  // Candidato 1
        distrito3.addCandidateVotes(250);  // Candidato 2
        distrito3.addCandidateVotes(100);  // Candidato 3

        // Arreglo de distritos para procesamiento
        ElectoralDistrict distritos[] = {distrito1, distrito2, distrito3};

        // Análisis de resultados
        std::cout << "Análisis de Resultados Electorales\n";
        std::cout << "==================================\n";

        for (const auto& distrito : distritos) {
            std::cout << "Distrito: " << distrito.getDistrictName() << std::endl;
            
            // Calcular y mostrar tasa de participación
            double participationRate = distrito.calculateParticipationRate();
            std::cout << "Tasa de Participación: " 
                      << std::fixed << std::setprecision(2) 
                      << (participationRate * 100) << "%" << std::endl;

            // Verificar umbral de participación
            std::cout << "Cumple Umbral Mínimo: " 
                      << (distrito.meetsParticipationThreshold() ? "Sí" : "No") << std::endl;

            // Encontrar candidato ganador
            int winnerIndex = distrito.findWinningCandidateIndex();
            std::cout << "Candidato Ganador (Índice): " << winnerIndex << std::endl;
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
