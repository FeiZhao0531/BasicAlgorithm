/// Create template class of Min Heap
/// Author: Fei
/// Create: Aug-20-2019

#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

#include <iostream>
#include <cassert>
#include <algorithm>

template<typename Item>
class MinHeap
{
private:
    Item*   data;
    int     capacity;
    int     counts;

    void shiftDown( int k)
    {
        while( 2 * k <= counts) {
            int j = 2 * k;
            if( j + 1 <= counts && data[j + 1] < data[j])
                j ++;

            if( data[k] <= data[j])
                break;
            else {
                std::swap( data[k], data[j]);
                k = j;
            }
        }
    }

    void shiftUp( int k)
    {
        while( k > 1 && data[k] < data[k / 2]) {
            std::swap( data[k], data[k / 2]);
            k /= 2;
        }
    }

public:
    MinHeap( int capacity)
    {
        this->capacity = capacity;
        data = new Item[capacity + 1];
        counts = 0;
    }

    MinHeap( Item arr[], int n)
    {
        data = new Item[n + 1];
        for( int i = 0; i < n; ++ i)
            data[i + 1] = arr[i];

        capacity = n + 1;
        counts = n;

        for( int i = counts / 2; i >= 1; -- i)
            shiftDown(i);
    }

    ~MinHeap()
    {
        delete[] data;
        data = NULL;
    }

    int size() { return counts;}

    bool isEmpty() { return 0 == counts;}

    void insert( Item item)
    {
        assert( counts + 1 <= capacity);
        data[counts + 1] = item;
        counts ++;
        shiftUp( counts);
    }

    Item getMinItem()
    {
        assert( counts >= 1);
        Item res = data[1];
        std::swap( data[1], data[counts]);
        counts --;
        shiftDown(1);

        return res;
    }

};

#endif // MINHEAP_H_INCLUDED
