// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends

#define F first
#define S second

class Solution {
public:
    int minimumLength(string s) {
        s += 'd';
        using pci = pair<char, int>;
        vector<pci> v;
        char cur = s[0], cnt = 0;
        for(char c: s){
            if(cur == c) cnt++;
            else{
                v.push_back({cur, cnt});
                cur = c, cnt = 1;
            }
        }
        int l = 0, r = v.size() - 1, ans = s.size() - 1;
        while(l < r){
            // cout << v[l].F << ' ' << v[r].F << endl;
            // cout << v[l].S << ' ' << v[r].S << endl;
            if(v[l].F == v[r].F) ans -= (v[l].S + v[r].S), l++, r--;
            else break;
        }
        if(l == r){
            if(v[l].S > 1) return 0;
            return 1;
        }
        return ans;
    }
};