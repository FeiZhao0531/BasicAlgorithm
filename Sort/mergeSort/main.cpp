///  merge sort
///  author: Fei Zhao
///  creating time: May-5-2019

#include <iostream>
using namespace std;

class Solution{
public:
    void mergeSort( int arr[], int tmp[], int low, int high){

        if( high > low) {
            int mid = low + ( high - low) / 2;
            mergeSort( arr, tmp, low, mid);
            mergeSort( arr, tmp, mid+1, high);
            mergeArrays( arr, tmp, low, mid, high);
        }
        return;
    }

private:
    void mergeArrays( int arr[], int tmp[], int low, int mid, int high){

        int i = low;
        int j = mid+1;
        int k = low;

        while( i <= mid && j <= high) {
            if( arr[i] < arr[j])
                tmp[k ++] = arr[i ++];
            else if( arr[i] > arr[j])
                tmp[k ++] = arr[j ++];
            else {
                tmp[k ++] = arr[i ++];
                tmp[k ++] = arr[j ++];
            }
        }
        while( i <= mid)
            tmp[k ++] = arr[i ++];
        while( j <= high)
            tmp[k ++] = arr[j ++];

        for( int i=low; i <= high; ++i)
            arr[i] = tmp[i];

        return;
    }

};

int main()
{
    int arr[] = { 5,6,2,4,7,8,9,1,3};
    int len = sizeof(arr) / sizeof(int);
    int tmp[len];
    Solution().mergeSort( arr, tmp, 0, len-1);

    for( int i=0; i<len; ++i)
        cout<<arr[i]<<", ";
    cout<<endl;
    return 0;
}
