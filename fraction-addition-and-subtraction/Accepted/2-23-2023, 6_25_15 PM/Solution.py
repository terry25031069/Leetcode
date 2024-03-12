// https://leetcode.com/problems/fraction-addition-and-subtraction

class Solution:
    def fractionAddition(self, exp: str) -> str:
        exp = exp.replace('-', ' - ').replace('+', ' + ')
        exp = exp.split()
        num, dem = 0, 1
        flag = 1
        for i in range(len(exp)):
            print("exp: ", exp[i])
            if exp[i] == '+': flag = 1 
            elif exp[i] == '-': flag = -1
            else: 
                tmp0, tmp1 = list(map(int, exp[i].split('/')))
                num, dem = flag * tmp0 * dem + tmp1 * num, dem * tmp1
                gcd = math.gcd(num, dem)
                num //= gcd
                dem //= gcd
                print(num, dem)
        if num == 0: return "0/1"
        else: return str(num) + "/" + str(dem)



