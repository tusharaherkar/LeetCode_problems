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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            // Algo:
            // 1. Create Dummy node which will act as new_head of merged LL
            // 2. traverse list1 and list2 and append nodes one by one based on comparison
            // 3. Check if any nodes left in list1 OR list2 if yes then append those remaining nodes
            // 4. Delete dummy node which created on step1

            // Time Complexity Analysis:
            // Need to traverse elements of lists 1 and lists2 one by one here O(M+N)
            // where M is the length of list1 LL
            // where N is the length of list2 LL
            // 

            // Space Complexity Analysis
            // No extra space required O(1) = constant space
            

            // Create Dummy node which will act as new_head of merged LL
            ListNode* dummy = new ListNode(0);
    
            ListNode* curr = dummy;
            
            // traverse list1 and list2 and append nodes one by one based on comparison
            while(list1 && list2)
            {
                if(list1->val <= list2->val)
                {
                    curr->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    curr->next = list2;
                    list2 = list2->next;
                }
                curr = curr->next;
            }

            // Check if any nodes left in list1 OR list2 if yes then append those remaining nodes
            if(list1)
            {
                curr->next = list1;
            }

            // Check if any nodes left in list1 OR list2 if yes then append those remaining nodes
            if(list2)
            {
                curr->next = list2;
            }
            
            // Delete dummy node which created on step1
            curr = dummy->next;
            delete dummy;
    
            return curr;
            
        }
    };