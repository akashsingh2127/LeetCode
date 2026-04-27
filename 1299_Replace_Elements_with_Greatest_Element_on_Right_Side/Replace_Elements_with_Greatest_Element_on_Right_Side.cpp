#include <bits/stdc++.h>
using namespace std;


/*
This approach replaces each element with the maximum element to its right.
It traverses from right to left while maintaining the current maximum.
Time Complexity: O(n) Space Complexity: O(1) 
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n = nums.size();
        int maxx = nums[n - 1], max2 = nums[n - 1];  /*store the last element in two different var because it will prevent from maximum declaration confusion.*/

        nums[n - 1] = -1; //as per rule last value as -1 and we alreadystored the last value in variables

        for(int i = n - 2; i >= 0; i--){
            max2 = nums[i];//current val in max2
            nums[i] = maxx;//second last value changes to nums[n] first then the same will go on in the loop
            maxx = max(max2, maxx);//then the new maximum will be generated
        }

        return nums;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {17, 18, 5, 4, 6, 1};

    vector<int> result = obj.replaceElements(nums);

    cout << "Modified Array: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}




/* The challenge i faced was not a big issue just i had a little bit confusion in how to keep track of the maximum because i was changing the maximum value all the time..........*/
