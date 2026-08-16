class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u'||
            c=='A' || c=='E'|| c=='I'|| c=='O'|| c=='U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        int countl = 0, countr = 0;
        while(l<r){
            if(isVowel(s[l]))  countl++;
            if(isVowel(s[r]))  countr++;
            l++; r--;
        }
        return (countl == countr);
    }
};