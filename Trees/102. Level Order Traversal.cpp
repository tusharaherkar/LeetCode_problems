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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Level Order Traversal is done by using Queue

        // level by level add in the queue and then visit them
        
        // Time Complexity Analysis:
        // we are visiting each node at least once
        // here, O(N) where N is the number of nodes in binary tree

        // Space Complexity Analysis
        // queue used to be of size N
        // here, O(N) where N is the number of nodes in binary tree


        vector<vector<int>> ans;
        // Corner Case 1:
        if(root == NULL)
            return ans;

        //Define queue of TreeNode* to push the elements
        queue <TreeNode*> levelOrder;
        
        //Push root element to start traversing
        levelOrder.push(root);
   
        while(!levelOrder.empty())
        {
            vector <int> level;
            
            //snapshot q size at the level order and visit those many nodes which are currenly in q
            for(int i = levelOrder.size(); i > 0 ; i--)
            {
                //get the front from queue
                TreeNode* visit = levelOrder.front();
                // Once visited then pop
                levelOrder.pop();
                
                //append that in vector level to print
                level.push_back(visit->val);
                
                //if visited node has left child then push in queue
                if(visit->left)
                    levelOrder.push(visit->left);

                //if visited node has right child then push in queue
                if(visit->right)   
                    levelOrder.push(visit->right);
                
            }
            //if level has some nodes then only push in final ans vector of vector
            if(level.size())
                ans.push_back(level);
        }
        return ans;
    }
};