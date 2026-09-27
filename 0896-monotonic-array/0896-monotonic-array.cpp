class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool isInc = false;
        bool isDec = false;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1])    continue;
            if(nums[i] < nums[i-1]) isDec = true;
            if(nums[i] > nums[i-1]) isInc = true;

            if(isInc && isDec)  return false; // can't be both at same time
        }
        return true;
    }
};