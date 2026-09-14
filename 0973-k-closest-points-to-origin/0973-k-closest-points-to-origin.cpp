class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>> pq;

        for(auto p : points){
            int a = p[0];
            int b = p[1];

            int diff = (a*a) + (b*b);
            pq.push({diff,{a,b}});
            if(pq.size() > k)   pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto num = pq.top();
            pq.pop();

            ans.push_back({num.second.first, num.second.second});
        }
        return ans;
    }
};