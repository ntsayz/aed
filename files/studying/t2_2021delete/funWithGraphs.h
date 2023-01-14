// AED 2021/2022 - CI2 - Parte Prática
// Pedro Ribeiro (DCC/FCUP) [12/02/2022]

#ifndef _FUNGRAPHS_H_
#define _FUNGRAPHS_H_

#include "graph.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class FunWithGraphs {
    static Graph *g;
    static map<string, int> index;

public:
    // Some example graphs
    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();
    static Graph graph5();
};

#endif
