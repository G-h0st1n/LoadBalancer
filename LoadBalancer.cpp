// LoadBalancer.cpp

#include "LoadBalancer.h"

using namespace std;

LoadBalancer::LoadBalancer(int n, const vector<vector<int>>& matrix, int maxRequests)
: numServers(n), adjMatrix(matrix), requestsPerServer(n, 0), maxRequestsPerServer(maxRequests) {};

int LoadBalancer::distributeRequest(int startServer) {
    int minCost = INF;
    int selectedServer = -1;

    for (int i = 0; i < numServers; ++i) {
        if (i != startServer && adjMatrix[startServer][i] != INF) {
            if ((requestsPerServer[i] < requestsPerServer[selectedServer] || selectedServer == -1) &&
                (adjMatrix[startServer][i] < minCost) &&
                requestsPerServer[i] < maxRequestsPerServer) {
                minCost = adjMatrix[startServer][i];
                selectedServer = i;
            }
        }
    }

    if (selectedServer != -1) {
        requestsPerServer[selectedServer]++;
        cout << "Solicitud asignada al Servidor " << selectedServer
             << " desde Servidor " << startServer << ", Carga actual: "
             << requestsPerServer[selectedServer] << "\n";
    } else {
        cout << "No hay servidores disponibles desde el Servidor " << startServer << "\n";
    }
    return selectedServer;
}

void LoadBalancer::completeRequest(int serverId) {
    if (serverId < 0 || serverId >= numServers || requestsPerServer[serverId] == 0) {
        cout << "Error: no hay solicitudes activas en el Servidor " << serverId << "\n";
        return;
    }

    requestsPerServer[serverId]--;
    cout << "Solicitud completada en el Servidor " << serverId
              << ", Carga actual: " << requestsPerServer[serverId] << "\n";
}

void LoadBalancer::displayServerLoads() {
    cout << "Cargas actuales de los servidores:\n";
    for (int i = 0; i < numServers; ++i) {
        cout << "Servidor " << i << ": " << requestsPerServer[i] << " solicitudes\n";
    }
}

void LoadBalancer::displayAdjMatrix() {
    cout << "Matriz de adyacencia:\n";
    for (const auto& row : adjMatrix) {
        for (int cost : row) {
            if (cost == INF) {
                cout << "INF ";
            } else {
                cout << cost << " ";
            }
        }
        cout << "\n";
    }
}
