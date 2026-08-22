class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // for(int i=0; i<n-1; i++){
        //     if(nums[i]==nums[i+1]) return true;
        // }
        // return false;

        int n = nums.size();
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n]++;
            if(mp[n] > 1)   return true;
        }
        return false;
    }
};