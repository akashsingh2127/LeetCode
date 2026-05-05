#include <bits/stdc++.h>
using namespace std;




// This code generates Pascal’s Triangle using the nCr (combination) formula.
// Each element at position (i, j) is computed as C(i-1, j).
// The nCr function efficiently computes combinations using multiplicative formula to avoid factorials.
// Time Complexity: O(n^2), since we compute n(n+1)/2 elements.
// Space Complexity: O(n^2) for storing the triangle.

class Solution {
public:
    int ncr(int n, int r){
        if(r > n) return 0;
        if(r > n - r){r = n - r;} // C(n, r) == C(n, n-r)

        long long num = 1, den = 1;

        int k = 1;
        while(k <= r){
            num *= (n - k + 1);
            den *= k;
            k++;
        }

        return num / den;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;

        int i = 1;
        while(i <= numRows){
            vector<int> row; //to push rows seperately for each row in the triangle

            for(int j = 0; j < i; j++){
                row.push_back(ncr(i - 1, j));
            }
            vec.push_back(row);//row is pushed in vec
            i++;
        }

        return vec;
    }
};

int main() {
    Solution obj;
    int numRows = 5;

    vector<vector<int>> result = obj.generate(numRows);

    for(auto &row : result){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


