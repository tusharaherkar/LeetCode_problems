/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//Que: Given the head of a linked list, rotate the list to the right by k places.

struct ListNode* rotateRight(struct ListNode* head, int k) {
    

    int count = 0;

    struct ListNode* temp = head;

    // first pass 
    // count the number of nodes
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Corner case 1:
    if(count == 0)
        return NULL;
    
    k = k % count;
    count = 0;

    if(k == 0)
        return head;

    temp = head;
    while(temp != NULL && count < k)
    {
        count++;
        temp = temp->next;
    }

    struct ListNode* dummy  = (struct ListNode*) malloc (sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = dummy; 
    struct ListNode* curr = head;
    struct ListNode* tail = head;

    while(temp != NULL)
    {
        prev = curr;
        curr = curr->next;
        if(temp->next == NULL)
            tail = temp;
        
        temp = temp->next;
    }

    prev->next = NULL;
    tail->next = head;
    head = curr;
    free(dummy);

    return head;

}