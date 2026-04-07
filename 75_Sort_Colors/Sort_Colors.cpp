#include <bits/stdc++.h>
using namespace std;

/*
Sorts array of 0s, 1s, and 2s.
Uses three pointers: low, mid, high to partition elements.
Places 0s at beginning, 1s in middle, 2s at end in one pass.
Time Complexity: O(n), Space Complexity: O(1)
*/

//also famous as Dutch National Flag algorithm.

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    /*The checking will be based on (mid) and(high) not (low) and (high) this time. and remember we r just adjusting the position of 1s and automatically 0s in the front and 2s at the back will be settled.that's why we use (mid)*/

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortColors(nums);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}


/*Challenge i faced was initially i started solving it using merge sort but the time complexity + the space complexity was exceeding too much, and it is but obvious any one will go with any sorting technique, so there u have to find a pattern that unlike other sorting questions the array contains only three variable so in this case we can just check those three seperately using if else.  and if there are even more colors then we can just use COUNTING SORT.*/