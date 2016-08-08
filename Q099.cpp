/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//morris inorder tranveral time: O(n), space O(1) 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
            
        TreeNode *first =NULL,*second =NULL,*pre=NULL;    
        TreeNode *cur = root;
        while(cur!=NULL) {
            if(cur->left==NULL) {
                if(pre!=NULL&&pre->val>cur->val) {
                    if(first==NULL) {
                        first = pre;
                        second = cur;
                    }
                    else
                        second = cur;
                }
                pre = cur;
                cur = cur->right;
            }
            else {
                TreeNode *pRightMostOfLeftSub = cur->left;
                while(pRightMostOfLeftSub->right!=NULL&&pRightMostOfLeftSub->right!=cur) {
                    pRightMostOfLeftSub = pRightMostOfLeftSub->right;
                }
                if(pRightMostOfLeftSub->right!=cur) {
                    pRightMostOfLeftSub->right = cur;
                    cur = cur->left;
                }
                else {
                    pRightMostOfLeftSub->right = NULL;
                    if(pre!=NULL&&pre->val>cur->val) {
                        if(first==NULL) {
                            first = pre;
                            second = cur;
                        }
                        else
                            second = cur;
                    }
                    pre = cur;
                    cur = cur->right;
                }
            }
        }
        
        if(first!=NULL&&second!=NULL)
            swap(first->val,second->val);
    }
};
