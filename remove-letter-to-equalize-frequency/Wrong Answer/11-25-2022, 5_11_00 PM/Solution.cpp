// https://leetcode.com/problems/remove-letter-to-equalize-frequency

class Solution{
public:
    bool equalFrequency(string word){
        int a[26] = {};
        for(auto i: word){
            a[i - 'a']++;
        }
        vector<int>aa;
        map<int, int>ans;
        for(int i = 0; i < 26; i++)if(a[i])aa.push_back(a[i]);
        for(auto i: aa)ans[i]++;
        if(ans.size() > 2 || (ans.size() == 1 && (*ans.begin()).first != 1)) return false;
        if(ans.size() == 1) return true;
        if((*ans.begin()).first == 1 && (*ans.begin()).second == 1) return true;
        else{
            auto loc = prev(ans.end(), 1);
            (*loc).second--, ans[(*loc).first - 1]++;
            if((*loc).second == 0) ans.erase((*loc).first);
            return ans.size() == 1;
        }
    }
};