class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int minn = nums[0];
        while(l <= r){
            int mid = l +(r-l)/2;
            if(nums[mid] <= nums[n-1]){ // 2nd half is sorted in asc so check 1st half
                minn = min(minn, nums[mid]);
                r = mid-1;
            }
            else if(nums[0] <= nums[mid]){ // 1st half is in proper sorted in asc order so check 1st half
                minn = min(minn, nums[mid]);
                l = mid + 1;
            }
        }
        return minn;
    }
};