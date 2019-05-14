///  heapSort
///  Author: Fei
///  Creating time: May-14-2019

#include <iostream>
using namespace std;

class Solution {

public:
    void heapSort( int arr[], int n) {

        // heaplify
        for( int i=(n-1-1)/2; i>=0; --i)
            __shiftDown2( arr, n, i);

        // swap arr[0] and the last unSorted element arr[i]
        for( int i=n-1; i>=1; --i) {
            swap( arr[0], arr[i]);
            __shiftDown2( arr, i, 0);
        }
    }

private:

    void __shiftDown( int arr[], int n, int k) {

        while( 2*k + 1 < n) {
            int index = 2*k + 1;
            if( index + 1 < n && arr[index] < arr[index+1])
                index += 1;
            if( arr[k] > arr[index])
                return;

            swap( arr[k], arr[index]);
            k = index;
        }
    }

    void __shiftDown2( int arr[], int n, int k) {

        int tmp = arr[k];
        while( 2*k + 1 < n) {
            int index = 2*k + 1;
            if( index + 1 < n && arr[index] < arr[index+1])
                index += 1;
            if( tmp > arr[index])
                return;

            arr[k] = arr[index];
            k = index;
        }
        arr[k] = tmp;
    }
};

int main()
{
    int arr[] = { 5,6,2,4,7,8,9,1,3};
    int len = sizeof(arr) / sizeof(int);
    Solution().heapSort( arr, len);

    for( int i=0; i<len; ++i)
        cout<<arr[i]<<", ";
    cout<<endl;
    return 0;
}
