class Solution:
    def myPowInf(self, x: float, n: int) -> float:

        if n == 0:
            return 1
        ans = x
        for i in range(abs(n)-1):
            ans *=x
        if n > 0:
            return ans
        else:
            return 1/ans

    def myPow(self, x: float, n: int) -> float:
        @cache
        def myRec(x:float, n:int) -> float:
            ans = x
            for i in range(abs(n)-1):
                ans *=x
            return ans

        if n == 0:
            return 1

        ans = x
        batches = 100
        steps = abs(n)-1
        bigSteps = steps//batches
        for i in range(bigSteps):
            ans *=myRec(x,batches)
        for i in range(steps - bigSteps*batches):
            ans *=x
        if n > 0:
            return ans
        else:
            return 1/ans

        