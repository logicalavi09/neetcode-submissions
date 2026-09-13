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
    vector<vector<int>> solve(TreeNode* root){
        if(root == NULL){
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> que;

        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> currentLevel;

            for(int i=0; i<size; i++){
                TreeNode* top_el = que.front();
                que.pop();

                currentLevel.push_back(top_el->val);

                if(top_el->left != NULL){
                    que.push(top_el->left);
                }
                
                if(top_el->right != NULL){
                    que.push(top_el->right);
                }

            }

            ans.push_back(currentLevel);
        }

        return ans;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        return solve(root);
    }
};
