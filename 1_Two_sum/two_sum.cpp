#include <bits/stdc++.h>
using namespace std;

/*
Overview:
We need to find two indices such that their elements add up to the target.
We use a hash map to store each number and its index while traversing once.
For every element, we check if its complement (target - current value) exists.
Time Complexity: O(n), Space Complexity: O(n).
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // stores value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // store current element with its index
            mp[nums[i]] = i;
        }

        return {}; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}