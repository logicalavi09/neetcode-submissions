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
    // void preorder(TreeNode* root, vector<int>& ans){
    //     if(!root){
    //         return;
    //     }

    //     ans.push_back(root);
    //     preorder(root->right, ans);
    //     preorder(root->left, ans);
    // }

    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }

        swap(root->left, root->right);
        
        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};
