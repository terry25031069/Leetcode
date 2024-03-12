// https://leetcode.com/problems/sort-characters-by-frequency

map<char, int>m;

bool cmp(pair<char, int> a, pair<char, int> b){
    return a.second > b.second; 
}

class Solution {
public:
    string frequencySort(string s) {
        m.clear();
        for(auto i: s) m[i]++;
        vector<pair<char, int>>ans(m.begin(), m.end());
        sort(ans.begin(), ans.end(), cmp);
        string anss = "";
        for(auto i: ans){
            for(int j = 0; j < i.second; j++) anss += i.first;
        }
        return anss;
    }
};