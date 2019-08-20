#include "DenseGraph.h"
#include <cassert>
#include <iostream>
using namespace std;

DenseGraph::DenseGraph( int numsVertex, bool directed)
{
    //ctor
    this->numsVertex = numsVertex;
    this->numsEdge = 0;
    this->directed = directed;

    for( int i = 0; i < numsVertex; ++ i)
        g.push_back( vector<bool>( numsVertex, false));
}

DenseGraph::~DenseGraph()
{
    //dtor
}

void DenseGraph::addEdge( int v, int w)
{
    assert( v >= 0 && v < numsVertex);
    assert( w >= 0 && w < numsVertex);

    if( hasEdge( v, w))
        return;

    g[v][w] = true;
    numsEdge ++;
    if( !directed)
        g[w][v] = true;

    return;
}

bool DenseGraph::hasEdge( int v, int w)
{
    assert( v >= 0 && v < numsVertex);
    assert( w >= 0 && w < numsVertex);
    return g[v][w];
}

void DenseGraph::show()
{
    for( int i = 0; i < numsVertex; ++ i) {
        for( int j = 0; j < numsVertex; ++ j)
            cout << g[i][j] << "\t";
        cout << endl;
    }
}
