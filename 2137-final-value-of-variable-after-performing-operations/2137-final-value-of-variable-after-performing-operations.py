class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        actions = {"++X":1, "X++":1, "--X":-1, "X--":-1}
        ret = 0
        for op in operations:
            ret += actions[op]
        return ret
        