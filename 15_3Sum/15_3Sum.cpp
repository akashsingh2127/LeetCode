#include<bits/stdc++.h>
using namespace std;


    // The array is first sorted to apply the two-pointer technique efficiently.
    // One element is fixed, while two pointers search for the remaining pair.
    // If sum becomes smaller, move start pointer; if larger, move high pointer.
    // Duplicate values are skipped to ensure only unique triplets are stored.
    // Time Complexity: O(n^2), Space Complexity: O(1) excluding output vector.




    /*and listen we have to find (num1+num2+num3=0) so we can say that (nu2+num3=-num1) and we r using the same approach*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());//sorting makes the problem easy

        vector<vector<int>> vec;

        for(int j=0;j<nums.size();j++){
              /*if next element is the same as the first elemnt then no need to check for those ele again*/
            if(j > 0 && nums[j] == nums[j-1]) continue;          

            int start=j+1,high=nums.size()-1;

            while(start<high){

                vector<int> ans;

                /*i have to use nums[start] and nums[high] in future in while loop to pass the same element so i stored it in variables*/
                int s=nums[start],end=nums[high];

                if(nums[start]+nums[high]==-nums[j]){
                    ans.push_back(nums[start]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[high]);
                    vec.push_back(ans);  
                    while(start<high && nums[start]==s){//if same element appears for two pointer then (start) pass
                        start++;
                    }   

                    while(start<high && nums[high]==end){//same as (start)
                        high--;
                    }         
                }

                else if(nums[start]+nums[high] < -nums[j]){//if less increment start
                    while(start<high && nums[start]==s){
                        start++;
                    }
                }

                else{
                    while(start<high && nums[high]==end){//if more decrement high
                        high--;
                    }
                }
            }
        }

        return vec;
    }
};

int main() {
    Solution s;

    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = s.threeSum(nums);

    for(auto v : ans){

        for(int x : v){
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}



/* the challenge i faced was that i wasn't using while loop in the beginning to pass all the duplicate values which was causing duplicacy in answers.*/