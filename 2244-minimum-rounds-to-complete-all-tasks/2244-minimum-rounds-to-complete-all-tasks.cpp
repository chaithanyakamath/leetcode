class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        int n = tasks.size();
        for(int n : tasks)  mp[n]++;

        int count = 0;
        for(auto& [task, freq] : mp) {
            if(freq == 1)
                return -1;

            count += (freq + 2) / 3;
        }
        return count;
    }
};