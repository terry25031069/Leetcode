// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<int> tmp;
        map<char, int>m; 
        m['a'] = 1, m['e'] = 2, m['i'] = 3, m['o'] = 4, m['u'] = 5;
        for(auto i: word)tmp.emplace_back(m[i]);
        tmp.emplace_back(0);
        int ans = 0, cur = 0, loc = 0;
        for(auto i: tmp){
            if(i == loc + 1) {
                loc++, cur++;
            }else if(i == loc){
                cur++;
            }else{
                if(loc == 5){
                    ans = max(ans, cur);
                }
                cur = loc = (i == 1);
            }
        }
        return ans;
    }
};