class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int n : stones) pq.push(n);

        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a != b)  pq.push(abs(a-b));
            
        }
        return pq.empty() ? 0 : pq.top();
    }
};