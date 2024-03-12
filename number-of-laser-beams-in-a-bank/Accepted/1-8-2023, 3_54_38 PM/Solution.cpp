// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int check(string s){
        int cnt = 0;
        for(auto i: s) cnt += (i != '0');
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> b;
        int ans = 0, num1 = 0, num2 = 0;
        for(int i = 0; i < bank.size(); i++){
            int tmp = check(bank[i]);
            if(!tmp) {
                bank.erase(bank.begin() + i), i--;
                continue;
            }
            cout << tmp << endl;
            if(num1 == 0){
                num1 = tmp;
            }else{
                num2 = tmp, ans += num1 * num2, num1 = num2;
            }
        }
        return ans;
    }
};