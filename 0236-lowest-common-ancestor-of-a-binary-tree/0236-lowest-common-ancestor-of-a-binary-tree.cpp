/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* a, vector<TreeNode*> &arr) {
        if(root == NULL) return false;
        arr.push_back(root);
        if(root == a) return true;
        if(path(root -> left, a, arr) || path(root -> right, a, arr)) return true;
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1, arr2;
        path(root, p, arr1);
        path(root,q, arr2);
        int i = 0, j = 0;
        int n = arr1.size(), m = arr2.size();
        while (i < n && j < m) {
            if(arr1[i] == arr2[j]) {
                i++;
                j++;
            }
            else return arr1[i - 1];
        }
        if(i == n) return arr1[i - 1];
        else return arr2[j - 1];
    }
};