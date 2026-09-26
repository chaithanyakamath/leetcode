class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        int m = knowledge.size();
        unordered_map<string, string> mp;
        string ans = "";
        bool see = true;
        for(int i=0; i<m; i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        int l = 0;
        for(int r=0; r<n; r++){
            if(s[r] == '(') see = false;
            if(see) ans += s[r];

            if(s[r] == ')'){
                see = true;
                l = r;
                while(s[l] != '('){
                    l--;
                }
                string check = s.substr(l+1, r-l-1);
                string add = (mp.count(check)) ? mp[check] : "?";
                ans += add;
            }
        }
        return ans;
    }
};