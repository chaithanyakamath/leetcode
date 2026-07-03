class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited = grid; //copy to keep checking n update
        queue<pair<int, int>> q;
        int countFresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 2)  q.push({i,j}); //push rotten into queue
                if(visited[i][j] == 1)  countFresh++; // get count of current fresh one's
            }
        }
        if(countFresh == 0) return 0;
        if(q.empty())   return -1;

        int min = -1;
        vector<pair<int,int>> adjacent = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx, dy] : adjacent){
                    int i = x + dx;
                    int j = y + dy;
                    if(i>=0 && i<n && j>=0 && j<m && visited[i][j] == 1){
                        visited[i][j] = 2;
                        countFresh--;
                        q.push({i,j});
                    }
                }
            }
            min++; // its lvl wise, in each lvl(time) all these shld be done
        }
        if(countFresh == 0) return min;
        return -1;
    }
};