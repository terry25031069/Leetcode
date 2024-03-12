// https://leetcode.com/problems/remove-letter-to-equalize-frequency

class Solution {
public:
    bool equalFrequency(string word) {
        int a[26] = {};
        for(auto i: word){
            a[i - 'a']++;
        }
        vector<int>aa;
        for(int i = 0; i < 26; i++)if(a[i])aa.push_back(a[i]);
        sort(aa.begin(), aa.end());
        int flag = 0, i = 0;
        for(int i = 0; i < aa.size(); i++){
            if(aa[i] == 2) flag++;
            else if(aa[i] > 2) return false;
        }
        return (flag < 2);
    }
};