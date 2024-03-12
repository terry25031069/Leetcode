// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(chars.back() + 1); 
        int ans = 0, cnt = 1, idx = 0; 
        char tmp = chars[0];
        for(int i = 1; i < chars.size(); i++){
            if(tmp == chars[i]) cnt++;
            else{
                idx++, ans++;
                if(cnt > 1){
                    string s = to_string(cnt);
                    ans += s.size();
                    for(int j = 0; j < s.size(); j++) chars[idx++] = s[j];
                }
                tmp = chars[i], cnt = 1;
            }
        }
        return ans;
    }
};