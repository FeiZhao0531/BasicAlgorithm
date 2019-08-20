/// Template Class for Graph Algorithm to traverse a graph
///     and counting the numbers of components
/// Author: Fei
/// Create: Aug-19-2019
#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <iostream>
#include <cassert>

template <typename Graph>
class Component
{
private:
    Graph &G;
    bool *visited;
    int ccount; // nums of connected component
    int *id; // id of component( use to check whether given vertexes connected)

    void dfs( int v)
    {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj( G, v);
        for( int i = adj.begin(); !adj.end(); i = adj.next()) {
            if( !visited[i])
                dfs(i);
        }
    }

public:
    Component( Graph &graph) : G( graph)
    {
        visited = new bool[G.getNumsVertex()];
        id = new int[G.getNumsVertex()];
        ccount = 0;
        for( int i = 0; i < G.getNumsVertex(); ++ i) {
            visited[i] = false;
            id[i] = -1;
        }

        for( int i = 0; i < G.getNumsVertex(); ++ i) {
            if( !visited[i]) {
                dfs(i);
                ccount ++;
            }
        }
    }

    ~Component()
    {
        delete[] visited;
        delete[] id;
    }

    int count() const
    {
        return ccount;
    }

    bool isConnected( int v, int w)
    {
        assert( v >= 0 && v < G.getNumsVertex());
        assert( w >= 0 && w < G.getNumsVertex());
        return id[v] == id[w];
    }

};


#endif // COMPONENT_H_INCLUDED
