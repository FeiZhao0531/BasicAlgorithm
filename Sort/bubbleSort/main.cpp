#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void bubbleSort( vector<int>& arr, int len) {

    for( int i=0; i<len; ++i) {
        for( int j=0; j<len-i-1; ++j) {
            if( arr[j] > arr[j+1])
                swap( arr[j], arr[j+1]);
                /*
                int tmp = arr[j+1];
                a[j+1] = arr[j];
                a[j] = tmp;
                */
        }
    }
    return;
}

int main()
{
    int nums[] = { 5,3,9,4,1,7,9,6};
    int len = sizeof(nums)/sizeof(int);
    vector<int> arr( nums, nums+len);
    bubbleSort( arr, len);
    for( int i=0; i<len; ++i)
        cout<<arr[i]<<", ";
    cout<<endl;
    return 0;
}
