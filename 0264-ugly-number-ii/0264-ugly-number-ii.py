class Solution:
    def nthUglyNumberYield(self, n: int) -> int:
        if n == 1:
            return 1
        def ugly2():
            value=0
            while True:
                value+=2
                yield value
        def ugly3():
            value=0
            while True:
                value+=3
                yield value
        def ugly5():
            value=0
            while True:
                value+=5
                yield value
        def ugly():
            g2,g3,g5 = ugly2(), ugly3(), ugly5()
            u2 = next(g2)
            u3 = next(g3)
            u5 = next(g5)
            while True:
                ret=0
                if u2 < u3 and u2 < u5:
                    ret = u2
                    u2 = next(g2)
                elif u3 < u2 and u3 < u5:
                    ret = u3
                    u3 = next(g3)
                elif u5 < u2 and u5 < u3:
                    ret = u5
                    u5 = next(g5)
                elif u2 == u3 and u2 < u5:
                    ret = u2
                    u2 = next(g2)
                    u3 = next(g3)
                elif u2 == u5 and u2 < u3:
                    ret = u2
                    u2 = next(g2)
                    u5 = next(g5)
                elif u3 == u5 and u3 < u2:
                    ret = u3
                    u3 = next(g3)
                    u5 = next(g5)
                yield ret
        ret = 1
        count = 1
        for u in ugly():
            if count == n:
                break
            ret = u
            count += 1
        return ret

    def nthUglyNumber(self, n: int) -> int:
        uglyNumbers = [1]
        p2, p3, p5 = 0, 0, 0
        nextUgly2 = 2
        nextUgly3 = 3
        nextUgly5 = 5
        nextUgly = 1
        for i in range(1,n):
            nextUgly = min([nextUgly2,nextUgly3,nextUgly5])
            uglyNumbers.append(nextUgly)
            if nextUgly == nextUgly2:
                p2+=1
                nextUgly2 = uglyNumbers[p2]*2
            if nextUgly == nextUgly3:
                p3+=1
                nextUgly3 = uglyNumbers[p3]*3
            if nextUgly == nextUgly5:
                p5+=1
                nextUgly5 = uglyNumbers[p5]*5
        return nextUgly
        
        