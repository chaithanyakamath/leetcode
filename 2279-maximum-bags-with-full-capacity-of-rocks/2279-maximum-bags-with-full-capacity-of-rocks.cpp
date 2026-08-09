class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int count = 0;
        vector<int> extra;
        for(int i=0; i<n; i++)  extra.push_back(capacity[i] - rocks[i]);

        sort(extra.begin(), extra.end());
        for(int n : extra){
            if(n <= additionalRocks){
                count++;
                additionalRocks -= n;
            }
        }
        return count;
    }
};