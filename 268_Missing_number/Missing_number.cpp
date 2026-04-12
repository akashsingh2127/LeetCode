#include <bits/stdc++.h>
using namespace std;

/*
Find the missing number in an array containing n distinct numbers from 0 to n.
We use the sum formula: total = n*(n+1)/2 and subtract the array sum.
The difference gives the missing number.
Time Complexity: O(n), Space Complexity: O(1)
*/


/*This problem is simple because the numbers are in order, and only one number is missing.*/
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = nums[0];
    for (int i = 1; i < n; i++) {
        sum += nums[i];
    }
    int total = n * (n + 1) / 2;
    return total - sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = missingNumber(nums);
    cout << ans;

    return 0;
}