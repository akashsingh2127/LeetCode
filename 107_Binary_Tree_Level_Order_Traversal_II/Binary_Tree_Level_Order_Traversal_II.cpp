#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Perform a level-order traversal (BFS) using a queue.
2. Process one level at a time by storing the current queue size.
3. Store all nodes of the current level in a temporary vector.
4. Push each level into a stack to reverse the order of levels.
5. Pop all levels from the stack into the answer vector and return it.
Time Complexity: O(N), where N is the number of nodes.
Space Complexity: O(N), for the queue, stack, and answer vector.
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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if(root == nullptr)
            return {};

        vector<vector<int>> ans;
        stack<vector<int>> st;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            st.push(level);
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
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

    vector<vector<int>> ans = obj.levelOrderBottom(root);

    cout << "Bottom-Up Level Order Traversal:\n";

    for(auto level : ans) {

        for(int value : level)
            cout << value << " ";

        cout << endl;
    }

    return 0;
}