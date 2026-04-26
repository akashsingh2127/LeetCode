#include <bits/stdc++.h>
using namespace std;



/*
This approach places positive elements at even indices and negative at odd indices.
It uses two pointers to maintain correct alternating positions in a new array.
Time Complexity: O(n) Space Complexity: O(n) 
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> vec(nums.size(), 0);
        int pos = 0, neg = 1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                vec[pos] = nums[i];
                pos += 2;//even indexes positive
            } else {
                vec[neg] = nums[i];
                neg += 2;//odd indexes negative
            }        
        }
        return vec;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> result = obj.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

