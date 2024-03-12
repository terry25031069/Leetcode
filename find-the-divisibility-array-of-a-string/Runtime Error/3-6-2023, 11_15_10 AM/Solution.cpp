// https://leetcode.com/problems/find-the-divisibility-array-of-a-string

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        int tmp = 0;
        for(auto c: word){
            tmp = tmp * 10 + c - '0';
            tmp %= m;
            ans.push_back(!tmp);
        }
        return ans;
    }
};