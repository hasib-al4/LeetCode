/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;

        long long ans = 0;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            long long min = q.front().second;
            long long first, last;
            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = cur_id;
                if (i == size - 1)
                    last = cur_id;
                if (node->left != NULL)
                    q.push({node->left, 2 * cur_id + 1});
                if (node->right != NULL)
                    q.push({node->right, 2 * cur_id + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};