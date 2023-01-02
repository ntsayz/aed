// AED 2021/2022 - CI2 - Parte Prática
// Pedro Ribeiro (DCC/FCUP) [12/02/2022]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "graph.h"
#include "funWithGraphs.h"
#include "minHeap.h"

using testing::Eq;

// ----------------------------------------------------------
// 1) Existencia de ligacao
// ----------------------------------------------------------
TEST(test1, hasEdge) {
    cout << "Testando 'hasEdge'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_TRUE(g1.hasEdge(1,2));
    EXPECT_TRUE(g1.hasEdge(1,3));
    EXPECT_FALSE(g1.hasEdge(1,4));
    EXPECT_TRUE(g1.hasEdge(4,5));
    EXPECT_TRUE(g1.hasEdge(5,4));
    EXPECT_TRUE(g1.hasEdge(5,6));
    EXPECT_TRUE(g1.hasEdge(5,6));
    EXPECT_FALSE(g1.hasEdge(5,8));
    EXPECT_FALSE(g1.hasEdge(5,9));

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_TRUE(g2.hasEdge(1,2));
    EXPECT_FALSE(g2.hasEdge(2,1));
    EXPECT_TRUE(g2.hasEdge(8,7));
    EXPECT_TRUE(g2.hasEdge(7,5));
    EXPECT_FALSE(g2.hasEdge(5,4));
    EXPECT_TRUE(g2.hasEdge(5,6));
    EXPECT_FALSE(g2.hasEdge(6,9));
    EXPECT_TRUE(g2.hasEdge(5,6));
    EXPECT_FALSE(g2.hasEdge(6,9));
}

// ----------------------------------------------------------
// 2) Distribuição de grau
// ----------------------------------------------------------
TEST(test2, degreeDistribution) {
    cout << "Testando 'degreeDistribution'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    vector<int> dd1 = {0,2,5,2};
    EXPECT_EQ(g1.degreeDistribution(), dd1);

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    vector<int> dd3 = {0,2,7};
    EXPECT_EQ(g3.degreeDistribution(), dd3);
}

// ----------------------------------------------------------
// 3) Mesmo componente conexo?
// ----------------------------------------------------------
TEST(test3, sameComponent) {
    cout << "Testando 'sameComponent'" << endl;

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_TRUE(g3.sameComponent(1,2));
    EXPECT_TRUE(g3.sameComponent(1,3));
    EXPECT_TRUE(g3.sameComponent(3,2));
    EXPECT_TRUE(g3.sameComponent(4,5));
    EXPECT_TRUE(g3.sameComponent(5,4));
    EXPECT_TRUE(g3.sameComponent(6,9));
    EXPECT_TRUE(g3.sameComponent(9,8));
    EXPECT_TRUE(g3.sameComponent(8,7));
    EXPECT_TRUE(g3.sameComponent(7,6));
    EXPECT_FALSE(g3.sameComponent(1,4));
    EXPECT_FALSE(g3.sameComponent(5,1));
    EXPECT_FALSE(g3.sameComponent(6,2));
    EXPECT_FALSE(g3.sameComponent(7,2));
}

// ----------------------------------------------------------
// 4) Excentricidade
// ----------------------------------------------------------
TEST(test4, eccentricity) {
    cout << "Testando 'eccentricity'" << endl;

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(17, g4.eccentricity(1));
    EXPECT_EQ(16, g4.eccentricity(2));
    EXPECT_EQ(11, g4.eccentricity(3));
    EXPECT_EQ(15, g4.eccentricity(4));
    EXPECT_EQ(12, g4.eccentricity(5));

    cout << "  . graph5" << endl;
    Graph g5 = FunWithGraphs::graph5();
    EXPECT_EQ(-1, g5.eccentricity(1));
    EXPECT_EQ(-1, g5.eccentricity(2));
    EXPECT_EQ(-1, g5.eccentricity(3));
    EXPECT_EQ(-1, g5.eccentricity(4));

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(5, g1.eccentricity(1));
    EXPECT_EQ(4, g1.eccentricity(2));
    EXPECT_EQ(4, g1.eccentricity(3));
    EXPECT_EQ(3, g1.eccentricity(4));
}

// ----------------------------------------------------------
// 5) Ponto de Encontro
// ----------------------------------------------------------
TEST(test5, meeetingPoing) {
    cout << "Testando 'meetingPoint'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(4, g1.meetingPoint(1,6));
    EXPECT_EQ(5, g1.meetingPoint(4,7));
    EXPECT_EQ(6, g1.meetingPoint(5,9));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(-1, g3.meetingPoint(4,6));
    EXPECT_EQ(-1, g3.meetingPoint(1,5));

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(6, g4.meetingPoint(1,7));
    EXPECT_EQ(6, g4.meetingPoint(5,7));
    EXPECT_EQ(2, g4.meetingPoint(5,1));
}

// ----------------------------------------------------------
// 6) Segunda melhor MST
// ----------------------------------------------------------
TEST(test6, secondBestMST) {
    cout << "Testando 'secondBestMST'" << endl;

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(28, g4.secondBestMST());
}

// ----------------------------------------------------------
// 7) Transito complicado
// ----------------------------------------------------------
TEST(test7, secondBestMST) {
    cout << "Testando 'traffic'" << endl;

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    list<int> ans;
    ans = {4,1,2,5}; EXPECT_EQ(ans, g4.traffic(4,5));
    ans = {6,5,2,3}; EXPECT_EQ(ans, g4.traffic(6,3));
    ans = {2,5,6,7}; EXPECT_EQ(ans, g4.traffic(2,7));
}