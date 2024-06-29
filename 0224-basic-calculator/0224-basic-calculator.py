class Solution:
    def calculateSlow(self, s: str) -> int:
        par=["+"]
        papar="+"
        numbers=[]
        cur_num=""
        sign="+"
        ss=s.replace(" ", "")
        for c in ss:
            if c in ["0","1","2","3","4","5","6","7","8","9"]:
                cur_num+=c
            else:
                if cur_num:
                    pros = par.count("-")
                    if pros%2 == 0:
                        papar="+"
                    else:
                        papar="-"
                    if papar == sign:
                        numbers.append(int(cur_num))
                    else:
                        numbers.append(-int(cur_num))
                    cur_num = ""
                if c == "(":
                    par.append(sign)
                    sign="+"
                elif c == ")":
                    par.pop()
                else:
                    sign = c
        if cur_num:
            pros = par.count("-")
            if pros%2 == 0:
                papar="+"
            else:
                papar="-"
            if sign == papar:
                numbers.append(int(cur_num))
            else:
                numbers.append(-int(cur_num))
        return sum(numbers)

    def calculate(self, s: str) -> int:
        par=["+"]
        papar="+"
        total_sum=0
        cur_num=""
        sign="+"
        ss=s.replace(" ", "")
        for c in ss:
            if c in ["0","1","2","3","4","5","6","7","8","9"]:
                cur_num+=c
            else:
                if cur_num:
                    pros = par.count("-")
                    if pros%2 == 0:
                        papar="+"
                    else:
                        papar="-"
                    if papar == sign:
                        total_sum += int(cur_num)
                    else:
                        total_sum -= int(cur_num)
                    cur_num = ""
                if c == "(":
                    par.append(sign)
                    sign="+"
                elif c == ")":
                    par.pop()
                else:
                    sign = c
        if cur_num:
            pros = par.count("-")
            if pros%2 == 0:
                papar="+"
            else:
                papar="-"
            if sign == papar:
                total_sum += int(cur_num)
            else:
                total_sum -= int(cur_num)
        return total_sum                
                 
                


        