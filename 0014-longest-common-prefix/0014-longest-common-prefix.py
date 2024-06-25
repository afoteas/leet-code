class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        output=""

        for i in range(0,200):
            temp=""
            for st in strs:
                if len(st)<=i:
                    return output
                if temp=="":
                    temp=st[i]
                elif temp != st[i]:
                    return output
            output=output+temp
        return output
        
                
        