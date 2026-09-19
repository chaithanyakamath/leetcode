class Solution {
public:
    bool topologicalSort(vector<vector<int>>& adj, int numCourses, vector<int>& inDegree){
        queue<int> qu;
        
        for(int i=0; i<inDegree.size(); i++)    if(inDegree[i] == 0)    qu.push(i);

        while(!qu.empty()){
            int cur = qu.front();
            qu.pop();
            numCourses--;
            for(auto neigh : adj[cur]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0)    qu.push(neigh);
            }
        }
        return numCourses==0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto course : prerequisites){
            int a = course[0];
            int b = course[1];

            adj[b].push_back(a); // b-->a
            inDegree[a]++;
        }
        return topologicalSort(adj, numCourses, inDegree);
    }
};