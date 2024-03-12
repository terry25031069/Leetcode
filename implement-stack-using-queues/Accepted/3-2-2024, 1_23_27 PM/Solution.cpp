// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:
    queue<int> q;

    MyStack() {
        while(!q.empty()) q.pop();
    }
    
    void push(int x) {
        int n = q.size(), t = n;
        q.push(x);
        while(t > 0){
            int tt = q.front(); q.pop();
            q.push(tt);
            t--;
        }    
    }
    
    int pop() {
        int t = top();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */