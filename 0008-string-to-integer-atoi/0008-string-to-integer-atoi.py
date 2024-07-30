class Solution:
    def myAtoi(self, s: str) -> int:
        sign = None
        ss = ""
        for c in s:
            if c == " " and not ss and not sign:
                continue
            if c in ["+","-"] and not ss:
                if sign:
                    break
                if c == "-":
                    sign=-1
                else:
                    sign=1
            elif c.isdigit():
                if ss == "0":
                    if c!="0":
                        ss = c
                    continue
                ss+=c
            else:
                break
        if not sign:
            sign = 1
        if not ss:
            return 0
        else:
            number = sign*int(ss)
            if number > 2147483647:
                number = 2147483647
            elif number < -2147483648:
                number = -2147483648
            return number

        