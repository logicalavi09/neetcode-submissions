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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return{};
        }

        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> currLevel;

            for(int i=0; i<size; i++){
                TreeNode* front_el = que.front();
                que.pop();
                currLevel.push_back(front_el->val);

                if(front_el->left != NULL){
                    que.push(front_el->left);
                }

                if(front_el->right != NULL){
                    que.push(front_el->right);
                }
            }

            ans.push_back(currLevel.back());
        }
        return ans;
    }
};
