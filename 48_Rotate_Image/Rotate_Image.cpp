#include <bits/stdc++.h>
using namespace std;

/*
Problem: Rotate Image (90° clockwise)
Given an n x n matrix, rotate it by 90 degrees in-place.
Approach: First transpose the matrix, then reverse each row.
Transpose swaps matrix[i][j] with matrix[j][i].
Time Complexity: O(n^2)
Space Complexity: O(1) (in-place rotation)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose each row
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){/*remember j = i ....... not j=0 beacuse it will re-transpose the transposed matrix*/
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row one by one
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    obj.rotate(matrix);
    for(auto &row : matrix){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}



/*The challenge i faced was i was doing j=0 and it was re-transposing the transposed matrix because we in case of j=0 it would swap every element once and [ swap(swap)=original ] and remember j = i ....... not j=0 beacuse it will re-transpose the transposed matrix*/