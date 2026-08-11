#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 1. An O connected to the boundary can never be surrounded.
    // 2. Find all O's present on the four boundaries of the board.
    // 3. Start DFS from every boundary O.
    // 4. DFS visits all O's connected to that boundary O.
    // 5. Mark all such safe O's as visited.
    // 6. Any O that is not visited cannot reach the boundary.
    // 7. Therefore, every unvisited O is completely surrounded by X's.
    // 8. Convert every unvisited O into X.
    // 9. Keep every visited O unchanged because it is not surrounded.
    // 10. DFS explores each cell at most once, giving O(m*n) time and space.

    void dfs(vector<vector<char>>& graph,
             vector<vector<bool>>& visited,
             int r, int c,
             vector<int>& row,
             vector<int>& col) {

                //almost used in every such approach. remember the base case
        if (r < 0 || r >= graph.size() ||
            c < 0 || c >= graph[0].size() ||
            visited[r][c] ||
            graph[r][c] == 'X') {
            return;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + row[i];
            int nc = c + col[i];

            dfs(graph, visited, nr, nc, row, col);
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        vector<pair<int, int>> vec; // firstly i will store all the O's position in the vector and traverse on each O one by one with the condition of Visited[row][col]==false

        // Store O's on left and right boundaries
        for (int i = 0; i < m; i++) {

            if (board[i][0] == 'O')
                vec.push_back({i, 0});

            if (board[i][n - 1] == 'O')
                vec.push_back({i, n - 1});
        }

        // Store O's on top and bottom boundaries
        for (int i = 0; i < n; i++) {

            if (board[0][i] == 'O')
                vec.push_back({0, i});

            if (board[m - 1][i] == 'O')
                vec.push_back({m - 1, i});
        }

        vector<int> row = {-1, 1, 0, 0};
        vector<int> col = {0, 0, -1, 1};
        for (auto x : vec) {

            int r = x.first;
            int c = x.second;

            if (!visited[r][c])
                dfs(board, visited, r, c, row, col);
        }
        // Now, all O's that are connected to the boundary have been marked as visited. becuase the unconnected O' will never be visited hence they will never be marked as visisted.
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};


int main() {

    Solution obj;

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    obj.solve(board);

    for (auto &row : board) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}