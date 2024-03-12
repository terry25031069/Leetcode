// https://leetcode.com/problems/sort-characters-by-frequency

map<char, int>m;

bool cmp(char a, char b){
    cout << a << ' ' << b << ' ' << m[a] << ' ' << m[b] << endl;
    return m[a] > m[b];
}

class Solution {
public:
    string frequencySort(string s) {
        m.clear();
        for(auto i: s) m[i]++;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};