#include<bits/stdc++.h>
using namespace std;


    // Binary Search is used to find the integer square root of x.
    // The search space is from 1 to x, and mid*mid is compared with x.
    // If mid*mid is smaller, search moves right; otherwise it moves left.
    // long long is used to prevent overflow while computing mid*mid.
    // When no exact square root exists, the floor value is stored in high.

    // Time Complexity: O(log x)
    // Space Complexity: O(1)
class Solution {
public:
    int mySqrt(int x) {

        if(x == 0) return 0;
        int low = 1, high = x;
        while(low <= high) {
            long long mid = low + (high - low) / 2;//make sure u use the long long datatype here else it will give an overflow
            if(mid * mid == x) {
                return mid;
            }

            else if(mid * mid < x) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return high;
    }
};

int main() {



    Solution s;

    int x = 17;

    cout << "Integer Square Root = "
         << s.mySqrt(x) << endl;

    return 0;
}