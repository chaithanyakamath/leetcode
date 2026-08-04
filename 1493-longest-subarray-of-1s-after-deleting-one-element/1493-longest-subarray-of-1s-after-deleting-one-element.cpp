class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int zcount = 0;
        int ans = 0;
        for(int j=0; j<n; j++){
            if(nums[j] == 0)  zcount++;

            while(zcount > 1){
                if(nums[i] == 0)    zcount--;
                i++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};