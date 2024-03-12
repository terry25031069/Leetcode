// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<127>tmp;
        int cur0 = 0, cur1 = 0;
        int ans = 0;
        while(cur1 - s.size()){
            bitset<127>tmp1, tmp2; 
            tmp1.set(s[cur1]), tmp2.set(s[cur0]);
            if((tmp ^ tmp1).count() > tmp.count()){
                tmp ^= tmp1;
                if(cur1 - s.size()) cur1++;
            }
            else tmp ^= tmp2, cur0++;
            ans = max(ans, cur1 - cur0);
        }
        return ans;
    }
};