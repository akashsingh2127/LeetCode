#include <bits/stdc++.h>
using namespace std;

/*
Performs inorder traversal (Left → Root → Right) of a binary tree.
Uses recursion to visit nodes in correct order.
Stores result in a vector and returns it.
Time Complexity: O(n), Space Complexity: O(n)
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

void inorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;//base case (helps in backtracking)

    inorder(root->left, ans);//traversal in leftmost node
    ans.push_back(root->val);//pushing the values in the answer during the backtracking
    inorder(root->right, ans);//traversal in the right most node
}

vector<int> inorderTraversal(TreeNode* root) {/*we also need an answer array so we will create a seperate function for traversal*/
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = inorderTraversal(root);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}