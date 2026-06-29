#include<bits/stdc++.h>
using namespace std;

    // Binary Search is used to locate the minimum element in a rotated sorted array.
    // If nums[mid] > nums[end], the minimum lies in the right half.
    // Otherwise, the minimum lies in the left half including mid.
    // The search space is reduced until start and end converge to the minimum element.
    // Time Complexity: O(log n), Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while(start < end) {//make sure it shouldn't be (start<=end)

            int mid = start + (end - start) / 2;

            if(nums[end] < nums[mid]) { //for the cases:-4567123
                start = mid + 1;
            }
            else {//for the cases:-6712345
                end = mid;
            }
        }
        return nums[start];//for the normal case:-1234567
        //changing the start and end in the while loop will lead us to the sorted array where first val will be min
    }
};


/*       OR        
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        while(start < end){

    int mid = start + (end - start)/2;

    if(nums[start] <= nums[mid] &&
       nums[mid] <= nums[end]){
        return nums[start];
    }

    else if(nums[start] <= nums[mid] &&
            nums[mid] > nums[end]){
        start = mid + 1;
    }

    else{
        end = mid;
    }
}
        }           
};

*/

int main() {

    Solution s;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << "Minimum Element = "
         << s.findMin(nums);

    return 0;
}


/* Initially i was wiriting unnecessary conditions in the if and elseif and which was like (nums[start] > nums[mid] && nums[mid] > nums[end]) but only cond i needed was (nums[mid]>nums[end])... 
Secondly, make sure unlike the other roatetd sorted array problems don't do (start<=end) in the while loop this will lead to wrong answer e.g. [3,1,2].....
Thirdly, we r dealing with the third condition outside the while loop but i was trying to cover it inside the loop itself whihc led to some Return error...*/