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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
            
        int leftHeight = 0;
        int rightHeight = 0;
        for(TreeNode *p=root->left;p!=NULL;p=p->left)
            leftHeight++;
        for(TreeNode *p=root->right;p!=NULL;p=p->right)
            rightHeight++;
            
        if(leftHeight==rightHeight)
            return (1<<(leftHeight+1))-1;//2^(leftHeight+1)-1
            
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

//solution ELT, to-do:further check
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        deque<TreeNode *> q;
        int h = 0;
        q.push_front(root);
        while(!q.empty()&&q.back()->right!=NULL) {
            for(int i=pow(2,h);i>0;--i) {
               q.push_front(q.back()->right);
               q.push_front(q.back()->left);
               q.pop_back();
            }
            h++;
        }
            
        while(!q.empty()&&q.back()->right==NULL&&q.back()->left==NULL)
            q.pop_back();
        if(q.empty())
            return pow(2,h+1)-1;
        else if(q.back()->right!=NULL)
            return pow(2,h+1)+2*q.size()-1;
        else
            return pow(2,h+1)+2*q.size()-2;
    }
};
