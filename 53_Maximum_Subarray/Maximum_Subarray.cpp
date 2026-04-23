#include <bits/stdc++.h>
using namespace std;


/*
Kadane’s Algorithm finds the maximum subarray sum by maintaining a running sum.
If the sum becomes negative, it resets to 0 since it won’t help future subarrays.
Time Complexity: O(n) Space Complexity: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxx = INT_MIN;    // assigned as minus infinity for the first maximum check

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxx = max(maxx, sum);

            if(sum < 0){   /* if current sum is less than 0 then in future if it is added to any of the number it will  never give the maximum*/
                sum = 0;
            }
        }
        return maxx;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = obj.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}

