class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
    //    int n = grid.size();
    //    int count = 0;

    //     for(int r=0; r<n; r++){ // a row
    //         for(int c=0; c<n; c++){ // checked with all columns
    //             bool same = true;
    //             for(int i=0; i<n; i++){
    //                 if(grid[r][i] != grid[i][c])    same = false;
    //             }
    //             if(same)    count++; // count of how many colums were equal to particular row
    //         }
    //     }
    //     return count;


        int n = grid.size();
        map<vector<int>, int> mp;
        int ans = 0;

        for(auto &row : grid)   mp[row]++;

        for(int c=0; c<n; c++){
            vector<int> col;
            for(int i=0; i<n; i++){
                col.push_back(grid[i][c]);
            }
            ans += mp[col];
        }
        return ans;
    }
};