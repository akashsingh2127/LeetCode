#include<bits/stdc++.h>
using namespace std;

    // A sorted and rotated array can have at most one position where nums[i] > nums[i+1].
    // Traverse the array circularly and count such "drop" points.
    // If the count is greater than one, the array cannot be obtained by rotating a sorted array.
    // A completely sorted array also has exactly one circular drop (last element > first element).
    // Time Complexity: O(n), Space Complexity: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {

            if(nums[i] > nums[(i + 1) % n]) {//this u can also get from the notes they have provided
                cnt++;
            }
        }

        return cnt <= 1;
    }
};

int main() {

    Solution s;

    vector<int> nums = {3, 4, 5, 1, 2};

    if(s.check(nums))
        cout << "True";
    else
        cout << "False";

    return 0;
}