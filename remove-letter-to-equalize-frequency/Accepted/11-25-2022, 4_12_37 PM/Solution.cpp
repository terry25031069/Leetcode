// https://leetcode.com/problems/remove-letter-to-equalize-frequency

class Solution {
public:
    bool check(string word){
        int a[26] = {};
        for(auto i: word){
            a[i - 'a']++;
        }
        vector<int>aa;
        for(int i = 0; i < 26; i++)if(a[i])aa.push_back(a[i]);
        sort(aa.begin(), aa.end());
        map<int, int>ans;
        for(auto i: aa) ans[i]++;
        return ans.size() == 1;
    }
    bool equalFrequency(string word) {
        bool ans = 0;
        for(int i = 0; i < word.size(); i++){
            string tmp = word.substr(0, i) + word.substr(i + 1, word.size() - i);
            ans |= check(tmp);
        }
        return ans;
    }
};