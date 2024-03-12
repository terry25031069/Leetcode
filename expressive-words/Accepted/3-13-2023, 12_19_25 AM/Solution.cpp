// https://leetcode.com/problems/expressive-words

#define F first
#define S second

class Solution {
public:
    using pci = pair<char, int>;
    vector<pci> zip(string s){
        vector<pci> ans;
        s += 'S';
        int cnt = 1; char c = s[0];
        for(int i = 1; i < s.size(); i++){
            if(s[i] == c) cnt++;
            else{
                ans.push_back({c, cnt});
                c = s[i], cnt = 1;
            }
        }
        return ans;
    }
    bool chk(vector<pci> a, vector<pci> b){
        //cout << a.size() << ' ' << b.size() << endl;
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++){
            if(a[i].F == b[i].F){
                if(!(a[i].S == b[i].S || (a[i].S > b[i].S && a[i].S > 2))) return false;
            }else return false;
        }
        return true;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        auto sp = zip(s);
        for(auto str: words){
            ans += chk(sp, zip(str));
        }
        return ans;
    }
};