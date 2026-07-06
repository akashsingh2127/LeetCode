#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Perform a level-order traversal (BFS) while assigning every node its vertical (x) and level (y) coordinates.
2. Store nodes in a nested map where x represents the vertical column and y represents the level.
3. Use a multiset to automatically sort nodes having the same (x, y) coordinates.
4. Traverse the nested map from leftmost to rightmost column and collect the node values.
5. Return the resulting vertical order traversal.
Time Complexity: O(N log N), where N is the number of nodes.
Space Complexity: O(N), for the queue and nested map.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root == nullptr)
            return {};

        // we have used multiset to avoid duplicate values and sort in the ascending order for the elements in the same level and vertical 
        map<int, map<int, multiset<int>>> nodes; //{node,{vertical, level}}

        queue<pair<TreeNode*, pair<int,int>>> q; // for bfs traversal

        q.push({root, {0, 0}});

        while(!q.empty()) {

            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;   //vertical index
            int y = p.second.second;  //level indexing

            nodes[x][y].insert(node->val);

            if(node->left) // left will be v_index--
                q.push({node->left, {x - 1, y + 1}});

            if(node->right)// right will be v_index++
                q.push({node->right, {x + 1, y + 1}});
        }
        vector<vector<int>> ans; //to record answer 

        for(auto colMap : nodes) { //in the outer map

            vector<int> col; 

            for(auto levelMap : colMap.second) { //in the inner map

                for(auto value : levelMap.second) // for the multiset
                    col.push_back(value);
            }

            ans.push_back(col);
        }

        return ans;
    }
};

int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.verticalTraversal(root);

    cout << "Vertical Traversal:\n";

    for(auto column : ans) {

        for(int value : column)
            cout << value << " ";

        cout << endl;
    }

    return 0;
}