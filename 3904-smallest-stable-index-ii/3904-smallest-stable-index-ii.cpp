class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> storeMin(n);
        storeMin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            storeMin[i] = min(nums[i], storeMin[i+1]);
        }

        int maxVal = 0;
        for(int i=0; i<n; i++){
            maxVal = max(maxVal, nums[i]);
            if(maxVal - storeMin[i] <= k)   return i;
        }
        return -1;
    }
};