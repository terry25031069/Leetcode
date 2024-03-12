// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        set<int> s;
        for(auto i: banned) s.insert(i);
        for(int i = 1; i <= n; i++){
            if(s.find(i) == s.end() && maxSum >= i){
                maxSum -= i;
                ans++;
            }else{
                if(maxSum < i) break;
            }
        }
        return ans;
    }
};