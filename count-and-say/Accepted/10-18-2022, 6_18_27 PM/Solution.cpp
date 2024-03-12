// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        string s = to_string(1);
        while(--n){
            s += 'X';
            string result = "";
            char current = s[0]; int cnt = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == current) cnt++;
                else{
                    result += to_string(cnt);
                    result += current;
                    current = s[i];
                    cnt = 1;
                }
            }
            cout << result << endl;
            s = result;
        }
        return s;
    }
};