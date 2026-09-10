class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int l = 0, r = n-1;
        int count = 0;
        sort(people.begin(), people.end());

        while(l <= r){
            if(people[l] + people[r] <= limit)  l++;
            r--;
            count++;
        }
        return count;
    }
};