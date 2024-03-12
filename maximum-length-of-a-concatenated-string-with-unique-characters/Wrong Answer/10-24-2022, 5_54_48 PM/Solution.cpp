// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    int hash(string s){
        int ans = 0;
        for(auto i: s)ans += 1 << (i - 'a');
        return ans;
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        for(int i = 0; i < (1 << arr.size()); i++){
            int con = 0, add = 0, tmpsize = 0;
            for(int bit = 0; bit < arr.size(); bit++){
                if((i>>bit) & 1)con |= hash(arr[bit]), add += hash(arr[bit]), tmpsize += arr[bit].size();
            }
            if(con == add) ans = max(ans, tmpsize);
        }
        return ans;
    }
};