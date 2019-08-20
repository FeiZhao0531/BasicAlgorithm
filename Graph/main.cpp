#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;

int main()
{
    string fileName1 = "testG1.txt";
    SparseGraph g1S( 13, false);
    ReadGraph<SparseGraph> readGraphG1S( g1S, fileName1);
    Component<SparseGraph> componentG1S( g1S);
    //g1S.show();
    cout << "TestG1.txt, Component Count = " << componentG1S.count() << endl;

    string fileName2 = "testG2.txt";
    SparseGraph g2S( 7, false);
    ReadGraph<SparseGraph> readGraphG2S( g2S, fileName2);
    g2S.show();
    cout << endl;

    Path<SparseGraph> pathG2S( g2S, 0);
    cout << "DFS : ";
    pathG2S.showPath(6);

    ShortestPath<SparseGraph> shortPathG2S( g2S, 0);
    cout << "BFS : ";
    shortPathG2S.showPath(6);

    return 0;
}

//int main()
//{
//    int N = 20;
//    int M = 100;
//    srand( time(NULL));
//
//    SparseGraph g1( N, false);
//    DenseGraph g2( N, false);
//
//    for( int i = 0; i < M; ++ i) {
//        int v = rand() % N;
//        int w = rand() % N;
//        g1.addEdge( v, w);
//        g2.addEdge( v, w);
//    }
//
//    /// O( E)
//    for( int v = 0; v < N; ++ v) {
//        cout << v << " : ";
//        SparseGraph::adjIterator adj( g1, v);
//        for( int w = adj.begin(); !adj.end(); w = adj.next())
//            cout << w << " ";
//        cout << endl;
//    }
//    cout << endl;
//
//    /// O( N^2)
//    for( int v = 0; v < N; ++ v) {
//        cout << v << " : ";
//        DenseGraph::adjIterator adj( g2, v);
//        for( int w = adj.begin(); !adj.end(); w = adj.next())
//            cout << w << " ";
//        cout << endl;
//    }
//    cout << endl;
//
//    return 0;
//}
