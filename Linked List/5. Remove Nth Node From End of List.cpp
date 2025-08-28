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
    // Que: Given the head of a linked list, remove the nth node 
    // from the end of the list and return its head.
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Ex:  1, 2, 3, 4, 5 -> NULL
        // n = 2
        // delete 4 from the LL because it is last 2nd node

        // Corner case 1:
        if(head == NULL)
        {
            return NULL;
        }
        // Corner case 2:
        if(head->next == NULL)
        {
            delete head;
            return NULL;
        }
        
        // Algo:
        // create dummy node to handle if the head of the LL needs to be deleted
        // make count = 0
        // make dummy node->next = head;
        // Make ListNode* trav start from head
        // Let it go n places ahead 
        // now ListNode* curr = head
        // ListNode*  prev = dummy node created
        // make trav go till NULL i.e. end of LL while making go till end make prev++ and curr++
        // when trav reaches end curr will be the node which will be getting deleted
        // prev will be the pointer previous to current
        // now delete curr by altering prev->next = curr->next
        // return dummy->next as it will final outcome LL


        ListNode* new_head = new ListNode;
        new_head->next = head;

        ListNode* prev = new_head;

        ListNode* curr = head;
        
        ListNode* trav = head;

        int count = 0;

        while(trav != NULL && count < n)
        {
            trav = trav->next;
            count++;
        }
        curr = head;

        while(trav != NULL)
        {
            prev = curr;
            curr = curr->next;
            trav = trav->next;
        }
        prev->next = curr->next;
        delete curr;
        curr = new_head->next;
        delete new_head;
        return curr;
        
    }
};