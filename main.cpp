
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "LoadBalancer.h"

using namespace std;

vector<vector<int>> generateAdjMatrix(int numServers) {
    vector<vector<int>> matrix(numServers, vector<int>(numServers, INF));
    srand(time(0));

    for (int i = 0; i < numServers; ++i) {
        for (int j = 0; j < numServers; ++j) {
            if (i != j) {
                matrix[i][j] = rand() % 20 + 1; // Genera costos aleatorios entre 1 y 20
            } else {
                matrix[i][j] = 0; // Distancia a sí mismo es 0
            }
        }
    }
    return matrix;
}

int main() {
    int numServers, maxRequests;

    cout << "Ingrese el número de servidores: ";
    cin >> numServers;

    cout << "Ingrese el límite máximo de solicitudes por servidor: ";
    cin >> maxRequests;

    vector<vector<int>> matrix = generateAdjMatrix(numServers);

    LoadBalancer lb(numServers, matrix, maxRequests);

    lb.displayAdjMatrix();

    lb.distributeRequest(0);
    lb.distributeRequest(0);
    lb.distributeRequest(1);
    lb.completeRequest(2);
    lb.distributeRequest(1);

    lb.displayServerLoads();

    return 0;
}
