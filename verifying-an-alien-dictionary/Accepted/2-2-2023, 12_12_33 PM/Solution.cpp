// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        auto tmp = words;
        sort(tmp.begin(), tmp.end(), [&order](string a, string b){
            for(int i = 0; i < min(a.size(), b.size()); i++){
                if(a[i] != b[i]) return order.find(a[i]) < order.find(b[i]);
            }
            return a.size() < b.size();
        });
        return tmp == words;
    }
};