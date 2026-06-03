#include<bits/stdc++.h>
using namespace std;


    // Traverse the array from both left and right simultaneously.
    // Prefix and suffix products help handle negative numbers and zeros.
    // Whenever a product becomes zero, reset it to start a new subarray.
    // The maximum among all prefix and suffix products gives the answer.
    // Time Complexity: O(n), Space Complexity: O(1)

/*The logic is based on the concept of if (even -ve) then the just checking with 0 can be done and the answer can be found but of (odd -ve) we r using prefix and suffix multiplication and that's only because for (one -ve) val  the remaining number of -ve will be even........ */
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int prefix = 1, suffix = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            //0 is the breaking point in the array because multiplying any number after that will give 0 only
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            
            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            ans = max(ans, max(prefix, suffix));
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum Product Subarray = "
         << s.maxProduct(nums);

    return 0;
}