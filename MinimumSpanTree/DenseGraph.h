/// Dense Weighted Graph Class
/// Author: Fei
/// Create: Aug-20-2019

#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include <vector>
#include <cassert>
#include <iostream>
#include "Edge.h"

using std::vector;
using std::cout;
using std::endl;

template <typename Weight>
class DenseGraph
{
public:
    DenseGraph( int numsVertex, bool directed)
    {
        //ctor
        this->numsVertex = numsVertex;
        this->numsEdge = 0;
        this->directed = directed;

        for( int i = 0; i < numsVertex; ++ i)
            g.push_back( vector<Edge<Weight>*>( numsVertex, NULL));
    }

    virtual ~DenseGraph()
    {
        //dtor
        for( int i = 0; i < numsVertex; ++ i) {
            for( int j = 0; j < numsVertex; ++ j) {
                if( g[i][j] != NULL) {
                    delete g[i][j];
                    g[i][j] = NULL;
                }
            }
        }
    }

    int getNumsVertex() { return numsVertex;}
    int getNumsEdge() { return numsEdge;}

    void addEdge( int v, int w, Weight weight)
    {
        assert( v >= 0 && v < numsVertex);
        assert( w >= 0 && w < numsVertex);

        if( hasEdge( v, w)) {
            delete g[v][w];
            if( !directed)
                delete g[w][v];

            numsEdge --;
        }

        g[v][w] = new Edge<Weight>( v, w, weight);
        numsEdge ++;
        if( !directed)
            g[w][v] = new Edge<Weight>( w, v, weight);

        return;
    }

    bool hasEdge( int v, int w)
    {
        assert( v >= 0 && v < numsVertex);
        assert( w >= 0 && w < numsVertex);
        return g[v][w] != NULL;
    }

    void show()
    {
        for( int i = 0; i < numsVertex; ++ i) {
            for( int j = 0; j < numsVertex; ++ j)
                if( g[i][j])
                    cout << g[i][j]->wt() << "\t";
                else
                    cout << "NULL\t";

            cout << endl;
        }
    }

    /// Iterator for vertex
    class adjIterator
    {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator( DenseGraph &graph, int v) : G( graph)
        {
            this->v = v;
            this->index = -1;
        }

        Edge<Weight>* begin()
        {
            index = -1;
            return next();
        }

        Edge<Weight>* next()
        {
            for( index ++; index < G.getNumsVertex(); ++ index)
                if( G.g[v][index])
                    return G.g[v][index];

            return NULL;
        }

        bool end()
        {
            return index >= G.getNumsVertex();
        }
    };

protected:

private:
    int                             numsVertex;
    int                             numsEdge;
    bool                            directed; // whether directed graph
    vector<vector<Edge<Weight>* >>  g; // adjacent matrix

};
#endif // DENSEGRAPH_H
