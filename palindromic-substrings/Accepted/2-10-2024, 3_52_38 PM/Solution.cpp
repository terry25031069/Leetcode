// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; i - j >= 0 && i + j < n; j++){
                //cout << i-j << ' ' << i+j << endl;
                if(s[i-j] == s[i+j]) ans++;
                else break;
            }
            if(i + 1 < n && s[i] == s[i+1]){
                for(int j = 0; i - j >= 0 && i + 1 + j < n; j++){
                    //cout << i-j << ' ' << i+j+1 << endl;
                    if(s[i-j] == s[i+j + 1]) ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};