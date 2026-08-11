class Solution {
public:
    int partitionString(string s) {
        vector<int> store(26, 0);
        int n = s.size();
        int count = 1;

        for(int i=0; i<n; i++){
            if(store[s[i]-'a'] == 1){  
                count++;
                fill(store.begin(), store.end(), 0);
            }
            store[s[i]-'a'] = 1;
        }
        return count;
    }
};