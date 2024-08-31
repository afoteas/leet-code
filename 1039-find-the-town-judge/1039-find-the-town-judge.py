class Solution:
    def findJudgeMine(self, n: int, trust: List[List[int]]) -> int:
        if not trust:
            if n>1:
                return -1
            else:
                return 1
        trusts=defaultdict(int)
        for t in trust:
            trusts[t[1]]+=1
        
        j = max(trusts, key=trusts.get)
        for t in trust:
            if t[0] == j:
                return -1
        if trusts[j]==n-1:
            return j
        else:
            return -1

    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # Create a list of of person and their trust value
        numTrust = [0] * (n + 1)
        print(numTrust)

        # Increase trust value of trustee and decrease trust value of truster for each pair
        for person1, person2 in trust:
            numTrust[person1] -= 1
            numTrust[person2] += 1
        
        # Check if anyone achieves n-1 trust. This person is the town judge
        for i in range(1, len(numTrust)):
            if numTrust[i] == n - 1:
                return i
        
        # If no one achieves n-1 trust, then there is no town judge
        return -1