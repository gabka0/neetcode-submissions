class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(char& x: s){
            if(isalnum(x)) ans+=tolower(x);
        }
        int k = 0;
        int l = ans.size()-1;
        while(k<l){
            if(ans[k]!=ans[l]) return false;
            k++;
            l--;
        }
        return true;
        
    }
};
