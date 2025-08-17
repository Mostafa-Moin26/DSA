// Problem link --->
https://leetcode.com/problems/min-stack/description/


// Solution ---->
// using stack of pair
class MinStack {
public:
    
    stack<pair<int, int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// using normal stack
class MinStack {
public:
    stack<long long> st; 
    long long mini;

    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2LL * mini - x;
        }
    }
    
    int top() {
        if (st.empty()) return -1;

        long long x = st.top();
        if (x < mini) {
            return (int)mini;  
        }
        return (int)x;
    }
    
    int getMin() {
        return (int)mini;
    }
};