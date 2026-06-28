#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Use two stacks: one for the current level and one for the next level.
2. Traverse one level completely before moving to the next.
3. If traversing Left-to-Right, push left child first then right child.
4. If traversing Right-to-Left, push right child first then left child.
5. Swapping the stacks after every level automatically produces the zigzag order.
*/

// Definition for a binary tree node.
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root==nullptr)
            return ans;

            //stack needs to be used because two stacks will help in zig zag traversing
        stack<TreeNode*> current;
        stack<TreeNode*> next;

        bool ltr=true;// left to right

        current.push(root);

        while(!current.empty()){

            vector<int> vec; //to have a new vector in each level

            while(!current.empty()){ // for traversing every nodes in that level

                TreeNode* temp=current.top(); // same logic as bfs
                current.pop();
                vec.push_back(temp->val);

                if(ltr){ //left to right (left first right after)
                    if(temp->left)
                        next.push(temp->left);

                    if(temp->right)
                        next.push(temp->right);
                }
                else{ //right to left (right first left after)
                    if(temp->right)
                        next.push(temp->right);

                    if(temp->left)
                        next.push(temp->left);
                }
            }

            // outside of the inner while loop  (After one level)
            ans.push_back(vec);
            ltr=!ltr;// changed from right to left
            swap(current,next);
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";

    for(auto level : ans){
        for(int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}



/*Initially, i wasn't able to think of using two stacks. and the second issue i faced was using two while loops for keeping a track on the level.*/