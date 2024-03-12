// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(chars.back() + 1); 
        int ans = -1, cnt = 1; 
        char tmp = char(8);
        for(char c: chars){
            if(c != tmp){
                    ans += 1 + (cnt > 1) * to_string(cnt).size();
                    cout << ans << endl;
                    tmp = c, cnt = 1;
            }else cnt++;
        } 
        return ans;
    }
};