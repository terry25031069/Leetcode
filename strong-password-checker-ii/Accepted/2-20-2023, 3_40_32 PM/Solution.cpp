// https://leetcode.com/problems/strong-password-checker-ii

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8) return false;
        string sp = "!@#$%^&*()-+";
        int l, u, d, s;
        l = u = d = s = 0;
        string &ch = password;
        for(int i = 0; i < password.size(); i++){
            if(islower(ch[i])) l++;
            else if(isupper(ch[i])) u++;
            else if(isdigit(ch[i])) d++;
            else if(sp.find(ch[i]) != string::npos) s++;
            if(i > 0 && ch[i] == ch[i-1]) return false;
        }
        if(!(l && u && d && s)) return false;
        return true;
    }
};