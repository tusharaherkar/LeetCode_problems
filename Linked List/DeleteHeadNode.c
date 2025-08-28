void deleteHeadNode(ListNode **head)
{
    // Case 1: 1-> 2-> 3-> NULL
 
    // Case 2: NULL
    // Case 3: 1 -> NULL
    
    if(*head == NULL || **head == NULL)
        return;
    
    ListNode* newHead = NULL;
    ListNode* curr = (*head);
    
    if((*head)->next)
        newHead = (*head)->next;
    
    (*head) = newHead;
    
    if(curr)
        free(curr);
}
