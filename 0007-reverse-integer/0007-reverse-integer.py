class Solution:
    def reverse(self, x: int) -> int:
        if x==0:
            return 0
        chint=f"{x}"
        sign = -1 if chint[0] == "-" else 1
        chret=""
        for ch in chint[::-1]:
            if not chret and ch=="0":
                continue
            else:
                if ch != "-":
                    chret+=ch
        # print(f"chret={chret}")
        intret=int(chret)
        if intret > 2147483647:
            return 0
        else:
            return sign*intret
        