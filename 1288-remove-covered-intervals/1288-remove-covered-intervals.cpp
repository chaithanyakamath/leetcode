class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // int ans = 0;
        // for (int i=0; i<n; i++) {
        //     int curL = intervals[i][0];
        //     int curR = intervals[i][1];
        //     for (int j = 0; j<n; j++) {
        //         if(i==j)    continue;
        //         int x = intervals[j][0];
        //         int y = intervals[j][1];
        //         if(x <= curL && y >= curR){
        //             ans--;
        //             break;
        //         }  
        //     }
        // }

        sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])    return a[1] > b[1]; // same leftNum => sort by greater rightNum
            return a[0]<b[0]; // sorting ascending order of leftNum
        }); // custom sort - uses custom comparator

        int ans = 0;
        int mRight = 0;
        for(auto &curr : intervals){
            if(curr[1] > mRight){
                ans++;
                mRight = curr[1];
            }
        }
        return ans;
    }
};