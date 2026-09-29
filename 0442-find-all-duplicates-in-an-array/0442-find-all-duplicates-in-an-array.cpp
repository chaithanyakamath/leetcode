class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int idx = abs(nums[i])-1; // idx where val 'x' will be placed
            if(nums[idx] < 0)   ans.push_back(abs(nums[i]));  // -ve val idicates duplicates
            else nums[idx] = -nums[idx]; // perform operation of making val -ve to identify duplicates
        }
        return ans;
    }
};
// we r using the concept of storing val 'x' in (x-1) location by performing some similar operations amongst all which will help us to identify a 'x' whn it comes for 2nd time