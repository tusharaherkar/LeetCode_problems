class RandomizedSet {
    public:
        vector <int> Store;
        unordered_map <int, int> posStore;
    
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
    
            // If present then don't insert
            if(posStore.find(val) != posStore.end())
                return false;
            // if not present then push in Store
            else 
            {
                Store.push_back(val);
                posStore[val] = Store.size()-1;
                return true;
            }
        }
        
        bool remove(int val) {
            //if present
            if(posStore.find(val) != posStore.end())
            {
                // get the pos
                // exchange with last element
                // change the values in map
                // update the map
                // delete last element of vector
                // delete the map
    
                int pos = posStore[val];
                swap(Store[pos], Store[Store.size()-1]);
                
                //Now the postions are exchanged hence change the map
                posStore[Store[pos]] = posStore[Store[Store.size()-1]];
    
                posStore.erase(Store[Store.size()-1]);
                Store.pop_back();
                return true;
                
            }
            else //if not present
            {
                return false;
    
            }
            
        }
        
        int getRandom() {
    
            return Store[rand()%Store.size()];
            
        }
    };
    
    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */