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
    int calculateDepth(TreeNode* root)
    {
        TreeNode* trav = root;
        int countedDepth = 0;

        while(trav != NULL)
        {
            trav  = trav->left;
            countedDepth++;
        }
        return countedDepth;
    }
    int countNodes(TreeNode* root) {
        // Intution:
        // Intution is based on below two examples
        // Example 1:
        //		 4
        //	    / \
        //	   5   6
        //	  / \  / \
        //   7  8  9  3
        
        // Example 2:
        //		 4
        //	    / \
        //	   5   6
        //	  / \  / \
        //   7  

        // 2 facts about above two examples
        // Fact 1: if the leftDepth and rightDepth are same then leftSubtree is perfect binary tree 
        //         that means leftSubtree has 2 ^ leftDepth - 1  nodes and we just need to count the nodes in rightSubtree
        // Fact 2: if the leftDepth and rightDepth are not same then rightSubtree is perfect binary tree till rightDepth
        //         So rightSubtree will surelly have 2 ^ rightDepth - 1  nodes and we just need to count the nodes in leftSubtree
        // This is how we can calculate the total number of nodes in perfect binary tree

        // Here depth can be calculated by traversing to leftmost child as it is perfect binary tree

        if(root == NULL)
            return 0;

        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);

        if(leftDepth == rightDepth)
        {
            return (1<<leftDepth) + (countNodes(root->right));
        }

        return (1<<rightDepth) + (countNodes(root->left));


    }
};