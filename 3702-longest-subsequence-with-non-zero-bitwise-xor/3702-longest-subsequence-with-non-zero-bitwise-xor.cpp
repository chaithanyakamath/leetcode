class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool hasZero = false;

        for(int x : nums){
            ans ^= x;
            if(x != 0)  hasZero = true;
        }
        if(ans != 0)    return n;
        if(hasZero) return n-1;
        return 0;
    }
};