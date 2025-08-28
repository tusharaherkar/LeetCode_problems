// LCA of BST is different ques and LCA of BT is different que

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

        
        // Time Complexity:
        // O(N) where N is the number of nodes in BT
        // lets assume if the tree is skewed 

        // Space Complexity:
        // O(N) where N is the number of nodes in BT
        // lets assume if the tree is skewed 

        // if root is NULL return NULL
        if(root == NULL)
            return NULL;

        // if p and q both are same return one of them
        if(p == q) 
            return p;

        // while traversing dfs if we encounter one of p & q then return that 
        if(p == root || q == root)
            return root;

        // if we encounter leaf node then return NULL as this not right candidate for LCA
        if(root->left == NULL && root->right == NULL)
            return NULL;  

        //recursive call to left subTree
        TreeNode* leftSubtree = lowestCommonAncestor(root->left, p, q);
        
        //recursive call to right subTree
        TreeNode* rightSubtree = lowestCommonAncestor(root->right, p, q);
        
        // if some returning node coming from leftSubtree and right Subtree then return current root 
        // as current root will be known as LCA not the leftSubtree or rightSubtree
        if (rightSubtree != NULL && leftSubtree != NULL)
            return root;

        // if LCA exists in leftSubtree then return leftSubtree or else return rightSubtree
        return (leftSubtree != NULL ? leftSubtree : rightSubtree);
        
    }
};