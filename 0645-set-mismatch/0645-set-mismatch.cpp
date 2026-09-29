class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> store(n+1,0);
        store[0] = 1;
        for(int n : nums){
            store[n]++;
        }

        int missing = -1, duplicate = -1;
        for(int i=1; i<=n; i++){
            if(store[i] == 0)  missing = i;
            if(store[i] > 1)   duplicate = i;
        }
        return {duplicate, missing};
    }
};