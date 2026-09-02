class Solution {
public:
int n;
    int solve(int l, int r, vector<int>& nums){
        if(l > r)   return 0; // all turns r done

        int left = nums[l] - solve(l+1, r, nums);
        int right = nums[r] - solve(l, r-1, nums);

        return max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
       n = nums.size();
       return solve(0, n-1, nums) >= 0;
    }
};