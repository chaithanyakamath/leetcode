class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        if(n==0)    return 0;

        int maxC = 1;
        for(auto it : st){
            if(!st.count(it-1)){ // if no sequence currently
                int cur = it; // consider that element as begin
                int count = 1; // start the count from begining
            
                if(st.count(cur)){
                    while(st.count(cur+1)){ // keep iterating until sequence is there
                        cur++;
                        count++;
                    }
                }
                maxC = max(maxC, count);
            }
        }
        return maxC;
    }
};
// 2 main things --> 1. how to maintain the length if sequence is there(count)    2.wt to do if sequence breaks(start from begining)
// for each element keep checking for sequence begining from that particular number n store the max len
                    