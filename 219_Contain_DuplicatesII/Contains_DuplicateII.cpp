#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach:
1. Use an unordered_map where the key is the element and the value is a pair(index, count).
2. For every element, check if it has appeared before in the map.
3. If yes, compare the current index with its last stored index.
4. If the difference is less than or equal to k, a nearby duplicate exists.
5. Otherwise, update the latest index and increment its occurrence count.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, pair<int,int>> m;

        for(int i = 0; i < nums.size(); i++) {

            if(m.find(nums[i]) != m.end()) {

                if(i - m[nums[i]].first <= k) {
                    return true;
                }
            }

            m[nums[i]].first = i;   // Update latest index
            m[nums[i]].second++;    // Increment count
        }

        return false;
    }
};

/*           OR (BETTER VERSION)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++){

            if(m.find(nums[i])!=m.end()){

                if(i - m[nums[i]] <= k)
                    return true;
            }

            m[nums[i]] = i;
        }

        return false;
    }
};
*/





int main() {

    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    Solution obj;

    if(obj.containsNearbyDuplicate(nums, k))
        cout << "True";
    else
        cout << "False";

    return 0;
}