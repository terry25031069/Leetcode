// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i

#define F first
#define S second

class Solution {
public:
    int minimumPushes(string word) {
        using pic = pair<int, char>;
        map<char, int> cnt;
        vector<pic> v;
        
        for(char ch: word) cnt[ch]++;
        for(auto [key, val]: cnt) v.push_back({val, key});
        sort(v.rbegin(), v.rend());

        int ans = 0, enc = 0;
        for(pic sv: v){
            //cout << sv.F << ' ' << sv.S << endl;
            ans += (enc / 8 + 1) * sv.F;
            enc++;
        }
        return ans;
    }
};