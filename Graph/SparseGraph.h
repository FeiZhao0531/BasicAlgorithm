/// Sparse Graph Class
/// Author: Fei
/// Create: Aug-18-2019

#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include <vector>

class SparseGraph
{
public:
    SparseGraph( int numsVertex, bool directed);
    virtual ~SparseGraph();

    int getNumsVertex() { return numsVertex;}
    int getNumsEdge() { return numsEdge;}

    void addEdge( int v, int w);

    bool hasEdge( int v, int w);

    void show();

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

        int begin()
        {
            if( G.g[v].size())
                return G.g[v][0];

            return -1;
        }

        int next()
        {
            index ++;
            if( index < (int)G.g[v].size())
                return G.g[v][index];

            return -1;
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
    std::vector<std::vector<int>>   g; // adjacent table

};

#endif // SPARSEGRAPH_H
