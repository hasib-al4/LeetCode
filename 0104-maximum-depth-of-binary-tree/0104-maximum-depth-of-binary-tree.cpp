/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int depth = 0;
        if (root == NULL ) return depth;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
             depth =  it.second;
            if(node -> left != NULL) q.push({node -> left, depth + 1});
            if(node -> right != NULL) q.push({node -> right, depth + 1});
        }
        return depth;
    }
};