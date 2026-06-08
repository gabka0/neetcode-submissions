class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> x = {
            {')', '('}, 
            { '}', '{'},
            {']', '['}};
        stack<char> stck;
        if(s.size()%2==1) return false;
        for(int i=0; i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stck.push(s[i]);
            }
            else{
                if(stck.empty() || stck.top()!=x[s[i]]) return false;
                else stck.pop();
            }
        }
        return stck.empty();
    }
};
