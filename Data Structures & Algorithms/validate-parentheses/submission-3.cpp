class Solution {
public:
    bool isValid(string s) {
        stack<char> fck;
        unordered_map<char,char> fck2 = {{')', '('}, {'}', '{'}, {']', '['}};
    
        for(char i: s){
            
            if(i=='(' || i=='{' || i=='['){
                fck.push(i);
            }
            else{
                if (fck.empty() || fck.top() != fck2[i]) return false;
                fck.pop();
            }
        }
        return fck.empty();;
    }
};
