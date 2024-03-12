// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    string makeGood(string s) {
        int flag;
        do{
            flag = 0;
            for(int i = 0; i < s.size() - 1; i++){
                if(tolower(s[i]) == tolower(s[i+1]) && (islower(s[i]) ^ islower(s[i + 1]))){
                    s.erase(s.begin() + i, s.begin() + i + 2);
                    if(s.size() == 0) break;
                    cout << s << endl;
                    i--;
                    flag = 1;
                }
            }
        }while(flag);
        return s;
    }
};