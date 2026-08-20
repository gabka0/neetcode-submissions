class MinStack {
private:
stack<int> stck;
stack<int> minStck;
public:
    MinStack() {
    }
    
    void push(int val) {
        stck.push(val);
        if(minStck.empty() || val<minStck.top() ) minStck.push(val);
        else minStck.push(minStck.top());
    }
    
    void pop() {
        minStck.pop();
        stck.pop();
        
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return minStck.top();
        
    }
};
