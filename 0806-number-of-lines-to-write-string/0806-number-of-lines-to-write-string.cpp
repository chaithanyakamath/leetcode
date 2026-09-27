class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = widths.size();
        int m = s.size();
        int a = 0, b = 1;
        vector<int> ans;
        for(char c : s){
            int chk = c - 'a';
            a += widths[chk];
            if(a > 100){ 
                b++;
                a = widths[chk];
            }
        }
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
};