#include <bits/stdc++.h>
using namespace std;

/*
Find the element that appears only once in an array where all others appear twice.
Using XOR: equal numbers cancel out (a ^ a = 0), and 0 ^ x = x.
So XORing all elements leaves the single unique number.
Time Complexity: O(n), Space Complexity: O(1)
*/

//it's something similar as we did in 268_Missing_number
int singleNumber(vector<int>& nums) {
    int xorr = 0;

    for (int i = 0; i < nums.size(); i++) {
        xorr ^= nums[i];       //it looks like 0^1^1^2^3^3  = 0^0^2^0= 2
    }

    return xorr;  // returns 2
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
}


