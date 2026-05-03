#include <bits/stdc++.h>
using namespace std;

/*
Problem: Spiral Matrix
Given an m x n matrix, return elements in spiral order.
Approach: Recursively traverse one boundary at a time and shrink the matrix.
Base Case: Stop when starting indices cross ending indices.
Time Complexity: O(m * n)
Space Complexity: O(1) (excluding output + recursion stack)
*/

class Solution {
public:
    void spiral(vector<vector<int>>& matrix,
                int sr, int er, int sc, int ec,
                vector<int>& ans) {

        // Base case where starting point becomes greater than the ending point
        if(sr > er || sc > ec) return;

        // Top row (left → right)
        for(int j = sc; j <= ec; j++){
            ans.push_back(matrix[sr][j]);
        }

        // Right column (top → bottom)
        for(int i = sr + 1; i <= er; i++){
            ans.push_back(matrix[i][ec]);
        }

        // Bottom row (right → left)
        if(sr < er){
            for(int j = ec - 1; j >= sc; j--){
                ans.push_back(matrix[er][j]);
            }
        }

        // Left column (bottom → top)
        if(sc < ec){
            for(int i = er - 1; i > sr; i--){
                ans.push_back(matrix[i][sc]);
            }
        }

        // Recursive call for inner submatrix
        spiral(matrix, sr + 1, er - 1, sc + 1, ec - 1, ans);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        spiral(matrix, 0, row - 1, 0, col - 1, ans);

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);

    for(int x : result){
        cout << x << " ";
    }

    return 0;
}



/*I used recursion for the traversal and the challenge i faced was aligning the indexes of the column and rows and to also mind it doesn't consider duplicacy. That took a bit of time and focus............


another easy method would be without recursion

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    vector<int> ans;

    while(top <= bottom && left <= right) { //the condition becomes a kinda base case as we used in recursion

        for(int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;

        for(int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        if(top <= bottom){
            for(int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}

*/