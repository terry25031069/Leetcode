// https://leetcode.com/problems/apply-operations-to-make-string-empty

class Solution {
public:
    int letter[26] = {};
    string lastNonEmptyString(string s) {
        for(char c: s) letter[c - 'a']++;
        int ma = *max_element(&letter[0], &letter[26]);
        vector<char> v;
        for(int i = 0; i < 26; i++){
            if(letter[i] == ma) v.push_back(i + 'a');
        } 
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--){
            auto it = find(v.begin(), v.end(), s[i]);
            if(it != v.end()){
                ans += s[i];
                v.erase(it);
            }
            if(!v.size()) break;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};