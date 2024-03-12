// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i: stones) q.push(i);
        while(q.size() > 1){
            int t0, t1; t0 = q.top(); q.pop(); t1 = q.top(), q.pop();
            if(t0 != t1) q.push(abs(t0-t1));
        }
        return q.top();
    }
};