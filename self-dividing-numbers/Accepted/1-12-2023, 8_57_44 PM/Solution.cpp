// https://leetcode.com/problems/self-dividing-numbers

class Solution {
public:
    bool chk(int n){
        for(char c: to_string(n)){
            if(c == '0' || n % (c - '0')) return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left; i <= right; i++){
            if(chk(i))ans.push_back(i);
        }
        return ans;
    }
};