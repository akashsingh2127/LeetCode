#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
Uses a hash set to detect sequence starts efficiently.
Expands only from elements that have no predecessor.
Time Complexity: O(n) – each element processed once.
Space Complexity: O(n) – extra space for set.
*/
    int longestConsecutiveSet(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxx = 0;

        for(int i : s){
            if(s.find(i - 1) == s.end()){/*no need to check for every element only to check with the smallest element of the sequence*/
                int cur = i;
                int count = 1;
                while(s.find(cur + 1) != s.end()){
                    count++;
                    cur++;
                }

                maxx = max(maxx, count);
            }
        }
        return maxx;
    }


    /*
Sorts the array and counts consecutive elements linearly.
Duplicates are skipped to avoid breaking sequences.
Time Complexity: O(n log n) – due to sorting.
Space Complexity: O(1) – no extra space (ignoring sort).
*/

    int longestConsecutiveSorted(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());//for small no. of elements it could be better performing but tc O(n logn)
    int maxx = 1;
    int count = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i - 1]){
            continue;
        }
        else if(nums[i] == nums[i - 1] + 1){
            count++;
        }
        else{
            count = 1;
        }
        maxx = max(maxx, count);
    }
    return maxx;
}


};

int main() {
    Solution obj;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Length: "
         << obj.longestConsecutiveSet(nums) << endl;

    return 0;
}


/*Although the hash-set approach is O(n) theoretically, in practice sorting O(n logn) can be faster due to better cache locality and lower constant factors. However, asymptotically the hash-set approach is optimal*/