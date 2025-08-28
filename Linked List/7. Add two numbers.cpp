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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
            ListNode *new_head = l1;
            int carry = 0;
            int posSum = 0;
            ListNode* prev = l1;
            
            // Traverse l1 and l2 
            // change l1's content which is addition of posSum of l1+l2
            while(l1 && l2)
            {
                posSum = (l1->val) + (l2->val) + carry;
                if(posSum >= 10)
                {
                    l1->val = posSum-10;
                    carry = 1;
                }
                else
                {
                    l1->val = posSum;
                    carry = 0;
                }
                prev = l1; // tracked prev as l1 may exaust early
                           // In such case l2 to be appended via prev
                l1 = l1 -> next;
                l2 = l2 -> next;
                
            
            }
            // if l2 is not exausted but l1 has exausted
            // then point l2 to l1 by maintaining prev pointer in l1
            // So from nowonwards we need to consider l1 not l2
            if(l2 != NULL)
            {
                prev->next = l2;
                prev = l1;
                l1 = l2;
            }
            // if l2 is exausted and l1 is still not exasted 
            // Need to continue in l1
            while(l1 != NULL)
            {
                posSum = l1->val + carry;
                if(posSum >= 10)
                {
                    l1->val = posSum-10;
                    carry = 1;
                }
                else
                {
                    l1->val = posSum;
                    carry = 0;
                }
                prev = l1; // tracked prev to add carry which is occuring at the last
                l1=l1->next;
            }
    
            // if carry present
            // Add new node in l1
            // append it via prev node
            if(carry)
            {
                ListNode* new_node = new ListNode;
                new_node->val = carry;
                new_node->next = NULL;
                prev->next = new_node;
            }
            return new_head;
    
            
        }
    };