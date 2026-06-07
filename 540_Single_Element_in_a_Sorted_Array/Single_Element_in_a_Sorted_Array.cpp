#include<bits/stdc++.h>
using namespace std;

    // In a sorted array, elements appear in pairs except one unique element.
    // Before the unique element, pairs start at even indices; after it, pairs start at odd indices.
    // Binary Search uses the parity of mid and its neighboring pair to decide which half to discard.
    // Boundary cases (first or last element being unique) are handled separately.
    // Time Complexity: O(log n), Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();
        
        //checking a few cases explicitly to avoid boundary error
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int start = 1, end = n - 2;
        int ans = -1;

    
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int checker = mid % 2;//for parity checking

            if(nums[mid] != nums[mid+1] &&nums[mid] != nums[mid-1]) {//if the ele is the single ele
                ans = nums[mid];
                break;
            }
            else if(nums[mid] == nums[mid+1] && checker == 1) {//in left
                end = mid - 1;
            }
            else if(nums[mid] == nums[mid+1] && checker == 0) {//in right
                start = mid + 2;
            }
            else if(nums[mid] == nums[mid-1] && checker == 0) {//in left
                end = mid - 2;
            }

            else {//nums[mid] == nums[mid-1] && checker == 1
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single Element = "
         << s.singleNonDuplicate(nums);

    return 0;
}


/*I used teh condtions explicitly so in a few areas there was a boundary error...... so i wrote a few test cases whihc could resolve my problem....
otherwise u have another method for it too where u don't have to write the test cases explicilty and the number of codes will also reduce a lot.... it just turns every (mid) value to even...*/