class Solution {
public:
    // void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
    //     vis[node] = true;
    //     for(int neigh : adj[node]){
    //         if(!vis[neigh])   dfs(neigh, adj, vis);
    //     }
    // }
    void bfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        queue<int> qu;
        qu.push(node);
        vis[node] = true;

        while(!qu.empty()){
            int cur = qu.front();
            qu.pop();
            for(int neigh : adj[cur]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    // bfs(neigh, adj, vis);
                    qu.push(neigh);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0]; // node 1
            int v = edge[1]; // node 2

            adj[u].push_back(v);
            adj[v].push_back(u);
            //connection btwn node 1 n 2
        }
        vector<bool> vis(n, false);
        bfs(source, adj, vis);
        return vis[destination];
    }
};