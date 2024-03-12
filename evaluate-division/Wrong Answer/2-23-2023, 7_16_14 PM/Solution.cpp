// https://leetcode.com/problems/evaluate-division

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> m;
        double e[21][21] = {};
        int idx = 1;
        for(int i = 0; i < equations.size(); i++){
            vector<string>eq = equations[i];
            if(!m[eq[0]]) m[eq[0]] = idx++;
            if(!m[eq[1]]) m[eq[1]] = idx++;
            e[m[eq[0]]][m[eq[1]]] = values[i];
            e[m[eq[1]]][m[eq[0]]] = 1. / values[i];
            e[m[eq[0]]][m[eq[0]]] = e[m[eq[1]]][m[eq[1]]] = 1.;
        }
        for(int k = 1; k < idx; k++){
            for(int i = 1; i < idx; i++){
                for(int j = 1; j < idx; j++){
                    if(!e[i][j]) e[i][j] = e[i][k] * e[k][j];
                }
            }
        }   
        cout << fixed << setprecision(3);
        for(int i = 1; i < idx; i++){
            for(int j = 1; j < idx; j++){
                cout << e[i][j] << ' ';
            } cout << endl;
        }
        vector<double> ans;     
        for(auto q: queries){
            int from = m[q[0]], to = m[q[1]];
            if(from == 0 || to == 0) ans.push_back(-1.0);
            else ans.push_back(e[from][to]);
        }
        return ans;
    }
};