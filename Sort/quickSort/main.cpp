///  quick Sort
///  author: Fei Zhao
///  creating time: May-5-2019
#include <iostream>
using namespace std;

class quickSort {
public:
    void threeWaysQuickSort( int arr[], int low, int high) {

        if( low >= high)
            return;

        int l = low - 1, // arr[ low, l] < pivot
            r = high + 1, // arr[ r, high] > pivot
            i = low + 1; // arr[ l+1, i-1] = pivot
        int pivot = arr[low]; // random index = rand()%( high - low + 1) + low
        while( i < r) {
            if( arr[i] > pivot) {
                swap( arr[i], arr[r-1]);
                r --;
            }
            else if( arr[i] < pivot) {
                swap( arr[i], arr[l+1]);
                l ++;
                i ++;
            }
            else
                i ++;
        }
        threeWaysQuickSort( arr, low, l);
        threeWaysQuickSort( arr, r, high);
        return;
    }

    void twoWaysQuickSort( int arr[], int low, int high) {

        if( low >= high)
            return;
        int l = low, r = high;
        int pivot = arr[low];
        while( l < r) {
            while( l < r && arr[r] >= pivot)
                r--;
            arr[l] = arr[r];
            while( l < r && arr[l] <= pivot)
                l ++;
            arr[r] = arr[l];
        }
        arr[l] = pivot;
        twoWaysQuickSort( arr, low, l-1);
        twoWaysQuickSort( arr, l+1, high);
        return;
    }
};

int main()
{
    //int arr[] = { 1,2,3,4,5,6,7,8,9};
    int arr[] = { 2,4,8,6,9,7,3,5,1};
    int len = sizeof( arr) / sizeof( int);
    //quickSort().twoWaysQuickSort( arr, 0, len-1);
    quickSort().threeWaysQuickSort( arr, 0, len-1);

    for( int i=0; i<len; ++i)
        cout<<arr[i]<<", ";
    cout<<endl;
    return 0;
}
