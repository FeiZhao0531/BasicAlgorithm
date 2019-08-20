/// Template Class for Graph Algorithm to read a existing graph in .txt file
/// Author: Fei
/// Create: Aug-19-2019

#ifndef READGRAPH_H
#define READGRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

using std::string;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;

template <typename Graph>
class ReadGraph
{
public:
    ReadGraph( Graph &graph, const string &fileName) {

        //ctor
        ifstream    file( fileName);
        string      line;
        int         V; // nums of vertexes
        int         E; // nums of edges

        assert( file.is_open());
        assert( getline( file, line));
        stringstream ss( line);
        ss >> V >> E;
        //cout << "V = " << V << ", E = " << E << endl;

        assert( V == graph.getNumsVertex());

        for( int i = 0; i < E; ++ i)
        {

            assert( getline( file, line));
            stringstream ss( line);

            int v, w;
            ss >> v >> w;
            assert( v >= 0 && v < V);
            assert( w >= 0 && w < V);
            graph.addEdge( v, w);
        }

    }

protected:

private:
};

#endif // READGRAPH_H
