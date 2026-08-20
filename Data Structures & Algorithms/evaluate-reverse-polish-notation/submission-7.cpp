class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        for(int i=0; i<tokens.size();i++){
            if(tokens[i]=="+"){
                int temp1=stck.top();
                stck.pop();
                int temp2=stck.top();
                stck.pop();
                stck.push(temp2+temp1);
            }
            else if(tokens[i]=="-"){
                int temp1=stck.top();
                stck.pop();
                int temp2=stck.top();
                stck.pop();
                stck.push(temp2-temp1);
            }
            else if(tokens[i]=="*"){
                int temp1=stck.top();
                stck.pop();
                int temp2=stck.top();
                stck.pop();
                stck.push(temp2*temp1);
            }
            else if(tokens[i]=="/"){
                int temp1=stck.top();
                stck.pop();
                int temp2=stck.top();
                stck.pop();
                stck.push(temp2/temp1);
            }
            else stck.push(stoi(tokens[i]));
        }
        return stck.top(); 
    }
};
