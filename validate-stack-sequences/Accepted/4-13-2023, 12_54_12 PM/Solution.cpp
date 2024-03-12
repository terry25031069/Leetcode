// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> a, b; int idx = 0, aidx = 0;
        while(aidx < pushed.size()){
            b.push(pushed[aidx++]);
            while(!b.empty() && b.top() == popped[idx]) b.pop(), idx++;
        }
        return b.empty();
    }
};