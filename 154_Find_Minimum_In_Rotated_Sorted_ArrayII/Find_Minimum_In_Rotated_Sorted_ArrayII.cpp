#include<bits/stdc++.h>
using namespace std;

    // Binary Search is used to locate the minimum element in a rotated sorted array.
    // If nums[mid] > nums[end], the minimum lies in the right half.
    //If numss[mid]<nums[end], the minimum lies in the left half.
    // Otherwise, shift the end left side by one because we need to deal with the duplicate too.
    // The search space is reduced until start and end converge to the minimum element.
    // Time Complexity: O(log n), Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while(start < end) {//make sure it shouldn't be (start<=end)

            int mid = start + (end - start) / 2;

            if(nums[end] < nums[mid]) {
                start = mid + 1;
            }else if(nums[mid]<nums[end]){//seperated condition
                end=mid;
            }
            else {//nums[mid]=nums[end]   to deal with the duplicate
                end--;
            }
        }
        return nums[start];//for the normal case:-1234567
        //changing the start and end in the while loop will lead us to the sorted array where first val will be min
    }
};


int main() {

    Solution s;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 4};

    cout << "Minimum Element = "
         << s.findMin(nums);

    return 0;
}


/*In part 1 u keep nums[mid]<=nums[end] condition together but as we r dealing with the duplictes here so we need to seperate these two contions*/