class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st;
        int n = s.size();
        int m = part.size();

        for(int i=0; i<n; i++){
            st.push_back(s[i]);
            if(st.size()>=m){
                bool match = true;
                for(int i=0; i<m; i++){
                    if(st[st.size() - m + i] != part[i]){
                        match = false;
                        break;
                    }
                }
                if(match)   st.erase(st.size()-m,m);
            }
        }
        return st;
    }
};