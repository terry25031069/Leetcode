// https://leetcode.com/problems/strong-password-checker-ii

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8) return false;
        string sp = "!@#$%^&*()-+";
        int l, u, d, s;
        l = u = d = s = 0;
        for(char ch: password){
            if(islower(ch)) l++;
            else if(isupper(ch)) u++;
            else if(isdigit(ch)) d++;
            else if(sp.find(ch) != string::npos) s++;
        }
        if(!(l && u && d && s)) return false;
        return true;
    }
};