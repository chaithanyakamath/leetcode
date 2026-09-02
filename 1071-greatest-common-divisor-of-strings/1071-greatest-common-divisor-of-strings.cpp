class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();

        int a = min(l1, l2);
        for(int len=a; len>0; len--){
            if(l1%len == 0 && l2%len ==0){
                string part = str1.substr(0,len);
                string s1 = "", s2 = "";
                for(int i=0; i<l1/len; i++) s1 += part;
                for(int i=0; i<l2/len; i++) s2 += part;
                if(s1 == str1 & s2 == str2)    return part;
            }
        }
        return "";
    }
};