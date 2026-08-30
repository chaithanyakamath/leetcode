class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return n;

        int mini = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        auto miniLoc = find(nums.begin(), nums.end(), mini) - nums.begin();
        auto maxxLoc = find(nums.begin(), nums.end(), maxx) - nums.begin();

        int left = min(miniLoc, maxxLoc);
        int right = max(miniLoc, maxxLoc);

        int front = right+1;
        int back = n-left;
        int mixed = (left+1) + (n-right);

        return min({front, back, mixed});
    }
};