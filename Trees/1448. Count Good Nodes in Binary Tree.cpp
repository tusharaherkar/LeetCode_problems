
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
    int TotalGoodNodes;

    void dfs(TreeNode* root, int goodNodeVal)
    {
        // return if root is NULL
        if(root == NULL)
            return;
        
        //if the current root cal is >= currMax then update the currMax and globally tracked TotalGoodNodes
        if(root->val >=  goodNodeVal)
        {
            TotalGoodNodes++;
            goodNodeVal = root->val;
        }   
        
        
        //leaf node then return 
        if(root->left == NULL && root->right == NULL)
            return;
        
        // give recurssive call to left subtree
        dfs(root->left, goodNodeVal);

        // give recurssive call to right subtree
        dfs(root->right, goodNodeVal);
    }


    int goodNodes(TreeNode* root) {
        TotalGoodNodes = 0;

        // Corner Case 1:
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        // giving call to dfs function to track currMax which is nothing but goodNodeVal
        dfs(root, root->val);

        
        // Time Complexity Analysis:
        // we are visiting each node at least once
        // here, O(N) where N is the number of nodes in binary tree

        // Space Complexity Analysis
        // queue used to be of size N
        // here, O(N) where N is the number of nodes in binary tree

        // return globally tracked goodNodes
        return TotalGoodNodes;
    }
};