class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = n;
        for (int i=0; i<n; i++) {
            int curL = intervals[i][0];
            int curR = intervals[i][1];
            for (int j = 0; j<n; j++) {
                if(i==j)    continue;
                int x = intervals[j][0];
                int y = intervals[j][1];
                if(x <= curL && y >= curR){
                    ans--;
                    break;
                }  
            }
        }
        return ans;
    }
};