class Solution {
public:
int n, m;
    // void dfs(int i, int j, vector<vector<char>>& grid){
    //     if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')  return ;
    //     grid[i][j] = '$';

    //     dfs(i+1,j, grid);
    //     dfs(i-1,j, grid);
    //     dfs(i,j+1, grid);
    //     dfs(i,j-1, grid);
    // }
    vector<vector<int>> directions{{1,0}, {0,1}, {-1,0}, {0,-1}};
    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int, int>> qu;
        qu.push({i,j});
        grid[i][j] = '$';

        while(!qu.empty()){
            auto cur = qu.front();
            qu.pop();

            for(auto dir : directions){
                int _i = cur.first + dir[0];
                int _j = cur.second + dir[1];

                if(_i<0 || _i>=n || _j<0 || _j>=m || grid[_i][_j] != '1') continue;
                else{ 
                    qu.push({_i,_j});
                    grid[_i][_j] = '$';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){   
                    bfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};