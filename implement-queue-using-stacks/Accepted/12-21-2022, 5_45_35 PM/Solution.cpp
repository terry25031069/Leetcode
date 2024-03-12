// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        stack<int> tmp;
        st = tmp;
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> tmp;
        while(st.size() > 1){
            tmp.push(st.top()); st.pop();
        }
        int ans = st.top(); st.pop();
        while(tmp.size() > 0){
            st.push(tmp.top()); tmp.pop();
        }
        return ans;
    }
    
    int peek() {
        stack<int> tmp;
        while(st.size() > 1){
            tmp.push(st.top()); st.pop();
        }
        int ans = st.top(); st.pop(); tmp.push(ans);
        while(tmp.size() > 0){
            st.push(tmp.top()); tmp.pop();
        }
        return ans;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */