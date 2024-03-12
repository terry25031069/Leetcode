// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<vector<int>> cnt(words.size(), vector<int>(26, 0));
        for(int i = 0; i < words.size(); i++){
            for(auto c: words[i]){
                cnt[i][c - 'a']++;
            }
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < words.size(); j++){
                cnt[0][i] = min(cnt[0][i], cnt[j][i]);
            }
            for(int ccnt = 0; ccnt < cnt[0][i]; ccnt++){
                //cout << i << ' ' << cnt[0][i] << endl;
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};