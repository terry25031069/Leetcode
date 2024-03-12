// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        using pci = pair<char, int>;
        vector<pci> v1, v2;
        name += 'S', typed += 'S';
        char cur = name[0]; int cnt = 0;
        for(auto c: name){
            if(c == cur) cnt++;
            else v1.push_back({cur, cnt}), cur = c, cnt = 1;
        }
        cur = typed[0], cnt = 0;
        for(auto c: typed){
            if(c == cur) cnt++;
            else v2.push_back({cur, cnt}), cur = c, cnt = 1;
        }
        if(v1.size() != v2.size()) return false;
        for(int i = 0; i < v1.size(); i++){
            if(v1[i].first != v2[i].first || v1[i].first == v2[i].first && v1[i].second > v2[i].second) return false;
        }
        return true;
    }
};