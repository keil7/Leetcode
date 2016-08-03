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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        int newVal = sum-root->val;
        //leaf
        if(root->left==NULL&&root->right==NULL)
            return newVal==0;
        //not leaf    
        return (root->left==NULL?false:hasPathSum(root->left,newVal))||(root->right==NULL?false:hasPathSum(root->right,newVal));
    }
};
