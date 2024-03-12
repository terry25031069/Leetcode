// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(auto i: s){
            if(isalpha(i)){
                ss.push_back(tolower(i));
            }
        }
        cout << ss << endl;
        string s2 = ss;
        reverse(s2.begin(), s2.end());
        return s2 == ss;
    }
};