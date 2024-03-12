// https://leetcode.com/problems/count-the-number-of-square-free-subsets

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        long long cnt = 0, ans = 1, bas = 2, n = 1e9 + 7;
        for(auto i: nums){
            if(i % 4 == 0 || i % 9 == 0 || i == 25) continue;
            cout << i << ' ';
            cnt++;
        }
        cout << ans << endl;
        while(cnt){
            if(cnt & 1) ans = ans * bas % n;
            cnt >>= 1;
            bas = bas * bas % n;
        }
        return ans - 1;
    }
};