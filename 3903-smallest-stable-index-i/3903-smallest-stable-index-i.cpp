class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> store(n);
        store[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            store[i] = min(nums[i], store[i+1]);
        }

        int maxVal = nums[0], ans = 0;
        for(int i=0; i<n; i++){
            maxVal = max(maxVal, nums[i]);
            if(store[i] != -1 && maxVal - store[i] <= k) return i;
        }
        return -1;
    }
};