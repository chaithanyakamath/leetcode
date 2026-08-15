class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool noZero = false;

        for(int x : nums){
            ans ^= x;
            if(ans != 0)  noZero = true;
        }
        if(ans != 0)    return n;
        if(noZero) return n-1;
        return 0;
    }
};