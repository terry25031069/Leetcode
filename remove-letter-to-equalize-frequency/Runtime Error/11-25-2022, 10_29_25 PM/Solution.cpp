// https://leetcode.com/problems/remove-letter-to-equalize-frequency

class Solution{
public:
    static bool cmp(int a, int b){
        if(a == 0) return 0;
        if(b == 0) return 1;
        return a < b;
    }
    bool equalFrequency(string word){
        int a[26] = {};
        for(auto i: word){
            a[i - 'a']++;
        }
        sort(a, a+26, cmp);
        for(int i = 0; i < 26; i++) cout << a[i] << " \n"[i == 25];

        map<int, int>ans;
        for(int i = 0; a[i] && i < 26; i++) ans[a[i]]++;
        if(ans.size() > 2 || (ans.size() == 1 && (*ans.begin()).first != 1 && (*ans.begin()).second != 1)) return false;
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