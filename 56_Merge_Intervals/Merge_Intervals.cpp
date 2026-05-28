#include<bits/stdc++.h>
using namespace std;



// Intervals are first sorted according to their starting times.
    // If current interval overlaps with the last merged interval, merge them.
    // Otherwise, push the current interval as a new separate interval.
    // This efficiently combines all overlapping intervals into minimal ranges.
    // Time Complexity: O(n log n), Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());//sorting makes the problem easy

        ans.push_back({intervals[0][0], intervals[0][1]});/*I pushed the first element in the array and for now consider it as the answer*/

        for(int i = 1; i < n; i++) {
            int start = intervals[i][0];//lower class
            int end = intervals[i][1];//upper class

            if(ans.back()[1] >= intervals[i][0]) { /*if previous upper classs is greater than current lower class then just check the max value for the updated upper class and replace it in the answer*/
                ans.back()[1] =max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back({intervals[i][0],intervals[i][1]}); //otherwise just push the respective class 
            }
        }
        return ans;
    }
};

int main() {

    Solution s;

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    vector<vector<int>> ans = s.merge(intervals);
    for(auto v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}

/*The challenge i faced was that i wasn't knowing that we can use (ans.back()[1])  to traverse the latest element in the (ans), instead i was trying to use (ans[i-1][1]) which was woring for the 2nd elment but as we moved to 3rd element it will look for (ans[2][1]) but if it would have overlapped then there would be only one element in (ans) hence (ans[2][1]) trversal would have given undefined error........ therefore u need to use(ans.back()[1])*/