/// Dense Graph Class
/// Author: Fei
/// Create: Aug-18-2019

#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include <vector>

class DenseGraph
{
public:
    DenseGraph( int numsVertex, bool directed);
    virtual ~DenseGraph();

    int getNumsVertex() { return numsVertex;}
    int getNumsEdge() { return numsEdge;}

    void addEdge( int v, int w);

    bool hasEdge( int v, int w);

    void show();

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

        int begin()
        {
            index = -1;
            return next();
        }

        int next()
        {
            for( index ++; index < G.getNumsVertex(); ++ index)
                if( G.g[v][index])
                    return index;

            return -1;
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
    std::vector<std::vector<bool>>  g; // adjacent matrix

};

#endif // DENSEGRAPH_H
