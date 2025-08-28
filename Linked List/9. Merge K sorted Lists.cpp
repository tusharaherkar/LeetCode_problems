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
        ListNode* merge2sortedLists(ListNode* l1, ListNode*l2)
        {
            //This is usual code to merge two sorted lists l1 and l2
            ListNode* dummy = new ListNode;
            ListNode* res = dummy;
            
            while(l1 && l2)
            {
                if(l1->val <= l2->val)
                {
                    res->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    res->next = l2;
                    l2 = l2->next;
                }
                res = res->next;
            }
            if(l1)
                res->next = l1;
            if(l2)
                res->next = l2;
            
            ListNode *head = dummy->next;
            delete dummy;
    
            return head;
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            //Corner Case 1:
            if(lists.size() == 0)
                return NULL;
            
            // Corner Case 2:
            if(lists.size() == 1)
                return lists[0];
    
            
            // Algo:
            // 1. traverse over all heads of all sorted linked lists one by one
            // 2. consider 2 lists at a time while traversing the lists 
            // 3. Merge these 2 lists by ususal merge2sortedLists()
            // 4. like these 2 merge all 2-2 lists present in given list
            //         [l1,  l2,   l3, l4]
            //           \    /    \   /
            //           [l1_2comb, l3_4_comb]
            // 5. Run the loop untill we get the one sorted lists
            while(lists.size() > 1)
            {   
                vector <ListNode*> mergedLists; 
                for(int i = 0 ; i < lists.size(); i+=2)
                {
                    //Take first list in l1
                    ListNode* l1 = lists[i];
                    //Take second list in l2
                    ListNode* l2 = (((i+1) < lists.size()) ? lists[i+1] : NULL);
    
                    //Merge l1 and l2 and push back in final merged lists
                    mergedLists.push_back(merge2sortedLists(l1, l2));
                }
                lists = mergedLists;
            }
    
            return lists[0];
        }
    };