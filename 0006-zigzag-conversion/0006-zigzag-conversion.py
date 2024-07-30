class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) < 2 or numRows == 1:
            return s
        else:
            retList = [""] * numRows
            down = True
            retList[0]=s[0]
            position=1
            for c in s[1:]:
                if position == 0:
                    down = True
                if position == numRows-1:
                    down = False
                
                retList[position]+=c
                if down:
                    position+=1
                else:
                    position-=1
                


            return "".join(retList)

        