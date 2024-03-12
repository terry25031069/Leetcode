// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int cur = 0, n = chars.size();
        for(int i = 0, j = 0; i < n; i = j){
            while(j < n && chars[j] == chars[i]) j++;
            chars[cur++] = chars[i];
            if(j - i == 1) continue;
            for(char c: to_string(j - i)) chars[cur++] = c;
        }        
        return cur;
    }
};