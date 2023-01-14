// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include <algorithm>
#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}


// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
// TODO
int Graph::outDegree(int v) {
    if(v < 1  || v > n) return -1;
    return (int) nodes[v].adj.size();
}

// ..............................
// b) Devolvendo o grau... pesado
// TODO
int Graph::weightedOutDegree(int v) {
    if(v < 1  || v > n) return -1;
    int cont = 0;
    for(auto edge : nodes[v].adj){
        cont += edge.weight;
    }
    return cont;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!nodes[i].visited){
            dfs(i);
            count++;
        }
    }
    return count;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    for (int i =1; i<= n; i++){
        nodes[i].visited= false;
    }
    int maiorComp = -200, comp = 1;
    for(int i = 1; i <= n; i++){
        if(!nodes[i].visited){
            dfs(i);
            comp = 1;
        }else{
            comp++;
        }
        if(comp > maiorComp){
            maiorComp = comp;
        }
    }
    return maiorComp;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
void Graph::topSort(int v, list<int> &result){
    if(nodes[v].visited)return;
    nodes[v].visited = true;
    for(auto edge: nodes[v].adj){
        topSort(edge.dest,result);
    }
    result.push_front(v);
}
list<int> Graph::topologicalSorting() {
    list<int> order;
    for(int i = 1; i <= n; i++){
        if(!nodes[i].visited){
            topSort(i,order);
        }
    }
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    bool flag= false;
    for (int i=1; i <= n ; i++){
        nodes[i].color="white";
        nodes[i].visited=false;
    }
    for (int i=1; i<=n ; i++){
        if (nodes[i].color=="white"){
            finaldfs(i, flag);
        }
    }
    return flag;
}
void Graph::finaldfs(int v, bool &flag) {
    nodes[v].color="gray";
    for (auto e: nodes[v].adj){
        int w = e.dest;
        if (nodes[w].color=="gray"){
            flag=true;
        }
        else{
            finaldfs(w,flag);
        }
    }
    nodes[v].color="black";
}