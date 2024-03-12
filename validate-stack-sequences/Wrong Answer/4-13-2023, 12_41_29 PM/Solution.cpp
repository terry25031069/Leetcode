// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> a, b; int idx = 0;
        for(int i = pushed.size()-1; i >=0; i--) a.push(pushed[i]);
        while(!a.empty()){
            b.push(a.top()); a.pop();
            if(b.top() == popped[idx]) b.pop(), idx++;
        }
        while(!b.empty() && b.top() == popped[idx]){
            idx++, b.pop();
        }
        return b.empty();
    }
};