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
    int postOrderIdx = 0;
    unordered_map <int, int> inorderMap;

    TreeNode* buildTree_dfs(vector<int>& postorder, int L, int R) {

        if(L > R)
            return NULL;
        
        if(postOrderIdx < 0)
            return NULL;
        
        int formNode = postorder[postOrderIdx--];

        int midInorderPos = inorderMap[formNode];

        TreeNode* root = new TreeNode(formNode);

        
        root->right = buildTree_dfs(postorder, midInorderPos+1, R);
        root->left = buildTree_dfs(postorder, L, midInorderPos-1);


        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        postOrderIdx = postorder.size() - 1;

        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return buildTree_dfs(postorder, 0, postorder.size() - 1);
    }
};