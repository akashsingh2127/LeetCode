#include <bits/stdc++.h>
using namespace std;


/*
This algorithm finds the next lexicographically greater permutation of the array.
It identifies a pivot, swaps with the next greater element, and reverses the suffix.
Time Complexity: O(n) Space Complexity: O(1) 
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag = 0;
        int index = -1;
        int size = nums.size() - 1;

        for(int i = size; i >= 1; i--){
            if(nums[i] > nums[i - 1]){/*if a greater element is identified immediately that will become a break point and that value will be swapped with the just next greater element after that breakpoint index*/
                index = i - 1;
                flag = 1;
                break;
            }
        }

        if(flag == 0){//if the array is in descending sorted then reverse it so that it could be ascending again
            reverse(nums.begin(), nums.end());
        } else {
            for(int j = size; j > index; j--){
                if(nums[j] > nums[index]){
                    swap(nums[j], nums[index]);// swapping done
                    reverse(nums.begin() + index + 1, nums.end());/*after the breakpoint index and swapped elements the array needs to be sorted*/
                    break;
                }
            }
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    obj.nextPermutation(nums);

    cout << "Next Permutation: ";
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}



/*
The challenge which i faced was i could only think of swapping the two values and instead of sorting the rest array after the breakpoint i was actually swapping it.. because the example i took was fitting with my concept then after the test cases failed checking with a better example i changed it to sorting*/