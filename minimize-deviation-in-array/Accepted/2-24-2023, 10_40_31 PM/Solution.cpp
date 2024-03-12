// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq; 
        int m = 2e9, ans = 2e9;
        for(int i=0;i<nums.size();i++){
            int tmp = (nums[i] * ((nums[i] % 2 != 0) + 1));
            pq.push(tmp);
            m = min(m, tmp);
        }
        while(!pq.empty()){
            int top = pq.top(); pq.pop();
            ans = min(ans, top - m);
            if(top % 2) break;
            m = min(m, top / 2);
            pq.push(top / 2);
        }
        return ans;
    }
};