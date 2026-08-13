class SmallestInfiniteSet {
public:
vector<int> store;
    SmallestInfiniteSet() {
        store = vector<int>(1001, 1);
    }
    
    int popSmallest() {
        for(int i=1; i<=1001; i++){
            if(store[i] ==1){
                store[i] = 0;
                return i;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        if(store[num] == 0) store[num]= 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */