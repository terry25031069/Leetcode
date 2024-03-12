// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    bool check(string s){
        for(int i = 0; i < s.size(); i++){
            if(i == 0 && s[i] == '-') continue;
            if(!isdigit(s[i])) return false;
        }
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        vector<int>number;
        for(auto i: tokens){
            if(check(i)){
                number.push_back(stoi(i));
            }else{
                int n2 = number.back(); number.pop_back();
                int n1 = number.back(); number.pop_back();
                int tmp;
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