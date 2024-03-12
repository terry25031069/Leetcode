// https://leetcode.com/problems/check-distances-between-same-letters

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for(auto &i: distance) i++;
        map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(!m[s[i]]) m[s[i]] = i + 1;
            else{
                cout << i << ' ' << m[s[i]] << ' ' << distance[s[i]-'a'] << endl;
                if(i + 1 - m[s[i]] != distance[s[i] - 'a']) return false;
            }
        }
        return true;
    }
};