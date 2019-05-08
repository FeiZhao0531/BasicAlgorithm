///  insertion sort
///  author: Fei Zhao
///  creating time: May-3-2019

#include <iostream>
using namespace std;

void insertSort( int arr[], int len) {

    for( int i=1; i<len; ++i) {
        int tmp = arr[i];
        int index = i - 1;
        while( index >= 0 && tmp < arr[index]) {
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = tmp;
    }
    return;
}

int main()
{
    int arr[] = { 5,3,9,4,1,7,9,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertSort( arr, len);
    for(int i=0; i<len; ++i)
        cout<<arr[i]<<", ";
    cout<<endl;
    return 0;
}
