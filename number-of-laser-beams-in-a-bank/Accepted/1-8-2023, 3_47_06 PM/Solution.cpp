// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int check(string s){
        int cnt = 0;
        for(auto i: s) cnt += (i != '0');
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> b;
        for(auto s: bank){
            if(check(s))b.push_back(check(s));
        }
        if(b.size() < 2) return 0;
        int ans = 0;
        for(int i = 0; i < b.size() - 1; i++){
            ans += b[i] * b[i+1];
        }
        return ans;
    }
};