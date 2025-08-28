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
        ListNode* reverseList(ListNode* head, ListNode* Temp)
        {
            // Corner case 1:
            if(head == NULL)
            {
                return NULL;
            }
            // Base case
            if(head->next == Temp)
            {
                return head;
            }
    
            ListNode* rem = reverseList(head->next, Temp);
    
            head->next->next = head;
    
            head->next = NULL;
    
            return rem;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
    
            ListNode* Temp = head;
            int count = 0;
            
            while(Temp != NULL && count < k)
            {
                Temp = Temp->next;
                count++;
            }
            
            // for the last chunk if temp has not progressed enough then 
            // dont perform any reversing just return
            if(count < k) return head;
            
            // reverse the list from head till temp
            ListNode* new_head = reverseList(head, Temp);
    
            //cout<<"Temp denoting to: "<<Temp->val<<endl;
    
            //return new_head;
            
            // the caller head->next to pointed to new_head coming from reverseList
            head->next = reverseKGroup(Temp, k);
    
            return new_head;
    
            
        }
    };