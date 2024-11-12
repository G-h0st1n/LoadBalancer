// LoadBalancer.h
#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = INT_MAX;

class LoadBalancer {
private:
    int numServers;
    vector<vector<int>> adjMatrix;
    vector<int> requestsPerServer;
    int maxRequestsPerServer;

public:
    LoadBalancer(int n, const vector<vector<int>>& matrix, int maxRequests);
    int distributeRequest(int startServer);
    void completeRequest(int serverId);
    void displayServerLoads();
    void displayAdjMatrix();
};

#endif // LOADBALANCER_H

