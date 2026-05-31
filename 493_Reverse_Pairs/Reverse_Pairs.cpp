#include<bits/stdc++.h>
using namespace std;




    // Merge Sort is used to divide the array into sorted halves recursively.
    // Before merging, valid reverse pairs are counted using two pointers on the sorted halves.
    // For each element in the left half, count elements in the right half satisfying nums[i] > 2*nums[j].
    // After counting, the halves are merged to maintain sorted order for higher recursive levels.
    // Time Complexity: O(n log n), Space Complexity: O(n)
class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low, right = mid + 1;
        vector<int> ans;
        while(left <= mid && right <= high) {
            if(nums[left] > nums[right]) {
                ans.push_back(nums[right]);
                right++;
            }
            else {
                ans.push_back(nums[left]);
                left++;
            }
        }
        while(left <= mid) {
            ans.push_back(nums[left]);
            left++;
        }
        while(right <= high) {
            ans.push_back(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++) {
            nums[i] = ans[i - low];
        }
    }


    /*In the mergesort fn the order should be 
            mergesort(nums,low,mid);
            mergesort(nums,mid+1,high);

            count reverse pairs logic

            merge(nums,low,mid,high);*/

    int mergesort(vector<int>& nums, int low, int high) {
        if(low >= high) return 0;
        int mid = (low + high) / 2;
        /*no need to define it reversepair fn and pass it in the mergesort fn everythime ... it sometimes causes confusion to the recursion*/
        int cnt = 0;
        cnt += mergesort(nums, low, mid);
        cnt += mergesort(nums, mid + 1, high);
        int j = mid + 1;
        /*Now this for and while loops are there to check for the element in the left array with the right array which satisfies the condition......  and also to check till when does it satisfy because suppose in arrays [11,15,19]                [1,2,6,7,10]      if (11)  satisfies for {1,2}  and {1,2} will also be there for (15) and (19)   and similarly we can continue checking from {6} on wards for nxt ele (15).......  so this is why we r using while loop inside the for loop to check for all the elements everytime once it is sorted in every recursion*/
        for(int i = low; i <= mid; i++) {
            while(j <= high &&
                  nums[i] > 2LL * nums[j]) {//(LL) means long long and this resolves integer overflow error
                j++;
            }
            cnt += j - (mid + 1);//it's (j-mid-1) not (j-mid+1)
        }
        merge(nums, low, mid, high);//merging back in sorted order
        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        return mergesort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 3, 2, 3, 1};

    cout << "Reverse Pairs = "
         << s.reversePairs(nums);

    return 0;
}


/* The challenge i faced was i was doing (cnt+=j-mid+1)  instead of (cnt+=j-mid-1)    and secondly i was struggling with logic how to compute cnt for every sorted subarray*/