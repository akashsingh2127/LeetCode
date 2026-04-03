#include <bits/stdc++.h>
using namespace std;

/*
Counts frequency of each element using unordered_map.
Finds the maximum frequency among all elements.
Sums frequencies of elements having this maximum frequency.
Time Complexity: O(n), Space Complexity: O(n)
*/

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int,int> um;

    for(int i = 0; i < nums.size(); i++){
        um[nums[i]]++;
    }

    int maxx = 0;
    for(auto it : um){
        maxx = max(maxx, it.second);
    }

    int ans = 0;
    for(auto it : um){
        if(it.second == maxx){
            ans += it.second;
        }
    }

    return ans;        
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << maxFrequencyElements(nums);

    return 0;
}


/*
The challenge I faced was i was using it.second()  but it should be it.second     because second is not a function.*/