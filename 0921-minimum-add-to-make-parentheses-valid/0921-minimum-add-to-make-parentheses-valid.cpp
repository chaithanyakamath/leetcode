class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for(char c : s){
            if(c == '(')    open++; // extra close parantheses required
            else if(c == ')' && open > 0)   open--; //  to balance out
            else close++; // extra open parantheses required
        }
        return open + close; // total min add
    }
};