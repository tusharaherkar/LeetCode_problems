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
    // LCA of BST is different ques and LCA of BT is different que
public:
    TreeNode* lowestCommonAncestorOptimized(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        
        // Time Complexity:
        // O(h) where h is the height of BST

        // Space Complexity:
        // O(1) = constant space

        while (cur) {
            
            // if p & q both are greater than root go to rightSubtree
            if (p->val > cur->val && q->val > cur->val) 
            {
                cur = cur->right;

            } 
            // if p & q both are less than root go to leftSubtree
            else if (p->val < cur->val && q->val < cur->val) 
            {
                cur = cur->left;
            } 
            // Case 1: Wherever split happens that node would be the Lowest common Ansestor
            // that means p lies on the left subtree and q lies in right subtree that node itself is LCA
            // Case 2: if we encounter one of the nodes between p OR q while traversing 
            // then whichever encountered first return from there 
            else 
            {
                return cur;
            }
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return lowestCommonAncestorOptimized(root, p, q);
        // Time Complexity:
        // O(h) where h is the height of BST

        // Space Complexity:
        // O(h) where h is the height of BST and it uses recursion stack of h

        // if root is NULL return NULL
        if(root == NULL)
            return NULL;

        // if we encounter leaf node then return NULL as this not right candidate for LCA
        if(root->left == NULL && root->right == NULL)
            return NULL;
        
        // if we encounter one of the nodes between p OR q while traversing 
        // then whichever encountered first return from there 
        if(p->val == root->val)
            return p;
        
        if(q->val == root->val)
            return q;


        TreeNode* leftSubtree, *rightSubtree;     

        // if p & q both are less than root go to leftSubtree
        if(p->val < root->val && q->val < root->val)
            leftSubtree = lowestCommonAncestor(root->left, p, q);
        

        // if p & q both are greater than root go to rightSubtree
        if(p->val > root->val && q->val > root->val)
            rightSubtree = lowestCommonAncestor(root->right, p, q);

        // Wherever split happens that node would be the Lowest common Ansestor
        // that means p lies on the left subtree and q lies in right subtree that node itself is LCA
        if(p->val < root->val && q->val > root->val)
            return root;
        
        
        // Wherever split happens that node would be the Lowest common Ansestor
        // that means p lies on the right subtree and q lies in left subtree that node itself is LCA
        if(p->val > root->val && q->val < root->val)
            return root;

        return (rightSubtree != NULL ?  rightSubtree : leftSubtree);
        
    }
};