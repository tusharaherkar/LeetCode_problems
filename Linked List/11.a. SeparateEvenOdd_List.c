/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {

    struct ListNode* trav = head;

    struct ListNode* EvenList = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* OddList = (struct ListNode*) malloc (sizeof(struct ListNode));

    struct ListNode* EvenHead = EvenList;
    struct ListNode* OddHead = OddList;

    while(trav != NULL)
    {
        // if it is even number 
        if(trav->val % 2 == 0)
        {
            EvenList->next = trav;
            EvenList = EvenList->next;
        }
        else
        {
            OddList->next = trav;
            OddList = OddList->next;
        }
        trav = trav->next;
    }
    EvenList->next = OddHead->next;
    free(OddHead);

    trav = EvenHead;
    EvenHead = EvenHead->next;
    free(trav);

    return EvenHead;


}