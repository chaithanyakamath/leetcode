class Solution {
public:
    void bfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
        queue<int> qu;
        qu.push(node);
        vis[node] = true;

        while(!qu.empty()){
            int cur = qu.front();
            qu.pop();

            for(int neigh=0; neigh<adj[cur].size(); neigh++){
                if(adj[cur][neigh] == 1 && !vis[neigh]){ 
                    vis[neigh] = true;
                    qu.push(neigh);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int provinces = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i, vis, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};