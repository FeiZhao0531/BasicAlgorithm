/// Template Class for Graph Algorithm to traverse a graph
///     and show the path from a source vertex to a given vertex
/// Author: Fei
/// Create: Aug-19-2019
#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

using std::vector;
using std::stack;

template <typename Graph>
class Path
{
private:
    Graph &G;
    int s; /// source vertex
    bool* visited;
    int* from;

    void dfs( int v)
    {
        visited[v] = true;
        typename Graph::adjIterator adj( G, v);
        for( int i = adj.begin(); !adj.end(); i = adj.next()) {
            if( !visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    Path( Graph &graph, int s) : G( graph)
    {
        int n = G.getNumsVertex();
        assert( s >= 0 && s < n);
        visited = new bool[n];
        from = new int[n];

        this->s = s;
        for( int i = 0; i < n; ++ i) {
            visited[i] = false;
            from[i] = -1;
        }

        dfs( s);
    }

    ~Path()
    {
        delete[] visited;
        delete[] from;
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
};

#endif // PATH_H_INCLUDED
