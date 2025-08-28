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
    bool hasPathSum_dfs(TreeNode* root, int targetSum, int CurrSum) {

        if(root == NULL)
            return false;

        // Add current Node's value before checkeding whether it is equal to target sum
        CurrSum += root->val;  
        
        // Only check if it is leaf node
        if(root->left == NULL && root->right == NULL && CurrSum == targetSum)
            return true;

        // Only check if it is leaf node
        if(root->left == NULL && root->right == NULL && CurrSum != targetSum)
            return false;
        
       

        return (hasPathSum_dfs(root->left, targetSum, CurrSum) ||
            hasPathSum_dfs(root->right, targetSum, CurrSum));

    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        return hasPathSum_dfs(root, targetSum, 0);
        
    }
};