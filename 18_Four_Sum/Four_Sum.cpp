#include<bits/stdc++.h>
using namespace std;




    // Sort the array and reduce 4Sum into 3Sum by fixing one element.
    // Remaining 3Sum is solved using the two-pointer technique efficiently.
    // Duplicate values are skipped to avoid repeated quadruplets.
    // Time Complexity: O(n^3), Space Complexity: O(1) excluding output vector.




    /*The 3sum logic is the saem just we r sending the numbers one by one in the main 4sum function*/

class Solution {
public:

    void threesum(vector<int>& nums,
                  vector<vector<int>>& ans,
                  long long target,
                  int start,
                  int first) {

        for(int j = start; j < (int)nums.size() - 2; j++) {

            if(j > start && nums[j] == nums[j-1]) continue;

            int index = j + 1;
            int n = nums.size() - 1;

            while(index < n) {

                long long sum =
                (long long)nums[j] + nums[index] + nums[n];

                int s = nums[index];
                int e = nums[n];

                if(sum == target) {

                    ans.push_back({
                        nums[first],
                        nums[j],
                        nums[index],
                        nums[n]
                    });

                    while(index < n && nums[index] == s) {
                        index++;
                    }

                    while(index < n && nums[n] == e) {
                        n--;
                    }
                }

                else if(sum < target) {

                    while(index < n && nums[index] == s) {
                        index++;
                    }
                }

                else {

                    while(index < n && nums[n] == e) {
                        n--;
                    }
                }
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        if(nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < (int)nums.size() - 3; i++) {

            if(i > 0 && nums[i] == nums[i-1]) continue;

            long long newtarget =
            (long long)target - nums[i];

            threesum(nums, ans, newtarget, i+1, i);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,0,-1,0,-2,2};

    int target = 0;

    vector<vector<int>> ans = s.fourSum(nums, target);

    for(auto v : ans) {

        for(int x : v) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}


/*Th challenge i faced was that i was using (int) in nums.size() which was leading to underflow condition and using (int)nums.size() resolved it*/