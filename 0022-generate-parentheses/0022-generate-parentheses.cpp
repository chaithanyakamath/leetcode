class Solution {
public:
string store = "";
vector<string> ans;
    bool validate(string s){
        int check = 0;
        for(char c : s){
            if(c == '(')    check++;
            else check--;
            if(check < 0)   return false;
        }
        return check==0;
    }
    void solve(int i, int len, const string& store){
        if(i >= 2*len){  
            bool valid = validate(store);
            if(valid)   ans.push_back(store);  
            return;
        }
        solve(i+1, len, store + ')');
        solve(i+1, len, store + '(');
    }
    vector<string> generateParenthesis(int n) {
        solve(0, n, "");
        return ans;
    }
};