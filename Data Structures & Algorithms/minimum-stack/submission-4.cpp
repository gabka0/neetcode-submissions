class MinStack {
public:
stack<int> stck;
stack<int> minStack;
    MinStack() {
    }
    
    void push(int val) {
        stck.push(val);
        if(minStack.empty()){
            minStack.push(val);
        } 
        else if(val<minStack.top()){
            minStack.push(val);
        }
        else{
            minStack.push(minStack.top());
        }
        
    }
    
    void pop() {
        stck.pop();
        minStack.pop();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};