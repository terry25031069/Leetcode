// https://leetcode.com/problems/remove-stones-to-minimize-the-total

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> tmp;
        for(int i: piles) tmp.push(i);
        while(k--){
            int top = tmp.top(); tmp.pop();
            tmp.push(top - top / 2);
        }
        int ans = 0;
        while(!tmp.empty()) ans += tmp.top(), tmp.pop();
        return ans;
    }
};