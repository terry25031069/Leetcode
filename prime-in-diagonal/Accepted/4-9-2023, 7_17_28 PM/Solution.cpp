// https://leetcode.com/problems/prime-in-diagonal

class Solution {
public:
    bool chk(int n){
        if(n == 1) return false;
        if(n == 2 || n == 3) return true;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> pc;
        for(int i = 0; i < nums.size(); i++){
            pc.push_back(nums[i][i]);
            pc.push_back(nums[i][nums.size()-i-1]);
        }
        int ans = 0;
        for(int i: pc){
            if(chk(i)) ans = max(ans, i);
        }
        return ans;
    }
};