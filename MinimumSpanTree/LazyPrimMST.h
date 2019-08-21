#ifndef LAZYPRIMMST_H_INCLUDED
#define LAZYPRIMMST_H_INCLUDED

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "MinHeap.h"

using std::vector;

template<typename Graph, typename Weight>
class LazyPrimMST
{
private:
    Graph& G;
    MinHeap<Edge<Weight>> pq;
    bool* marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visited( int v)
    {
        assert( !marked[v]);
        marked[v] = true;

        typename Graph::adjIterator adj( G, v);
        for( Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
            if( !marked[e->other(v)])
                pq.insert( *e);
    }

public:
    LazyPrimMST( Graph& graph) : G( graph), pq( MinHeap<Edge<Weight>>(graph.getNumsEdge()))
    {
        int n = G.getNumsVertex();
        marked = new bool[n];
        for( int i = 0; i < n; ++ i)
            marked[i] = false;
        mst.clear();

        visited(0);
        while( !pq.isEmpty()) {
            Edge<Weight> e = pq.getMinItem();
            if( marked[e.v()] == marked[e.w()])
                continue;

            mst.push_back( e);
            if( !marked[e.v()])
                visited( e.v());
            else
                visited( e.w());
        }

        mstWeight = mst[0].wt();
        for( int i = 1; i < mst.size(); ++ i)
            mstWeight += mst[i].wt();
    }

    ~LazyPrimMST()
    {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges()
    {
        return mst;
    }

    Weight result()
    {
        return mstWeight;
    }
};

#endif // LAZYPRIMMST_H_INCLUDED
