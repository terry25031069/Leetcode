// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        char tmp[numRows][s.size()];
        memset(tmp, 0, sizeof(tmp));
        int loc, x, y, dx, dy;
        int unit = 2 * numRows - 2;
        loc = x = y = 0;
        while(loc < s.size()){
            cout << x << ' ' << y << ' ' << s[loc] << endl;
            tmp[x][y] = s[loc];
            if(loc % unit == 0) dx = 1, dy = 0;
            else if(loc % unit == unit / 2) dx = -1, dy = 1;
            x += dx, y += dy, loc++;
        }
        string ans = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < ceil(double(s.size()) / 2.0); j++){
                if(tmp[i][j]) ans += tmp[i][j]; 
                //cout << tmp[i][j] << " \n"[j == ceil(s.size() / 2) - 1];
            }
        }
        return ans;
    }
};