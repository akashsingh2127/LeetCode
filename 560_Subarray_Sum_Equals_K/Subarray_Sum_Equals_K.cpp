#include <bits/stdc++.h>
using namespace std;

/*
Count the number of subarrays with sum = k.
Use prefix sum and hashmap to store frequency of sums.
If (current_sum - k) exists, it means a valid subarray is found.
Time Complexity: O(n), Space Complexity: O(n)
*/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int sum = 0;
    int count = 0;

    mp[0] = 1; // handles subarrays starting from index 0

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if(mp.find(sum - k) != mp.end()) {
            count += mp[sum - k];
        }

        mp[sum]++;
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = subarraySum(nums, k);

    cout << ans;

    return 0;
}