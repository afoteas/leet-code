class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        if not customers:
            return 0
        times = []
        nextFree = 0
        for customer in customers:
            if nextFree < customer[0]:
                nextFree = customer[0] + customer[1]
            else:
                nextFree += customer[1]
            times.append(nextFree - customer[0])

        return sum(times)/len(times)
        