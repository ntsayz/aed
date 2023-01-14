// AED 2021/2022 - CI2 - Parte Prática
// Pedro Ribeiro (DCC/FCUP) [12/02/2022]

#include "graph.h"
#include <climits>

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


// Depth-First (DFS) Search: example implementation
// (as given in class)
void Graph::dfs(int v) {
    //cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Breadth-First (BFS) Search: example implementation
// (as given in class)
void Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
    cout << endl;
}

// Dijkstra in O(|E| log |V|) using only the MinHeap that was given to you
// (as given in class)
void Graph::dijkstra(int s) {
    MinHeap<int, int> q(n, -1);
    for (int v=1; v<=n; v++) {
        nodes[v].dist = INF;
        q.insert(v, INF);
        nodes[v].visited = false;
    }
    nodes[s].dist = 0;
    q.decreaseKey(s, 0);
    while (q.getSize()>0) {
        int u = q.removeMin();
        //cout << "Node " << u << " with dist = " << nodes[u].dist << endl;
        nodes[u].visited = true;
        for (auto e : nodes[u].adj) {
            int v = e.dest;
            int w = e.weight;
            if (!nodes[v].visited && nodes[u].dist + w < nodes[v].dist) {
                nodes[v].dist = nodes[u].dist + w;
                q.decreaseKey(v, nodes[v].dist);
            }
        }
    }
}

// ----------------------------------------------------------

// ----------------------------------------------------------
// 1) Existencia de ligacao
// ----------------------------------------------------------
// TODO
bool Graph::hasEdge(int a, int b) {
    for (auto edge : nodes[a].adj) {
        if (edge.dest == b) {
            return true;
        }
    }
    return false;
}

// ----------------------------------------------------------
// 2) Distribuição de grau
// ----------------------------------------------------------
// TODO
vector<int> Graph::degreeDistribution() {
    vector<int> ans;
    bool first = true;
    for (const auto& node : nodes) {
        if (first) {
            first = false;
            continue;
        }
        size_t degree = node.adj.size();
        if (ans.capacity() < degree + 1)
            ans.resize(degree + 1, 0);
        ans[degree]++;
    }
    return ans;
}

// ----------------------------------------------------------
// 3) Mesmo componente conexo?
// ----------------------------------------------------------
// TODO
bool Graph::sameComponent(int a, int b) {
    bfs(a);
    return nodes[b].visited;
}

// ----------------------------------------------------------
// 4) Excentricidade
// ----------------------------------------------------------
// TODO
int Graph::eccentricity(int a) {
    if(nodes[a].adj.empty()) return -1;

    // Initialize the maximum distance from node a to any other node
    int maxDist = 0;

    // Perform Dijkstra's algorithm starting from node a
    dijkstra(a);

    // Find the maximum distance from node a to any other node
    for (int i = 1; i <= n; i++) {
        // Ignore nodes that are not reachable from node a
        if (nodes[i-1].dist == INT_MAX) {
            continue;
        }
        maxDist = max(maxDist, nodes[i-1].dist);
    }

    // Return -1 if there are unreachable nodes
    return maxDist == INT_MAX ? -1 : maxDist;

}
int Graph::bfs_meeting_point(int a, int b) {
    for (int v=1; v<=n; v++) {nodes[v].visited = false; nodes[v].dist = -1; nodes[v].color = 0;}
    queue<int> q; // queue of unvisited nodes
    q.push(a);
    nodes[a].visited = true;
    nodes[a].color = 1;
    q.push(b);
    nodes[b].visited = true;
    nodes[b].color = 2;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if ((nodes[w].color == 1 && nodes[u].color == 2) || (nodes[w].color == 2 && nodes[u].color == 1)) {
                return w;
            }
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].color = nodes[u].color;
            }
        }
    }
    cout << endl;
    return -1;
}

// ----------------------------------------------------------
// 5) Ponto de Encontro
// ----------------------------------------------------------
// TODO
int Graph::meetingPoint(int a, int b) {
    int index;
    bfs(a);
    int distance = nodes[b].dist;
    if (distance == -1) return -1;

    for (int i = 1; i < nodes.size(); i++) {
        if (i != a && i != b) {
            bfs(i);
            int custo = max(nodes[a].dist, nodes[b].dist);
            if (custo < distance) {
                distance = custo;
                index = i;
            }
        }
    }
    return index;
}

// ----------------------------------------------------------
// 6) Segunda melhor MST
// ----------------------------------------------------------
// TODO
int Graph::secondBestMST() {
    return 0;
}

// ----------------------------------------------------------
// 7) Transito complicado
// ----------------------------------------------------------
// TODO
list<int> Graph::traffic(int a, int b) {
    list<int> ans;
    return ans;
}
