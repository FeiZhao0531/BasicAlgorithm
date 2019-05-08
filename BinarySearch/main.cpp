///  Binary search
///  author: Fei Zhao
///  creating time: May-6-2019

#include <iostream>
using namespace std;

class Solution {
public:
    int binarySearch( int arr[], int n, int target) {

        int l = 0, r = n-1; // in the range of arr[l,r] to find the target
        while( l <= r) {
            int mid = l + 0.5*( r - l);
            if( arr[mid] > target)
                r = mid - 1;
            else if( arr[mid] < target)
                l = mid + 1;
            else
                return mid;
        }
        throw invalid_argument("No target in this arr");
        return -1;
    }
};

int main() {

    int arr[] = {0,1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    int target1 = 5, target2 = 7;
    cout<<"The index of "<<target1<<" in arr is "<<Solution().binarySearch(arr,n,target1)<<endl;
    cout<<"The index of "<<target2<<" in arr is "<<Solution().binarySearch(arr,n,target2)<<endl;

    return 0;
}
