/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
    
    
        Node* copyRandomListWithoutExtraSpace(Node* head)
        {
            //Algo/ Intution
            // In first pass: 
            //          a. create all nodes of L2 by traversing the given L1
            //          b. Make L1' next pointer to point to L2's newly created node (this will be acted as hashmap)
            // In second pass:
            //          a. Make L2's random pointers aligned properly
            // In third pass:
            //          a. Make Next pointers to point to proper nodes as per given 

            Node* trav = head;
    
            //First Pass
            while(trav != NULL)
            {
                Node *temp = new Node(trav->val);
                
                //Create Node
                //Allow that node's next to point to L1's next
                temp->next = trav->next;
                //modify L1's next to point to temp which will act as Map
                trav->next = temp;
    
                //Inc trav
                trav = temp->next;
            }
    
            Node* travL1 = head;
            //check whether L2 is created or not
            // while(travL1 != NULL)
            // {
            //     //cout<< " " <<travL1->val;
            //     travL1 = travL1->next;
            // }
            //cout<<endl;
    
            //Initialize travL2 pointer to point to L2's head i.e. L1 head's -> random is pointing to L2's head
            travL1 = head;
            Node* travL2 = head->next;
            Node* new_head = head->next;
    
            //Second Pass
            //In second pass, get random pointer's of L2 properly aligned
            while(travL1 != NULL)
            {
                if(travL1->random != NULL)
                    travL2->random = travL1->random->next;
                
                //Inc travL1 first to make easy for travL2 to traverse through L2
                travL1 = (travL2->next);
                if(travL1) //This condn is for last node suppose travL2 is pointing to last node of list L2
                    travL2 = (travL1->next); //this is for last node of L2
            }
    
            //Third Pass: restore L1's and L2's next pointer properly
            travL1 = head;
            travL2 = travL1->next;  //first set travL2 to L2'head
    
            while(travL2 != NULL)
            {
                //first get to next node of L1
                Node* L1Next = travL2->next;
    
                //Allow travL1 to point to next of L1
                travL1->next = L1Next;
    
                if(L1Next != NULL) //This is to avoid if L1Next should not be NULL for last node
                    travL2->next = L1Next->next;
    
                //cout<<"L1: "<<travL1->val;
                //cout<<"L2: "<<travL2->val;
                //Inc travL1 and travL2
                travL2 = (travL2->next);
                travL1 = (travL1->next);
    
            }
            return new_head;
        }
        Node* copyRandomList(Node* head) {
    
            //corner case 1: 
            if(head == NULL)
                return NULL;
    
            return copyRandomListWithoutExtraSpace(head);
            
            // Algo (With Extra space):
            // 1. declare Map of <Node*, Node*> which will be mapping between orginal L1 and created L2
            // 2. traverse the map and write random and next pointers appropriately
            
            //The below approach uses map of size N which is extra space
            unordered_map <Node*, Node*> map;
    
            Node *trav = head;
            //Traverse whole LL and form empty Nodes with orgnode's values
            while(trav != NULL)
            {
                Node *temp = new Node(trav->val);
                //Keep map of OrgNodes associated with each and every node of formed LL
                map[trav] = temp;
                trav = trav->next;
            }
            
            //Traverse Map one by one
            for(auto &it : map)
            {
                //This is org LL Node
                Node *OrgNode = it.first;
                //This is deep copied Node
                Node *cpyNode = it.second;
    
                //write random and next pointers based on orginal nodes's next & random mapped node 
                cpyNode->next = ((OrgNode->next == NULL) ? NULL : map[OrgNode->next]);
                cpyNode->random = ((OrgNode->random == NULL) ? NULL : map[OrgNode->random]); 
                
            }
    
            //return head of new node
            return map[head];        
        }
    };