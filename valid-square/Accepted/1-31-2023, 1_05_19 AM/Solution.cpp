// https://leetcode.com/problems/valid-square

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<vector<int>> f; f.resize(4);
        f[0] = {p1[0], p1[1]}, f[1] = {p2[0], p2[1]}, f[2] = {p3[0], p3[1]},f[3] = {p4[0], p4[1]};
        set<int> s;
        for(int i = 0; i < 3; i++){
            for(int j = i + 1; j < 4; j++){
                s.insert((f[i][0] - f[j][0]) * (f[i][0] - f[j][0]) + (f[i][1] - f[j][1]) * (f[i][1] - f[j][1]));
            }
        }
        //cout << s.size() << ' ' << *s.begin() << ' ' << *s.rbegin() << endl;
        if(s.size() != 2 || *s.rbegin() != 2 * (*s.begin()) || *s.begin() == 0) return false;
        return true;
    }
};