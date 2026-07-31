class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int prev = 0;
        int ans = 0;
        for(int curr = 1; curr<n; curr++){
            if(colors[curr] != colors[prev])    prev = curr;
            else{
                ans += min(neededTime[prev], neededTime[curr]);
                if(neededTime[curr] > neededTime[prev]) prev = curr;
            }
        }
        return ans;
    }
};