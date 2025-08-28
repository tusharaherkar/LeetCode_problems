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
    bool isValidBST_dfs(TreeNode* root, long leftBoundary, long rightBoundary) {

        //if root/current Node is NULL then it is valid BST
        if(root == NULL)
            return true;
        
        //check if root val falls between leftBoundary and rightBoundary
        // if not return false;
        if(root->val <= leftBoundary || root->val >= rightBoundary)
            return false;

        // give recursive calls to left and right subtrees with && operation as both of them should be valid BST
        // But when traversing to left subtree the rightBoundary will be changed to current node val
        // and when traversing to right subtree the leftBoundary will be changed to current node val
        
        return isValidBST_dfs(root->left, leftBoundary, root->val) && isValidBST_dfs(root->right, root->val, rightBoundary);

    }

    bool isValidBST(TreeNode* root) {
        // Time Complexity Analysis:
        // O(N) where N is the number of nodes in the BST

        // Space Complexity Analysis
        // O(N) where N is the number of nodes in the BST for recursion stack

         
        // Call the function with more args  mainly for tracking leftBoundary and RightBoundary
        return isValidBST_dfs(root, LONG_MIN, LONG_MAX);        
        
        // LONG_MIN and LONG_MAX is given to the function to cover cases like
        // root consists of INT_MIN/ INT_MAX value 
        // 
    }
};