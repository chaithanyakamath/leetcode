class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mcur=0;

        for(int i=0; i<n; i++){
            if(i>mcur) return false;
 
            mcur = max(mcur, nums[i]+i);
        }
        return true;
    }
};