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
    vector<int> rightSideView(TreeNode* root) {
        
        //Below is the algo for right side view using BFS with the help of queue

        // Do BFS level wise and print only back of queue

        
        // Time Complexity Analysis:
        // we are visiting each node at least once
        // here, O(N) where N is the number of nodes in binary tree

        // Space Complexity Analysis
        // queue used to be of size N
        // here, O(N) where N is the number of nodes in binary tree


        vector <int> rightSideView;
        //Corner Case 1:
        if(root == NULL)
            return rightSideView;

        queue <TreeNode*> q;
        
        q.push(root);

        while(!q.empty())
        {
            int SnapShotQSize = q.size();

            for(int i = SnapShotQSize ; i > 0; i--)
            {
                // for that level (i.e. when we enter first time in for loop)
                // get the rightmost node which will be right view
                if(i == SnapShotQSize)
                {
                    rightSideView.push_back(q.back()->val);
                    //Alternative Que:
                    //If left side view is needed in that case q.front needs to be printed
                }   

                TreeNode* visitiedNode = q.front();
                q.pop();

                if(visitiedNode->left != NULL)
                    q.push(visitiedNode->left);
                
                if(visitiedNode->right != NULL)
                    q.push(visitiedNode->right);
                
                
            }
        }
        return rightSideView;
    }
};