// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v{1};
        int p[3] = {2,3,5}, candidate[3] = {2,3,5};
        int idx[3] = {1,1,1};
        for(int i = 0; i < n; i++){
            int m = *min_element(candidate, candidate + 3);
            v.push_back(m);
            if(v.size() == 1691) break;
            for(int j = 0; j < 3; j++){
                if(m == candidate[j]){
                    candidate[j] = v[idx[j]] * p[j];
                    idx[j]++; 
                }
            }
        }
        //for(int i: v) cout << i << ' '; cout << endl;
        return v[v.size() - 2];
    }
};