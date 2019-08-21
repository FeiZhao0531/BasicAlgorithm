#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Edge.h"
#include "LazyPrimMST.h"

using namespace std;

int main()
{
    string fileName = "testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);

    /// test case for SparseGraph
    SparseGraph<double> g1S = SparseGraph<double>( V, false);
    ReadGraph<SparseGraph<double>, double> readGraph1S( g1S, fileName);
    g1S.show();
    cout << endl;

    cout << "Test Lazy Prim MST:" << endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMSt( g1S);
    vector<Edge<double>> mst = lazyPrimMSt.mstEdges();
    for( int i = 0; i < mst.size(); ++ i)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << lazyPrimMSt.result() << endl;

    return 0;
}
