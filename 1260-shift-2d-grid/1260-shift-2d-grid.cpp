class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        while(k>0){
            int last = grid[n-1][m-1];
            for(int i=n-1; i>=0; i--){
                for(int j=m-1; j>=0; j--){
                    if(i == n-1 && j == m-1)    continue;

                    if(i != n-1 && j == m-1)   grid[i+1][0] = grid[i][m-1];
                    else    grid[i][j+1] = grid[i][j];
                }
            }
            grid[0][0] = last;
            k--;
        }
        return grid;
    }
};