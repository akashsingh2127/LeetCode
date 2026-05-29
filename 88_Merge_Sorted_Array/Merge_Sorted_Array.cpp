#include<bits/stdc++.h>
using namespace std;


    // Two sorted arrays are merged in-place without using extra space.
    // Comparison starts from the back because nums1 has empty spaces at the end.
    // Larger element is placed at the current last index and pointers move backwards.
    // Remaining elements of nums2 are copied if nums1 elements finish first.
    // Time Complexity: O(m+n), Space Complexity: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m,vector<int>& nums2, int n) {
    //we will be choosing comparinig element from the last unlike the ususal method where we used an extra array
        int f = m - 1;
        int s = n - 1;
        int index = m + n - 1;//don't do m+n-2 it will just miss the last element

        while(f >= 0 && s >= 0) {

            if(nums1[f] > nums2[s]) {
                nums1[index] = nums1[f];
                index--;
                f--;
            }
            else {
                nums1[index] = nums2[s];
                index--;
                s--;
            }
        }

        /*if any ele is left in the nums2 then put it in the nums1 otherwise nums1 ele r already in their correct position*/
        while(s >= 0) {
            nums1[index] = nums2[s];
            index--;
            s--;
        }
    }
};

int main() {

    Solution s;

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3;
    int n = 3;

    s.merge(nums1, m, nums2, n);

    for(int x : nums1) {
        cout << x << " ";
    }
    return 0;
}

/*The challenge in it was i was doing (index=m+n-2) which was always excluding the last 0 in the nums1*/