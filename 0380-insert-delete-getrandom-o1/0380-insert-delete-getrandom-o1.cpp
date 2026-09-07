class RandomizedSet {
public:
vector<int> store;
unordered_map<int, int> mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.count(val))   return false;

        int idx = store.size();
        store.push_back(val);
        mp[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        if(!(mp.count(val)))    return false;

        int idx = mp[val]; // index of val
        int last = store.back(); // last ele of store

        store[idx] = last;
        mp[last] = idx;
        //move last element to 'idx' position

        store.pop_back(); // remove last element position
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int size = store.size();
        return store[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */