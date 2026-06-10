class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> stck;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int i = stck.top();
                stck.pop();
                int j = stck.top();
                stck.pop();
                stck.push(j+i);
            }
            else if(tokens[i]=="-"){
                int i = stck.top();
                stck.pop();
                int j = stck.top();
                stck.pop();
                stck.push(j-i);
            }
            else if(tokens[i]=="*"){
                int i = stck.top();
                stck.pop();
                int j = stck.top();
                stck.pop();
                stck.push(j*i);
            }
            else if(tokens[i]=="/"){
                int i = stck.top();
                stck.pop();
                int j = stck.top();
                stck.pop();
                stck.push(j/i);
            }
            else{
                stck.push(stoi(tokens[i]));
            }
        }
        return stck.top();
        
    }
};
