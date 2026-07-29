class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int score = 0, ans = 0;
        sort(tokens.begin(), tokens.end());
        int r = n-1, l = 0;
        while(l <= r){
            if(power >= tokens[l]){
                score++;
                ans = max(ans, score);
                power -= tokens[l];
                l++;
            }
            else if(score >= 1){
                score--;
                power += tokens[r];
                r--;
            }
            else break;
        }
        return ans;
    }
};