class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        string store = "";
        int n = s.size();

        for(int i=0; i<=n; i++){
            if(i == n || s[i] == '/'){
                if(store == "" || store == "."){}
                else if(store == ".."){
                    if(!st.empty()) st.pop();
                }
                else    st.push(store);
                store = "";
            }
            else{
                store += s[i];
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop(); 
        }
        return (ans == "") ? "/" : ans;
    }
};