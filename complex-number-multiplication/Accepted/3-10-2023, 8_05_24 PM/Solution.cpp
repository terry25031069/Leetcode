// https://leetcode.com/problems/complex-number-multiplication

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string a, b, c, d; int idx = 0, aa, bb, cc, dd;
        a = b = c = d = "";
        for(char ch: (num1 + num2)){
            if(ch == '+'){
                idx++;
                continue;
            }
            else if(ch == 'i'){
                idx++;
                continue;
            }
            if(idx == 0) a += ch;
            else if(idx == 1) b += ch;
            else if(idx == 2) c += ch;
            else d += ch;
        }
        cout << a << '/' << b << '/' << c << '/' << d << endl;
        aa = stoi(a), bb = stoi(b), cc = stoi(c), dd = stoi(d);
        return to_string(aa*cc - bb*dd) + "+" + to_string(aa*dd + bb*cc) + "i";
    }
};