#include <bits/stdc++.h>
using namespace std;


/*
Boyer-Moore Voting Algorithm finds the majority element by canceling out different elements.
It maintains a candidate and a counter to track dominance in a single pass.
Time Complexity: O(n) – we traverse the array once.
Space Complexity: O(1) – no extra space is used.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0){   /*this is to select the majority element which we will be resetting everytime when the unmatched element total will reset matched element total to 0 */
                ans = nums[i]; 
                count = 1;
            }
            else if(nums[i] == ans){// if same +1
                count++;
            }
            else{ //if not same -1
                count--;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {6, 5, 5};

    int result = obj.majorityElement(nums);
    cout << "Majority Element: " << result << endl;

    return 0;
}

