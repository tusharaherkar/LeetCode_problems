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
    // Que: You are given the head of a singly linked-list. The list can be represented as:

    // L0 → L1 → … → Ln - 1 → Ln
    // Reorder the list to be on the following form:

    // L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    // You may not modify the values in the list's nodes. Only nodes themselves may be changed. 
    public:
        ListNode* reverseList(ListNode* head)
        {
            // This is standard algo to reverse the list
            // Time complexity: O(N)
            // Space complexity: O(N) for using recursion stack

            if(head == NULL)
                return NULL;
            if(head->next == NULL)
                return head;
    
            ListNode* new_head = reverseList(head->next);
    
            head->next->next = head;
    
            head->next = NULL;
    
            return new_head;
    
        }
        void reorderList(ListNode* head) {
            //Algo/ Intution:
            //1. Find the middle of the list by slow fast pointer method
            //2. slow pointer will showcase the middle of the list
            //3. reverse the list from slow->next
            //4. Alternatively append L1 and L2 by altering the next pointer of L1 and L2
            
            // Time Complexity Analysis:
            // Worst case we need to traverse the LL from front and back
            // Hence, O(N) where N is the number of elements in LL


            // Space Complexity Analysis
            // recursion stack of reverseList() will take O(N) where N is the number of elements in LL
            // other than that no extra space 
            // So, overall O(N) where N is the number of elements in LL
            
            ListNode* slow = head;
            ListNode* fast = head->next;
    
            //Increase fast pointer to end of the list 
            //the slow pointer will traverse till middle of the list
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                if(fast->next != NULL)
                    fast = fast->next->next;
            }
    
            //reverse the LL from slow->next
            ListNode* new_head = reverseList(slow->next);
            // make tail of left LL point  to NULL 
            // then it will be meaningfull LL
            slow->next = NULL;
    
            ListNode* travL1 = head;
            ListNode* travL2 = new_head;
            
            //Alternatively, append L1 and L2 by altering the next pointer of L1 and L2
            while(travL1 != NULL && travL2 != NULL)
            {
                ListNode* travL1_plus1 = travL1->next;
                ListNode* travL2_plus1 = travL2->next;
    
                travL1->next = travL2;
                travL2->next = travL1_plus1;
    
                travL1 = travL1_plus1;
                travL2 = travL2_plus1;
            }
    
    
    
        }
    };