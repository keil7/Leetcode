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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||p==NULL||q==NULL)
            return NULL;
        if(p==q)//p,q same node
            return p;
        //make p->val>a->val for convenience    
        if(p->val<q->val) swap(p,q);
        
        if(root->val>p->val)//in left sub-tree
            return lowestCommonAncestor(root->left,p,q);
        else if(root->val<q->val)//in right sub-tree
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    }
};
