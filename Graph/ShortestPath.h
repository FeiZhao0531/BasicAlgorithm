/// Template Class for Graph Algorithm to traverse a graph
///     and show the shortest path from a source vertex to a given vertex
/// Author: Fei
/// Create: Aug-20-2019
#ifndef SHORTESTPATH_H_INCLUDED
#define SHORTESTPATH_H_INCLUDED

#include <iostream>
#include <cassert>
#include <queue>
#include <vector>

using std::vector;
using std::queue;

template <typename Graph>
class ShortestPath
{
private:
    Graph& G;
    int s; /// source vertex
    bool* visited;
    int* from;
    int* order;

public:
    ShortestPath( Graph& graph, int s) : G( graph)
    {
        int n = G.getNumsVertex();
        assert( s >= 0 && s < n);
        visited = new bool[n];
        from = new int[n];
        order = new int[n];

        this->s = s;
        for( int i = 0; i < n; ++ i) {
            visited[i] = false;
            from[i] = -1;
            order[i] = -1;
        }

        queue<int> q;
        q.push( s);
        visited[s] = true;
        order[s] = 0;
        while( !q.empty()) {
            int v = q.front();
            q.pop(); /// Don't forget pop()!!!

            typename Graph::adjIterator adj( G, v);
            for( int w = adj.begin(); !adj.end(); w = adj.next()) {
                if( !visited[w]) {
                    q.push( w);
                    visited[w] = true;
                    from[w] = v;
                    order[w] = order[v] + 1;
                }
            }
        }

    }

    ~ShortestPath()
    {
        delete[] visited;
        delete[] from;
        delete[] order;
    }

    bool hasPath( int w)
    {
        assert( w >= 0 && w < G.getNumsVertex());
        return visited[w];
    }

    void path( int v, vector<int>& vec)
    {
        stack<int> st;
        int p = v;
        while( p != -1) {
            st.push( p);
            p = from[p];
        }

        vec.clear();
        while( !st.empty()) {
            vec.push_back( st.top());
            st.pop();
        }
    }

    void showPath( int w)
    {
        vector<int> vec;
        path( w, vec);
        for( int i = 0; i < (int)vec.size(); ++ i) {
            cout << vec[i];
            if( i == vec.size() - 1)
                cout << endl;
            else
                cout << " -> ";
        }
    }

    int length( int w)
    {
        assert( w >= 0 && w < G.getNumsVertex());
        return order[w];
    }
};

#endif // SHORTESTPATH_H_INCLUDED
