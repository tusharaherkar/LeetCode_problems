/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        bool hasCycle(ListNode *head) {
    
            
            
            // Corner Case 1:
            //If the Linked list is empty then the cycle 
            //can not be present in it
            if(head == NULL)
                return false;
            
            // Corner case 2
            if(head->next == NULL)
                return false;
            
            // Algo (fast and slow pointers):
            // 1. Initialize fast pointer to head->next
            // 2. Initialize slow pointer to head 
            // 3. fast will move fast->next->next
            // 4. slow will move slow->next
            // 5. if cycle present both pointers eventually meets at a point then return true
            // 6. loop it till fast!=NULL and slow!=NULL

            // Time Complexity Analysis:
            // Worst case: Each Node has to be viisted atleast once
            // So, overall O(N) where N is the number of nodes in LL

            // Space Complexity Analysis
            // No extra space required here O(1) = constant space

            ListNode* fast = head->next;
            ListNode* slow = head;
            
    
            while(fast!= NULL && slow != NULL)
            {
                if(fast == slow)
                {
                    //cout<<"met at val: " <<fast->val<<" jumped: "<<count<<endl;
                    return true;
                }

                if(fast->next == NULL)
                    return false;
                fast = fast->next->next;
                slow = slow->next;
            }
            return false;
            
        }
    };