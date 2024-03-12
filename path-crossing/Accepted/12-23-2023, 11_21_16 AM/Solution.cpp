// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string path) {
        using pii = pair<int, int>;
        map<pii, bool> m;
        pii a = {0, 0}; m[a] = 1;
        for(auto ch: path){
            if(ch == 'N') a.first++;
            else if(ch == 'S') a.first--;
            else if(ch == 'W') a.second--;
            else a.second++;
            if(m[a]) return true;
            else m[a] = 1;
        }
        return false;
    }
};