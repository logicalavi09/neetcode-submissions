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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q)
            return true;

        if(!p || !q)
            return false;

        queue<TreeNode*> que1;
        queue<TreeNode*> que2;

        que1.push(p);
        que2.push(q);

        while(!que1.empty() && !que2.empty()){

            TreeNode* top1 = que1.front();
            TreeNode* top2 = que2.front();

            que1.pop();
            que2.pop();

            // Compare values
            if(top1->val != top2->val)
                return false;

            // Left child
            if(top1->left && top2->left){
                que1.push(top1->left);
                que2.push(top2->left);
            }
            else if(top1->left || top2->left){
                return false;
            }

            // Right child
            if(top1->right && top2->right){
                que1.push(top1->right);
                que2.push(top2->right);
            }
            else if(top1->right || top2->right){
                return false;
            }
        }

        return que1.empty() && que2.empty();
    }
};