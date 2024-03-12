// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int tmp = (1 << (s[0] - 'a')), cur0 = 0, cur1 = 1;
        int ans = 0;
        while(cur1 - s.size()){
            if((tmp ^ (1 << (s[cur1] - 'a'))) > tmp){
                tmp ^= (1 << (s[cur1] - 'a'));
                if(cur1 - s.size()) cur1++;
            }
            else tmp ^= (1 << (s[cur0] - 'a')), cur0++;
            ans = max(ans, cur1 - cur0);
        }
        return ans;
    }
};