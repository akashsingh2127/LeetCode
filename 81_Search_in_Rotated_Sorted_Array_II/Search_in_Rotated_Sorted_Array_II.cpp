#include<bits/stdc++.h>
using namespace std;


    // Binary Search is applied on a rotated sorted array containing duplicates.
    // One half is identified as sorted and checked for the target's possible range.
    // When start, mid, and end are equal, duplicates are removed by shrinking both ends.
    // This resolves ambiguity caused by duplicate values in determining the sorted half.
    // Time Complexity: O(log n) average, O(n) worst case; Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(nums[mid] == target) {
                return true;
            }
            //this is the additional line in Problem No. 33
            if(nums[start] == nums[mid] &&
               nums[mid] == nums[end]) {
                start++;
                end--;
            }

            else if(nums[start] <= nums[mid]) {
                if(target >= nums[start] &&
                   target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                if(target > nums[mid] &&
                   target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    if(s.search(nums, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}