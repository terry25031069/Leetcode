// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    map<char, string>phone;
    vector<string> letterCombinations(string digits) {
        phone['2'] = "abc", phone['3'] = "def", phone['4'] = "ghi";
        phone['5'] = "jkl", phone['6'] = "mno", phone['7'] = "pqrs";
        phone['8'] = "tuv", phone['9'] = "wxyz";
        vector<string>ans;
        ans.push_back("");
        for(auto digit: digits){
            vector<string>anstmp;
            for(auto &i: phone[digit]){
                for(auto &j: ans){
                    anstmp.push_back(j + i);
                    cout << "push back result: " << j + i << endl;
                }
            }
            ans = anstmp;
        }
        for(auto i: ans) cout << i << ' ';
        cout << endl;
        if(ans.size() != 1 && ans[0] != "")return ans;
        else 
            ans.pop_back();
            return ans;
    }
};