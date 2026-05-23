class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans;
        stack<int> tckns;
        for(int i = 0; i<tokens.size(); i++){
            int x, y;
            if(tokens[i]=="+"){
                x = tckns.top();
                tckns.pop();
                y = tckns.top();
                tckns.pop();
                tckns.push(x+y);
            }
            else if(tokens[i]=="-"){
                x = tckns.top();
                tckns.pop();
                y = tckns.top();
                tckns.pop();
                tckns.push(y-x);
            }
            else if(tokens[i]=="*"){
                x = tckns.top();
                tckns.pop();
                y = tckns.top();
                tckns.pop();
                tckns.push(x*y);
            }
            else if(tokens[i]=="/"){
                x = tckns.top();
                tckns.pop();
                y = tckns.top();
                tckns.pop();
                tckns.push(y/x);
            }
            else{
                tckns.push(stoi(tokens[i]));;
            }
        }
        return tckns.top();
    }
};
