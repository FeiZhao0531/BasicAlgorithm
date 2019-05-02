#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string intToString( int num) {

        string s = "";
        if( num == 0)
            return "0";

        bool positive = true;
        if( num < 0) {
            num = - num;
            positive = false;
        }

        while( num != 0) {
            s += '0' + num%10;
            num = num / 10;
        }
        if( positive == false)
            s += '-';

        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    int num;
    cout<<"Input your Integer: "<<endl;
    cin>>num;
    cout<<"Integer to String: "<<Solution().intToString(num)<<endl;
    return 0;
}
