class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int chk = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == target)   chk++;
                int len = j-i+1;

                if(chk > len/2)     count++;
            }
        }
        return count;
    }
};