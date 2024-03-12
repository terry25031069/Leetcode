// https://leetcode.com/problems/min-stack

class MinStack {
public:
    map<int, int> m;
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        s.push(val);
    }
    
    void pop() {
        int ele = s.top(); s.pop();
        m[ele]--;
        if(!m[ele]) m.erase(ele);
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return (*m.begin()).first;
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