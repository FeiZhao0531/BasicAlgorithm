/// Sparse Weighted Graph Class
/// Author: Fei
/// Create: Aug-20-2019

#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using std::vector;
using std::cout;
using std::endl;

template <typename Weight>
class SparseGraph
{
public:
    SparseGraph( int numsVertex, bool directed)
    {
        //ctor
        this->numsVertex = numsVertex;
        this->numsEdge = 0;
        this->directed = directed;

        for( int i = 0; i < numsVertex; ++ i)
            g.push_back( vector<Edge<Weight>*>());
    }

    virtual ~SparseGraph()
    {
        for( int i = 0; i < numsVertex; ++ i)
            for( int j = 0; j < g[i].size(); ++ j)
                delete g[i][j];
    }

    int getNumsVertex() { return numsVertex;}
    int getNumsEdge() { return numsEdge;}

    void addEdge( int v, int w, Weight weight)
    {
        assert( v >= 0 && v < numsVertex);
        assert( w >= 0 && w < numsVertex);

        g[v].push_back( new Edge<double>( v, w, weight));
        numsEdge ++;
        if( v != w && !directed)
            g[w].push_back( new Edge<double>( w, v, weight));

        return;
    }

    bool hasEdge( int v, int w)
    {
        assert( v >= 0 && v < numsVertex);
        assert( w >= 0 && w < numsVertex);

        for( int i = 0; i < (int)g[v].size(); ++ i)
            if( g[v][i]->other(v) == w)
                return true;

        return false;
    }

    void show()
    {
        for( int i = 0; i < numsVertex; ++ i) {
            cout << "vertex " << i << ":\t";
            for( int j = 0; j < (int)g[i].size(); ++ j)
                cout << "(to:" << g[i][j]->w() << ", wt:" << g[i][j]->wt() << ")\t";
            cout << endl;
        }
    }

    class adjIterator
    {
    private:
        SparseGraph &G;
        int v;
        int index = 0;
    public:
        adjIterator( SparseGraph &graph, int v) : G( graph)
        {
            this->v = v;
            this->index = 0;
        }

        Edge<Weight>* begin()
        {
            if( G.g[v].size())
                return G.g[v][0];

            return NULL;
        }

        Edge<Weight>* next()
        {
            index ++;
            if( index < (int)G.g[v].size())
                return G.g[v][index];

            return NULL;
        }

        bool end()
        {
            return index >= (int)G.g[v].size();
        }
    };

protected:

private:
    int                             numsVertex;
    int                             numsEdge;
    bool                            directed; // whether directed graph
    vector<vector<Edge<Weight>*>>   g; // adjacent table

};
#endif // SPARSEGRAPH_H
