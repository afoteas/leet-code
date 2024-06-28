class Solution:
    def isValid(self, s: str) -> bool:

        last=[]
        for c in s:
            if c in ["(", "{", "["]:
                last.append(c)
            elif not last:
                return False
            if c==")" and last.pop() != "(":
                return False
            if c=="}" and last.pop() != "{":
                return False
            if c=="]" and last.pop() != "[":
                return False
        if len(last) == 0:
            return True
        else:
            return False      