// https://leetcode.com/problems/binary-watch

class Solution {
public:
    string intToTime(int min){
        int h = min / 60, m = min % 60;
        return to_string(h) + ":" + to_string(m / 10) + to_string(m % 10);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        const vector<int> v = {1, 2, 4, 8, 16, 32, 60, 120, 240, 480};
        vector<string> ans; 
        for(int i = 0; i < 1024; i++){
            bitset<10> b(i);
            if(b.count() == turnedOn){
                int tmp = 0;
                for(int j = 0; j < 6; j++){
                    tmp += v[j] * b[j];
                }
                if(tmp >= 60) continue;
                for(int j = 6; j < 10; j++){
                    tmp += v[j] * b[j];
                }
                if(tmp >= 720) continue;
                //cout << b.to_string() << ' ' << b.count() << endl;
                ans.push_back(intToTime(tmp));
            }
        }
        return ans;
    }
};