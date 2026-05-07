#include<bits/stdc++.h>
using namespace std;


    // Boyer-Moore Voting Algorithm is used to find elements occurring more than n/3 times.
    // At most 2 such elements can exist, so we maintain 2 candidates and their counts.
    // Matching elements increase count, different elements cancel both counts.
    // Final verification pass checks whether the candidates actually appear more than n/3 times.
    // Time Complexity: O(n), Space Complexity: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1;
        int count1 = 0, count2 = 0;

        //this loop is just to check which elements r occuring the most
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == num1) {//if number matches num1 increment count1
                count1++;
            }
            else if(nums[i] == num2) {//if number matches num2 increment count2
                count2++;
            }
            else if(count1 == 0) { //if there is no element in (num1) then allot it the number
                num1 = nums[i];
                count1++;
            }
            else if(count2 == 0) {// if there is no element in (num2) then allot it the number
                num2 = nums[i];
                count2++;
            }
            else {    //if number doesn't match neither num1 or num2 decrement from both
                count1--;
                count2--;
            }
        }

        //now u got which numbers r occuring most number of times 
        int cnt1 = 0, cnt2 = 0;
        for(int x : nums) {
            if(x == num1) cnt1++;
            else if(x == num2) cnt2++;
        }

        vector<int> ans;
        int n = nums.size() / 3;
        // now u need to manually check whether the occurence is more than n/3 or not
        if(cnt1 > n) ans.push_back(num1);
        if(cnt2 > n) ans.push_back(num2);

        return ans;
    }
};

int main() {

    Solution s;
    vector<int> nums = {3,2,3};
    vector<int> ans = s.majorityElement(nums);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}





/*
The challenge i faced was that i knew when num1 or num2 will become a suitable candidate but how to allot them the respective numbers was a trouble for me... because my intial code had 
if(count1==0){ num1=nums[i]; count1++; }
else if(count2==0){ num2=nums[i]; count2++; }
else if(nums[i]==num1){ count1++; }
else if(nums[i]==num2){ count2++; }
else{ count1--; count2--; }

now here the problem was even with num2 has a number and if incase count1 becomes 0 then even the number same as num2 will get stored in num1 which will cretae issues.......
check it for this example nums = [1,2,2,3,2]..........

and shifting this two conditions above helped me resolve the problem of suitable candidate 
if(nums[i] == num1) {count1++;}
else if(nums[i] == num2) {count2++;}
*/