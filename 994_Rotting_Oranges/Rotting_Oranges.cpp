#include <bits/stdc++.h>
using namespace std;

/*
1. We use Multi-Source BFS because multiple rotten oranges spread simultaneously.
2. All initially rotten oranges are inserted into the queue at the beginning.
3. Each BFS level represents one unit of time (one minute).
4. We process only the oranges present in the queue at the current level.
5. For every rotten orange, we check its four adjacent cells.
6. If an adjacent cell contains a fresh orange, we make it rotten immediately.
7. The newly rotten orange is then added to the queue for the next level.
8. We increment the minute after processing a complete BFS level.
9. After BFS, if any fresh orange remains, it is unreachable, so we return -1.
10. Otherwise, we return the total number of minutes required.

time complexity:O(n*m)   and space complexity:O(n*m)

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> sys;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    sys.push({i, j});
                }
            }
        }

        vector<int> row = {0, 0, -1, 1};
        vector<int> col = {1, -1, 0, 0};

        int min = 0;
        while(!sys.empty()) {

            int siz = sys.size();

            for(int i = 0; i < siz; i++) {

                int temp_r = sys.front().first;
                int temp_c = sys.front().second;
                sys.pop();

                for(int k = 0; k < 4; k++) {

                    int nr = temp_r + row[k];  // good practice to make a new var with shorter name
                    int nc = temp_c + col[k];

                    //this is the case we need to check before, to avoid index out of bounds error and also check if the adjacent cell has a fresh orange
                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < m &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        sys.push({nr, nc});
                    }
                }
            }

            if(!sys.empty()) {
                min++;
            }
        }

        // If any fresh orange remains, it cannot be rotten
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return min;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << obj.orangesRotting(grid) << endl;

    return 0;
}


/*
it's more likely finding the level but more number of nodes at a same time that's why two loops and that's why the minutes is calculated ainside the while() after the inner for loop ends.


the challenge i faced was i was unnecessarily making visited vector which was a kind of unnecessary overhead..
and also no need to calculate the minutes in the queue itself.*/