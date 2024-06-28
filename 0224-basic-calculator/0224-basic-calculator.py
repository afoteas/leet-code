class Solution:
    def calculate(self, s: str) -> int:
        par=["+"]
        papar="+"
        numbers=[]
        cur_num=""
        sign="+"
        ss=s.replace(" ", "")
        for c in ss:
            if c in ["0","1","2","3","4","5","6","7","8","9"]:
                print(f"c==number")
                cur_num+=c
            else:
                if cur_num:
                    print(f"cur_num={cur_num}")
                    pros = par.count("-")
                    if pros%2 == 0:
                        papar="+"
                    else:
                        papar="-"
                    if papar == sign:
                        print(f"append=+")
                        numbers.append(int(cur_num))
                    else:
                        print(f"append=-")
                        numbers.append(-int(cur_num))
                    cur_num = ""
                if c == "(":
                    par.append(sign)
                    sign="+"
                    print(f"par = sign = {par}")
                elif c == ")":
                    par.pop()
                    print(f"par = {par}")
                else:
                    sign = c
                    print(f"sign = {c}")
        if cur_num:
            pros = par.count("-")
            if pros%2 == 0:
                papar="+"
            else:
                papar="-"
            if sign == papar:
                print(f"append=+")
                numbers.append(int(cur_num))
            else:
                print(f"append=-")
                numbers.append(-int(cur_num))
        return sum(numbers)
                
                 
                


        