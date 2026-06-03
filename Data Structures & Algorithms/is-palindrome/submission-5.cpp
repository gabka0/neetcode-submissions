class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<=r){
            while(!isalnum(s[l]) && l<s.size())l++;
            while(!isalnum(s[r]) && r>=0)r--;
            if(isalnum(s[l]) && isalnum(s[r])){
                if(tolower(s[l])!=tolower(s[r])) return false;
                l++;
                r--;
            }
        }
        return true;
    }
};
