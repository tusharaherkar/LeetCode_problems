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
    bool checkSym(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return true;

        //write all negative scenarios
        if(p != NULL && q == NULL)
            return false;
        
        if(q != NULL && p == NULL)
            return false;
        
        if(p->val != q->val)
            return false;

        //Here traverse ulta of each other
        //refer example
        return checkSym(p->left, q->right) &&
            checkSym(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {

        //corner case 1;
        if(root->left == NULL && root->right == NULL)
            return true;
        
        //though it is covered in below func
        return checkSym(root->left, root->right);

        
    }
};