// https://leetcode.com/problems/optimal-partition-of-string

class Solution {
public:
    int partitionString(string s) {
        s += s.back();
        int ans = 0;
        set<char> se;
        for(char c: s){
            if(se.find(c) != se.end()) ans++, se.clear();
            se.insert(c);
        }
        return ans;
    }
};