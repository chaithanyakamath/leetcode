class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<string> st;
        string cur = "";
        for(char c : s){
            if(c == '(' ){    
                st.push(cur);
                cur = "";
            }
            else if ( c == ')'){
                reverse(cur.begin(), cur.end());
                string prev = st.top();
                st.pop();

                cur = prev + cur;
            }
            else    cur += c;
        }
        return cur;
    }
};