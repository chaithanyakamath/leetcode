class Solution {
public:
int n;
unordered_map<int, string> mp = {{2,"abc"}, {3, "def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"},{9,"wxyz"}};
vector<string> ans;
string store;
    void solve(int i, string digits){
        if(i >= n){
            ans.push_back(store);
            return;
        }

        string cur = mp[digits[i]-'0'];
        for(int j=0; j<cur.size(); j++){
            store += cur[j];
            solve(i+1, digits);
            store.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();

        solve(0, digits);
        return ans;
    }
};