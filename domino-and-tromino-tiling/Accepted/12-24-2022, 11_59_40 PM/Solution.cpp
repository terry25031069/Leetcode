// https://leetcode.com/problems/domino-and-tromino-tiling

static int N = int(1e9+7);
class Solution {
public:
    struct mat{
        long long a[4][4];
        mat(vector<long long>n){
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    a[i][j] = n[i*4+j];
                }
            }
        }
        mat operator * (mat b){
            mat ans(vector<long long>(16, 0));
            for(int i = 0; i < 4; i++){
                for(int k = 0; k < 4; k++){
                    int tmp = a[i][k];
                    for(int j = 0; j < 4; j++){
                        ans.a[i][j] += tmp * b.a[k][j] % N;
                        ans.a[i][j] %= N;
                    }
                }
            }
            return ans;
        }
    };
    mat pow(mat a, int n){
        if(n == 1) return a;
        auto tmp = pow(a, n / 2);
        if(n & 1) return tmp * tmp * a;
        return tmp * tmp;
    }

    int numTilings(int n) {
        vector<long long> ele{2, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
        vector<long long> init{11, 11, 11, 11, 5, 5, 5, 5, 2, 2, 2, 2, 1, 1, 1, 1};
        mat a(ele), b(init);
        if(n < 5){
            reverse(init.begin(), init.end());
            return init[4 * n - 4];
        }
        mat ans = pow(a, n - 4) * b;
        return ans.a[0][0];
    }
};