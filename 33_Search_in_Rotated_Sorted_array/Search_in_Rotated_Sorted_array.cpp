#include <bits/stdc++.h>
using namespace std;

/*
Search an element in a rotated sorted array using modified binary search.
At every step, one half is always sorted, so we check if target lies in that half.
Based on that, we eliminate half of the array.
Time Complexity: O(log n), Space Complexity: O(1)
*/

int searchElement(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        
        if (nums[start] <= nums[mid]) {// shows left half is sorted and we will be checking in the left half
            if (target >= nums[start] && target < nums[mid]) {//if probable found in left half
                end = mid - 1;
            } else {//start while loop for the right half
                start = mid + 1;
            }
        }
        
        else {// shows right half is sorted and we will be checking in the right half
            if (target > nums[mid] && target <= nums[end]) {//if probable found in right half
                start = mid + 1;
            } else {//start while loop for the left half
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int index = searchElement(nums, target);

    cout << index;

    return 0;
}



/* The challenge i faced was that i wasn't able to combine the logic for rotated and not rotated array in a single loop.  but we need to understand the logic is exact same as the binary search.
*/