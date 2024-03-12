// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        string ans = to_string(x);
        ::reverse(ans.begin() + (ans[0] == '-'), ans.end());
        return (stoll(ans) > INT_MAX || stoll(ans) < INT_MIN? 0: stoi(ans));
    }
};