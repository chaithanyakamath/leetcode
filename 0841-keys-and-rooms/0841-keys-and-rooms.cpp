class Solution {
public:
    // void bfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
    //     queue<int> qu;
    //     qu.push(node);
    //     vis[node] = true;

    //     while(!qu.empty()){
    //         int cur = qu.front();
    //         qu.pop();

    //         for(auto neigh : adj[cur]){
    //             if(!vis[neigh]){
    //                 qu.push(neigh);
    //                 vis[neigh] = true;
    //             }
    //         }
    //     }
    // }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;
        for(auto neigh : adj[node]){
            if(!vis[neigh]) dfs(neigh, adj, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        dfs(0, rooms, vis);
        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};