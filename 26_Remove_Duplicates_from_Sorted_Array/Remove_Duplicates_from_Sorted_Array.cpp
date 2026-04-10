#include <bits/stdc++.h>
using namespace std;

/*
Removes duplicates from sorted array using two pointers.
i tracks position of unique elements, j scans the array.
Overwrites duplicates in-place to keep only unique values.
Time Complexity: O(n), Space Complexity: O(1)
*/



//we r using two pointers approach
int removeDuplicates(vector<int>& nums) {

    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];  // first value will be at the first positiona and this line will update the next element as the new unique element.
        }
    }
    return i + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    
    for (int i = 0; i < k; i++) {// print unique elements
        cout << nums[i] << " ";
    }

    return 0;
}