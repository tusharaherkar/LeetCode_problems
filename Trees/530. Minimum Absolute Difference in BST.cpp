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

    int minDiff;

public:
    //Sending prevNode as & is very important as prevNode will be always constant for a tree
    // So pass by reference 
    void dfs_inorder(TreeNode* root, TreeNode* &prevNode)
    {
        if(root == NULL)
            return;


        dfs_inorder(root->left, prevNode);

        if(prevNode != NULL)
            minDiff = min(minDiff, abs(prevNode->val - root->val));
        
        // currentNode will become previous Node now
        prevNode = root;

        dfs_inorder(root->right, prevNode);

    }
    int getMinimumDifference(TreeNode* root) {
        
        minDiff = INT_MAX;

        TreeNode* prev = NULL;

        dfs_inorder(root, prev);

        return minDiff;
        
    }
};