#include <bits/stdc++.h>
using namespace std;

/*
Problem: Set Matrix Zeroes
Given a matrix, if any cell is 0, set its entire row and column to 0 (in-place).
Approach: Use first row and column as markers to store which rows/columns to zero.
Edge Handling: Use two flags to track if first row/column originally had a zero.
Time Complexity: O(m * n)
Space Complexity: O(1) (no extra space used)
*/




/*In this approach we have used first row and column for tracking the zeroes which was done by additional arrays, and at the end we will we will chnage every other elements which needs to be zero except first row and first column..... and if there appears any zero in 1st row or column we can keep track of it using firstrow and firstcol boolean..... and we can change it at last after changin inner elements*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        bool firstRow = false, firstCol = false;


        // Check firstrow
        for(int j = 0; j < col; j++){
            if(matrix[0][j] == 0){
                firstRow = true;
            }
        }

        // Check firstcolumn
        for(int i = 0; i < row; i++){
            if(matrix[i][0] == 0){
                firstCol = true;
            }
        }

        // Mark first rows and first columns as 0 if there appears any zero in respective row or column
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set respective rows to zero using the marking we did
        for(int i = 1; i < row; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < col; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        // Set respective columns to zero using the marking we did
        for(int j = 1; j < col; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < row; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        // Now if there is any 0 in first row change all the elements as 0
        if(firstRow){
            for(int j = 0; j < col; j++){
                matrix[0][j] = 0;
            }
        }

        // Now if there is any 0 in first column change all the elements as 0
        if(firstCol){
            for(int i = 0; i < row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution obj;
    obj.setZeroes(matrix);

    // Print result
    for(auto &row : matrix){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}










/*The challenge i faced was that i was trying to change every element starting from first row and first column as 0 from the beginning but mistakenly i was changing the row also as 0 and while changing the inner elements we mistakenly changed the entire array as 0 if there existed any 0 in the first column...... then i used firstrow and firstcolumn boolean approach..... */