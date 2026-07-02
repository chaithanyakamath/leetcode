class Solution {
public:
    bool perform(char exp, vector<char>& store){
        if(exp == '&'){
            bool compare = true;
            for(char c : store)     compare = compare && (c == 't');
            return compare;
        }
        else if(exp == '|'){
            bool compare = false;
            for(char c : store)     compare = compare || (c == 't');
            return compare;
        }
        return store[0] == 'f';
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();

        for(int i=0; i<n; i++){
            if(expression[i] == ',')    continue;
            else if(expression[i] == ')'){
                vector<char> store;
                while(st.top() != '('){
                    store.push_back(st.top());
                    st.pop();
                }
                st.pop(); // removing '('
                char exp = st.top();
                st.pop(); // removing exp
                bool ans = perform(exp, store);
                st.push(ans ? 't' : 'f');
            }
            else    st.push(expression[i]);
        }
        return st.top() == 't';
    }
};