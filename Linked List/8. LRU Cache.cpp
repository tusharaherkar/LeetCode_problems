class LRUCache {
    // Que: LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    // int get(int key) Return the value of the key if the key exists, otherwise return -1.
    // void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    // The functions get and put must each run in O(1) average time complexity.

 
    class DLL
    {
        public:
        int key;
        int value;
        DLL* prev;
        DLL* next;
    };
   
public:
    // Maintain 2 data structures for LRU cache
    // 1. DLL -> for least recent access denoted by head and rule of eviction which happens at tail
    // 2. unordered_map <int, DLL*> -> to get and put functions
    //              for get(): hashmap is used to check if the key exists or not if exists return its corresponding value 
    //                         Also, straightaway goto node and append that node in the head side
    //              for put(): if the key exists directly update the value and 
    //                          straightaway goto node and append that node in the head side

    unordered_map<int, DLL*> map;
    DLL *head;
    DLL *tail;
    int currSize;
    int maxSize;


    void CreateNode(int key, int value)
    {
        DLL* new_node = new DLL;
        new_node->key = key;
        new_node->value = value;
        // if newly created DLL head and tail needs to be initialized properly
        if(head == NULL && tail == NULL)
        {
            new_node->next = NULL;
            new_node->prev = NULL;
            head = tail = new_node;
        }
        // Always create and append the node before head 
        // as recently accessed node will head
        else
        {
            //Adjust the pointers accordingly
            new_node->prev = NULL;
            new_node->next = head;
            head->prev = new_node;
            //update the head
            head = head->prev;
        }
        //update in map
        map[key] = new_node;
    } 

    void DeleteNode(DLL *node)
    {
        //1. if node is headnode i.e.  if(node->prev == NULL)
        //2. if node is tailnode i.e   if(node->next == NULL)        
        //3. if single Node present
        //4. If node is in between
        if(node->prev == NULL && node->next == NULL)
        {
            // single Node present
            //cout<<"It has only single node present in DLL" <<endl;
            delete node;
            head = NULL;
            tail = NULL;
            return;

        }
        else if(node->prev == NULL) // If node is headNode
        {
            //cout<<"Delete Node: headnode" <<endl;
            head = node->next;
            head->prev = NULL;
            delete node;
            return;
        }
        else if(node->next == NULL)  // If node is tailnode
        {
            //cout<<"Delete Node: tailnode" <<endl;
            tail = node->prev;
            tail->next = NULL;
            delete node;
            return;
        }
        else
        {
            //cout<<"Delete Node: in between" <<endl;
            DLL* prevNode = node->prev;
            DLL* nextNode = node->next;
            
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete node;
            return;
        }
    }
    
    LRUCache(int capacity) {

        currSize = 0;
        maxSize = capacity;   
        head = NULL;
        tail = NULL;     
    }
    
    int get(int key) {
        // Corner case 1:
        // if key is not present in map then return -1
        if(map.size() == 0 || map.find(key) == map.end())
            return -1;
        
        // If key is found
        DLL* found_node = map[key];
        int valueTobeReturned = found_node->value;

        DeleteNode(found_node);
        
        CreateNode(key, valueTobeReturned);

        // search in map, if not found return -1 
        // if found, get its pointer 
        // from pointer, take the value to be returned but before follow below steps
        // before returning the value, the accessed node is considered as Most Recently used element
        // Delete the node from its original position in DLL
        // Create new node and place it at head position Hence, MRU element
        // place  the address in Map
        // return the valueTobeReturned
        return valueTobeReturned;
    }
    
    void put(int key, int value) {

        // if(map.size() == 0) , then create head node and keep head and tail at same postion
        if(map.size() == 0)
        {
            // create Node with head and tail
            CreateNode(key, value);
        }
        else
        {
            // 1. if map has some elements in it
            // 2. First try to find the element(map.find(key))
            // 3. If found, then update the value and make it as MRU
            //
            if(map.find(key) != map.end())      
            {
                DLL* found_node = map[key];

                DeleteNode(found_node);
                
                CreateNode(key, value);

            }
            else
            {
                //If not found then 
                //      if map size is less than max size then create node and append at head
                //      if map size is max_size then apply rule of eviction
                //              Rule of eviction says delete tail from DLL and map

                if(map.size() < maxSize)
                {
                    //cout<<"Put [" << key <<","<<" "<< value <<"] as next to headnode" <<endl;
                    CreateNode(key, value);

                }
                else if(map.size()  ==  maxSize)
                {
                    //Apply rule of eviction
                    //delete evicted tail key from map                    
                    map.erase(tail->key);
                    DeleteNode(tail);
                    
                    //Create Node and append at head position
                    CreateNode(key, value);
                }
            }
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */