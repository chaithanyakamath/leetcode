class Solution {
public:
int n;
vector<vector<pair<int, int>>> dp;
    pair<int, int> solve(vector<int>& nums, int i, int prev){ // length, count
        if(i == n)  return {0, 1};

        if(dp[i][prev+1].first != -1) return dp[i][prev+1];
        pair<int, int> take = {INT_MIN, 0};
        if(prev == -1 || nums[i] > nums[prev]){   
            take =  solve(nums, i+1, i);
            take.first++;
        }
        pair<int, int> skip = solve(nums, i+1, prev);

        if(take.first > skip.first) return dp[i][prev+1] = take;
        else if(take.first < skip.first) return dp[i][prev+1] = skip;
        else return dp[i][prev+1] = {take.first, take.second + skip.second};
    }
    int findNumberOfLIS(vector<int>& nums) {
       n = nums.size();
       dp.assign(n, vector<pair<int,int>>(n+1, {-1, -1}));
       return solve(nums, 0, -1).second; 
    }
};