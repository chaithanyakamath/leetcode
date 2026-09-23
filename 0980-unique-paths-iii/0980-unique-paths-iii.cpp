class Solution {
public:
int n, m, valid = 0, ans = 0;

    void solve(int i, int j, vector<vector<int>>& grid, int valid){
        if(i<0 || i>=n || j<0 || j>= m) return;

        if(grid[i][j] == 2 && valid == 0){
            ans++;
            return;
        }
        if(grid[i][j] == 0 || grid[i][j] == 1){
            int org = grid[i][j];
            grid[i][j] = -1;
            valid--;
            solve(i+1, j, grid, valid);
            solve(i-1, j, grid, valid);
            solve(i, j+1, grid, valid);
            solve(i, j-1, grid, valid);
            grid[i][j] = org;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        pair<int, int> loc = {0,0};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0 || grid[i][j] == 1)  valid++;
                if(grid[i][j] == 1){
                    loc.first = i;
                    loc.second = j;
                } 
            }
        }
        solve(loc.first, loc.second, grid, valid);
        return ans;
    }
};