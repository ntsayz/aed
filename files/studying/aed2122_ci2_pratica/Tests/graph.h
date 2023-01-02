// AED 2021/2022 - CI2 - Parte Prática
// Pedro Ribeiro (DCC/FCUP) [12/02/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
#include <vector>
#include <list>
#include <iostream>
#include <queue>

#define INF (INT_MAX/2)

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        int dist;       // Node distance from source node
        bool visited;   // Has the node been visited?
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

    void dijkstra(int s); // Example implementation of Dijkstra
    void dfs(int v);      // Example implementation of DFS
    void bfs(int v);      // Example implementation of BFS

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // ----- Functions to implement in this test -----
    bool hasEdge(int a, int b);
    vector<int> degreeDistribution();
    bool sameComponent(int a, int b);
    int eccentricity(int a);
    int meetingPoint(int a, int b);
    int secondBestMST();
    list<int> traffic(int a, int b);
};

#endif
