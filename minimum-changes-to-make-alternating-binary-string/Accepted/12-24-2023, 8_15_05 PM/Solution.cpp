// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans += s[i] != ('0' + (i & 1));
        }
        return 2 * ans <= s.size() ? ans : s.size() - ans;
    }
};