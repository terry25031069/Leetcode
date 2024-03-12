// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int cnts[10] = {}, cntg[10] = {};
        for(auto i: secret) cnts[i - '0']++;
        for(int i = 0; i < guess.size(); i++){
            cntg[guess[i] - '0']++;
            if(guess[i] == secret[i]) A++;
        }
        for(int i = 0; i < 10; i++) B += min(cnts[i], cntg[i]);
        string ans = to_string(A) + "A" + to_string(B-A) + "B";
        return ans;
    }
};