class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        for(int i=0; i<s.size();i++){
            if(s[i]=='('){
                left.push(i);
            }
            if(s[i]=='*'){
                star.push(i);
            }
            if(s[i]==')'){
                if(!left.empty()){
                    left.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(left.size()>star.size()){
            return false;
        }
        while(left.size()){
            if(left.top()>=star.top()){
                return false;
            }
            left.pop();
            star.pop();
        }
        
        return true;
        
    }
};
