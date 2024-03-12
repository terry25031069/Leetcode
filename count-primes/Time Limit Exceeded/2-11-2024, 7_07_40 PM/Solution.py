// https://leetcode.com/problems/count-primes

class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        tmp = list(range(2, n+1))
        alive = [1 for i in range(1, n + 10000)]

        for i in tmp:
            if i < sqrt(tmp[-1]) + 1:
                for j in range(i, n//i + 1):
                    if alive[j * i]:
                        tmp.remove(j * i)
                        alive[j * i] = 0
        if tmp[-1] == n:
            tmp.pop()
        print(tmp)
        return len(tmp)