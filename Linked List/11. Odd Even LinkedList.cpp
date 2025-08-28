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
//Que : Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            // Algo:
            // 1. Create Dummy node for OddPtr named as OddDummyhead
            // 2. Create Dummy node for EvenPtr named as EvenDummyhead
            // 3. initialize count as 1
            // 4. declare ListNode* trav to do traversal inside LL
            // 5. If count is odd number then link OddPtr's next to trav, progress OddPtr
            // 6. If count is even number then link EvenPtr's next to trav progress EvenPtr
            // 7. progress trav and loop this till trav becomes NULL
            // 8. Atlast link oddPtr with EvenDummyhead's next
            // 9. Delete both dummy heads and Return OddDummyhead->next 

            // Time Complexity Analysis:
            // O(N) where N is the number of nodes in LL

            // Space Complexity Analysis
            // O(1) no extra space required = constant space
            

            ListNode* Evenhead = new ListNode;
            ListNode* Oddhead = new ListNode;
    
            ListNode* OddPtr = Oddhead;
            ListNode* EvenPtr = Evenhead;
    
            ListNode* trav = head;
            int count = 1;
    
            while(trav != NULL)
            {
                if(count % 2)
                {
                    OddPtr->next = trav;
                    OddPtr = trav;
    
                }
                else
                {
                    EvenPtr->next = trav;
                    EvenPtr = trav;
                }
                trav = trav->next;
                count++;
            }
            EvenPtr->next = NULL;
            OddPtr->next = Evenhead->next;
            delete Evenhead;
            OddPtr = Oddhead->next;
            delete Oddhead;
            return OddPtr;
            
        }
    };