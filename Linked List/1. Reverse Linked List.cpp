/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    
        ListNode* reverseList(ListNode* head) {
            
            // This is recursive function call to reverseList():
            // Ex: 1 -> 2 -> 3 -> 4-> 5 -> NULL
            // Algo (Recursive Approach):
            // Time Complexity Analysis:
            // traverse each node atleast once here O(N) where N is the number of elements in LL

            // Space Complexity Analysis
            // recursion stack will take O(N) where N is the number of elements in LL

            // Corner case 1:
            if(head == NULL)
            {
                return NULL;
            }
            // Base case of recursion: if it reached end of LL return the last node*
            if(( head->next == NULL))
                return head;
    
            // here rest will have new_head pointer which needs to be returned from last function call
            ListNode* rest = reverseList(head->next) ;
            
            // This is to reverese the two nodes links
            head->next->next = head;
            
            // every time curr call of head->next we are making NULL
            head->next = NULL;
    
            // return new_head from each of call stack
            return rest;
        }
    };