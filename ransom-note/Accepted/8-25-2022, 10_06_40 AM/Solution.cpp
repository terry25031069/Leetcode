// https://leetcode.com/problems/ransom-note

class Solution {
public:
    int letter[26] = {};
    bool canConstruct(string ransomNote, string magazine) {
        for(auto i: ransomNote){
            letter[i - 'a']--;
        }
        for(auto i: magazine){
            letter[i - 'a']++;
        }
        int ans = 1;
        for(int i = 0; i < 26; i++){
            if(letter[i] < 0){
                ans = 0;
                break;
            }
        }
        cout << (ans ? "true": "false") << endl;
        return ans;
    }
};