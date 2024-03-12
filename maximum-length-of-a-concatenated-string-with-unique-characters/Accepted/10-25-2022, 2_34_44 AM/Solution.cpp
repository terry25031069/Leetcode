// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    int hash(string s){
        int ans = 0;
        for(auto i: s){
            if((ans & (1 << (i - 'a'))) == 0){
                ans += 1 << (i - 'a');
            }else{
                return 0;
            }
        }
        return ans;
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<string>tmp{};
        for(auto i: arr){
            if(hash(i))tmp.push_back(i);
        }
        arr = tmp;
        for(int i = ((1 << arr.size()) - 1); i > -1; i--){
            int con = 0, add = 0, tmpsize = 0;
            for(int bit = 0; bit < arr.size(); bit++){
                if((i>>bit) & 1)con |= hash(arr[bit]), add += hash(arr[bit]), tmpsize += arr[bit].size();
            }
            if(con == add && con != 0) ans = max(ans, tmpsize);
        }
        return ans;
    }
};