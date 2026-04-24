#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx = 0;
        int start = prices[0];
        int diff = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] <= start){//if current price is less than the selling price then it will give max profit so we change the selling price with current price
                start = prices[i];
            }
            diff = prices[i] - start;// profit
            maxx = max(maxx, diff);
        }
        return maxx;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = obj.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}

/*
This approach tracks the minimum buying price and computes profit for each day.
It updates the maximum profit whenever a better selling price is found.
Time Complexity: O(n) – single pass through the array.
Space Complexity: O(1) – constant extra space is used.
*/