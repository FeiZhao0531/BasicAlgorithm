#include <iostream>
using namespace std;

void selectionSort( int arr[], int len) {

    for( int i=0; i<len-1; ++i) {
        int minIndex = i;
        for( int j=i+1; j<len; ++j){
            if( arr[j] < arr[minIndex])
                minIndex = j;
        }
        if( i != minIndex)
            swap( arr[i], arr[minIndex]);
    }
    return;
}

int main()
{
    int arr[] = { 8,3,6,9,1,7,2};
    int len = sizeof(arr)/sizeof(int);
    selectionSort( arr, len);
    for( int i=0; i<len; ++i)
        cout<<arr[i]<<", ";
    cout<<endl;
    return 0;
}
