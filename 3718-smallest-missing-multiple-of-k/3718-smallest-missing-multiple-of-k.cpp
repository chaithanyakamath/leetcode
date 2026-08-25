class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=1; i<=101; i++){
            if(find(nums.begin(), nums.end(), k*i) == nums.end()) return k*i;
        }
        return -1;
    }
};