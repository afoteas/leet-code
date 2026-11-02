class Solution:

    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:

        dpm = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        arriveAliceMonth = int(arriveAlice[0:2])

        arriveAliceDay = int(arriveAlice[3:6])

        leaveAliceMonth = int(leaveAlice[0:2])

        leaveAliceDay = int(leaveAlice[3:6])

        arriveBobMonth = int(arriveBob[0:2])

        arriveBobDay = int(arriveBob[3:6])

        leaveBobMonth = int(leaveBob[0:2])

        leaveBobDay = int(leaveBob[3:6])

 

        stayAlice = [0,0]

        for i in range(0, arriveAliceMonth - 1):

            stayAlice[0] = stayAlice[0] + dpm[i]

        stayAlice[0] = stayAlice[0] + arriveAliceDay

 

        for i in range(0, leaveAliceMonth - 1):

            stayAlice[1] = stayAlice[1] + dpm[i]

        stayAlice[1] = stayAlice[1] + leaveAliceDay

 

        stayBob = [0,0]

        for i in range(0, arriveBobMonth - 1):

            stayBob[0] = stayBob[0] + dpm[i]

        stayBob[0] = stayBob[0] + arriveBobDay

 

        for i in range(0, leaveBobMonth - 1):

            stayBob[1] = stayBob[1] + dpm[i]

        stayBob[1] = stayBob[1] + leaveBobDay

 

        if stayAlice[1] < stayBob[0] or stayBob[1] < stayAlice[0]:

            return 0

 

        return  min(stayAlice[1],stayBob[1]) - max(stayBob[0], stayAlice[0]) + 1