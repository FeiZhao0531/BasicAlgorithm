#include "SparseGraph.h"
#include <cassert>
#include <iostream>

using namespace std;

SparseGraph::SparseGraph( int numsVertex, bool directed)
{
    //ctor
    this->numsVertex = numsVertex;
    this->numsEdge = 0;
    this->directed = directed;

    for( int i = 0; i < numsVertex; ++ i)
        g.push_back( vector<int>());
}

SparseGraph::~SparseGraph()
{
    //dtor
}

void SparseGraph::addEdge( int v, int w)
{
    assert( v >= 0 && v < numsVertex);
    assert( w >= 0 && w < numsVertex);

    g[v].push_back( w);
    numsEdge ++;
    if( v != w && !directed)
        g[w].push_back( v);

    return;
}

bool SparseGraph::hasEdge( int v, int w)
{
    assert( v >= 0 && v < numsVertex);
    assert( w >= 0 && w < numsVertex);

    for( int i = 0; i < (int)g[v].size(); ++ i)
        if( g[v][i] == w)
            return true;

    return false;
}

void SparseGraph::show()
{
    for( int i = 0; i < numsVertex; ++ i) {
        cout << "vertex " << i << ":\t";
        for( int j = 0; j < (int)g[i].size(); ++ j)
            cout << g[i][j] << "\t";
        cout << endl;
    }
}
