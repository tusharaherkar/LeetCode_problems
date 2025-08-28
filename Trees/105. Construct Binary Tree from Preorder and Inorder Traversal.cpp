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
    // The soln uses hashmap and dfs
    // Intution:
    // first construct hashmap with inorder traversal and their corresponding positions as values
    // Start constructing the nodes with preorderIdx 

    int preorderIdx = 0;
    unordered_map <int, int> inorderMap;

    TreeNode* buildTree_dfs(vector<int>& preorder, vector<int>& inorder, int inorderPosStart, int inorderPosEnd){
        
        // Base Case 1: 
        // When inorderPosStart overshoots inorderPosEnd
        if(inorderPosStart > inorderPosEnd)
            return NULL;
        
        // Base Case 2: 
        // preorderIdx becomes >= preorder.size
        if(preorderIdx >= preorder.size())
            return NULL;
        
        // Forming Node from preorderIdx inside preorder
        int formNode = preorder[preorderIdx++];
        
        // Form Node
        TreeNode* root = new TreeNode(formNode);

        // Get the position from inorderMap
        int posMidInorder = inorderMap[formNode];

        // Form the left Subtree
        root->left = buildTree_dfs(preorder, inorder, inorderPosStart, posMidInorder-1);
    
        // Form the right Subtree
        root->right = buildTree_dfs(preorder, inorder, posMidInorder+1, inorderPosEnd);

        return root;
    } 

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Construct hashmap with inorder traversal and their corresponding positions as values
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return buildTree_dfs(preorder,inorder, 0, inorder.size()); 
        
    }
};