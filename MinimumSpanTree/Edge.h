/// Template Class for the Edges in Weighted Graph Algorithm
/// Author: Fei
/// Create: Aug-20-2019
#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

template<typename Weight>
class Edge
{
private:
    int a; /// vertex a
    int b; /// vertex b
    Weight weight; /// weight of edge between a and b

public:
    Edge( int a, int b, Weight weight)
    {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge(){}

    ~Edge(){}

    int v() { return a;}

    int w() { return b;}

    Weight wt() { return weight;}

    int other( int x)
    {
        assert( x == a || x == b);
        return x == a ? b : a;
    }

    friend ostream& operator<<( ostream& os, const Edge& e)
    {
        os << e.a << " - " << e.b <<" : " << e.weight;
        return os;
    }

    bool operator<( Edge<Weight>& e) { return weight < e.wt();}

    bool operator<=( Edge<Weight>& e) { return weight <= e.wt();}

    bool operator>( Edge<Weight>& e) { return weight > e.wt();}

    bool operator>=( Edge<Weight>& e) { return weight >= e.wt();}

    bool operator==( Edge<Weight>& e) { return weight == e.wt();}
};

#endif // EDGE_H_INCLUDED
