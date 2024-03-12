// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    bool check(string s){
        if(s.size() == 1 && !isdigit(s[0])) return false;
        for(int i = 0; i < s.size(); i++){
            if(i == 0 && s[i] == '-') continue;
            if(!isdigit(s[i])) return false;
        }
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        vector<long long>number;
        for(auto i: tokens){
            if(check(i)){
                number.push_back(stoll(i));
            }else{
                long long n2 = number.back(); number.pop_back();
                long long n1 = number.back(); number.pop_back();
                long long tmp;
                if(i == "+"){
                    tmp = n1 + n2;
                }else if(i == "-"){
                    tmp = n1 - n2;
                }else if(i == "*"){
                    tmp = n1 * n2;
                }else{
                    tmp = n1 / n2;
                }
                cout << tmp << endl;
                number.push_back(tmp);
            }
        }
        cout << endl;
        return number[0];
    }
};