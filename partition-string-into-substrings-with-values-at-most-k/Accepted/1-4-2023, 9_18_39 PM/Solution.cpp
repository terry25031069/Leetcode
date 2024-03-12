// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k

class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0;
        int64_t tmp = 0;
        for(auto i: s){
            if(tmp * 10 + i - '0' <= (int64_t)k) tmp = tmp * 10 + i - '0';
            else{
                if(tmp) ans++;
                tmp = i - '0';
                if(tmp > k) return -1;
            } 
        }
        if(tmp <= k) ans++;
        return ans;
    }
};