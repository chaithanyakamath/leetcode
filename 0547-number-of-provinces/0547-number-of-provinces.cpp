class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node] = true;
        for(int neighbours=0; neighbours < adj.size(); neighbours++){
            if(adj[node][neighbours] == 1 && !vis[neighbours])  dfs(neighbours, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int provinces = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};