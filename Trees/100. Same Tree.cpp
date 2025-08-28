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

        if((p == NULL) && (q == NULL))
            return true;
        
        //write all negative scenarios
        if(p!=NULL && q == NULL)
            return false;
        if(q!=NULL && p == NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        
        //If we traverse the left of p and same with q 
        //and if we traverse the right of p and same with q both has to return true that is why && operation exists
        return (isSameTree(p->left, q->left) && 
        isSameTree(p->right, q->right));      
    }
};