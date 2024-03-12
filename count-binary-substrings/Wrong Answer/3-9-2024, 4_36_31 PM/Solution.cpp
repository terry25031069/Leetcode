// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        s += !(s.back() - '0') + '0';
        vector<int> v;
        char t = s[0], cnt = 0;
        for(char ch: s){
            if(t == ch) cnt++;
            else{
                v.push_back(cnt);
                cnt = 1, t = ch;
            }
        }
        int ans = 0;
        for(int i = 0; i < v.size() - 1; i++){
            ans += min(v[i], v[i+1]);
        }
        return ans;
    }
};