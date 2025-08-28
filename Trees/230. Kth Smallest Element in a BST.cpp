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
    vector <int> inorder;

public:
    void dfs_inorderOptimized(TreeNode* root, int &cnt, int &ans, int k)
    {
        if(root == NULL)
            return;
        
        dfs_inorderOptimized(root->left, cnt, ans, k);
        
        cnt++;

        if(cnt == k)
        {
            ans = root->val;
            return;
        }
        
        dfs_inorderOptimized(root->right, cnt, ans, k);


    }

    int kthSmallestOptimized(TreeNode* root, int k) {

        // Intution:
        // while traversing for inorder traversal of the BST 
        // return inc cnt and check cnt reached k or not 
        // once it reaches k then lock that val in ans variable which is passed as reference to inorder

        //        5
        //       / \
        //      3   6
        //      /\
        //     2  4
        //     /
        //     1
        // Inorder traversal: 1 → 2 → 3 → 4 → 5 → 6
        // If k = 3, the 3rd smallest is 3

        // Time Complexity Analysis:
        // we are visiting each node at least once till count k
        // here, O(K) where K is given input

        // Space Complexity Analysis
        // recursion stack is used for traversing K nodes
        // here, O(K) where K is given input 

        int cnt = 0;
        int ans = 0;
        
        dfs_inorderOptimized(root, cnt, ans, k);
        
        return ans;

    }
    
    void dfs_inorder(TreeNode* root)
    {
        if(root == NULL)
            return;

        dfs_inorder(root->left);

        inorder.push_back(root->val);

        dfs_inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {

        // Intution:
        // Get the inorder traversal of the BST 
        // return k-1th element from that inorder traversal of BST
        //        5
        //       / \
        //      3   6
        //      /\
        //     2  4
        //     /
        //     1
        // Inorder traversal: 1 → 2 → 3 → 4 → 5 → 6
        // If k = 3, the 3rd smallest is 3

        // Time Complexity Analysis:
        // we are visiting each node at least once
        // here, O(N) where N is the number of nodes in BST

        // Space Complexity Analysis
        // recursion stack is used for traversing N nodes
        // here, O(N) where N is the number of nodes in BST
        return kthSmallestOptimized(root, k);

        dfs_inorder(root);    

        return inorder[k-1];
    }
};
