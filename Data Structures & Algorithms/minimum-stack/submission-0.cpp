class MinStack {
public:

    stack<int> st;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int mini = minStack.empty() ? val : minStack.top();

        int minVal = min(val,mini);

        minStack.push(minVal);

    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
