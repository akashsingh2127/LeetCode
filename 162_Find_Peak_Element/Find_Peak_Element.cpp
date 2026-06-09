#include<bits/stdc++.h>
using namespace std;



    // A peak element is greater than its adjacent elements.
    // First, boundary cases are checked since the first or last element can also be a peak.
    // Binary Search is used to locate a peak by observing the increasing/decreasing slope around mid.
    // If the slope is increasing, search moves right; otherwise it moves left.
    // This reduces the search space by half in every iteration.

    // Time Complexity: O(log n)
    // Space Complexity: O(1)
class Solution {
public:

    int findPeakElement(vector<int>& nums) {

        int start = 1;
        int end = nums.size() - 2;

        if(nums.size() == 1)
            return 0;

        if(nums[0] > nums[start])
            return 0;

        if(nums[end + 1] > nums[end])
            return end + 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid + 1] < nums[mid] &&nums[mid - 1] < nums[mid]) {
                return mid;
            }
            else if(nums[mid - 1] < nums[mid]) {//if the mid is on the increasing slope
                start = mid + 1;
            }
            else if(nums[mid] > nums[mid + 1]) {// if the element is on the decresing slope
                end = mid - 1;
            }
            // this is the additional line which diffrentiate the single peak v/s multiple peak
            else {//(nums[mid+1]>nums[mid]&&nums[mid]<nums[mid-1])  OR the on of the least values
                end = mid - 1;
            }
        }

        return -1;
    }
};

int main() {



    Solution s;

    vector<int> nums = {1, 2, 3, 1};

    cout << "Peak Element Index = "
         << s.findPeakElement(nums) << endl;

    return 0;
}