// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    map<char, int>r;
    vector<int>tmp;
    int romanToInt(string s) {
        r['I'] = 1, r['V'] = 5, r['X'] = 10, r['L'] = 50, r['C'] = 100, r['D'] = 500, r['M'] = 1000;
        for(auto i: s){
            tmp.push_back(r[i]);
            cout << tmp.back() << ' ';
        }
        tmp.push_back(0);
        int ans = 0, current = tmp[0];
        for(int i = 1; i < tmp.size(); i++){
            if(tmp[i] <= current){
                ans += current;
                current = tmp[i];
            }else{
                ans -= current; 
                current = tmp[i];
            }
        }
        return ans;
    }
};