#include<bits/stdc++.h>
using namespace std;


    // Use expected sum and square-sum formulas for numbers from 1 to n².
    // Difference of sums gives (missing - repeated).
    // Difference of square sums gives (missing + repeated).
    // Solve the two equations to find the missing and repeated values.
    // Time Complexity: O(n²), Space Complexity: O(1)

//(x-y=a) and (x^2)-(y^2)=b  therefore it can be written as (x+y)(x-y)=b then we can solve it mathematically...
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();

        long long x = 1LL * n * n;

        long long ss = 0, s = 0;

        long long actual_s =
        (x * (x + 1)) / 2;

        long long actual_ss =
        (x * (2 * x + 1) * (x + 1)) / 6;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                s += (long long)grid[i][j];

                ss += (long long)grid[i][j] *
                      grid[i][j];
            }
        }

        long long s_dif = actual_s - s;

        long long ss_dif =
        (actual_ss - ss) / s_dif;

        long long miss =
        (ss_dif + s_dif) / 2;

        long long repeat =
        miss - s_dif;

        return {(int)repeat, (int)miss};
    }
};

int main() {


    Solution s;

    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 5},
        {7, 8, 9}
    };

    vector<int> ans = s.findMissingAndRepeatedValues(grid);

    cout << "Repeated: " << ans[0] << endl;
    cout << "Missing : " << ans[1] << endl;

    return 0;
}



/*Make sure to change the data type as int while returning, because u did every operation in long long*/