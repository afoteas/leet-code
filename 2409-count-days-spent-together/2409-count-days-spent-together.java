class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int dpm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int arriveAliceMonth = Integer.valueOf(arriveAlice.substring(0,2));
        int arriveAliceDay = Integer.valueOf(arriveAlice.substring(3,5));
        int leaveAliceMonth = Integer.valueOf(leaveAlice.substring(0,2));
        int leaveAliceDay = Integer.valueOf(leaveAlice.substring(3,5));
        int arriveBobMonth = Integer.valueOf(arriveBob.substring(0,2));
        int arriveBobDay = Integer.valueOf(arriveBob.substring(3,5));
        int leaveBobMonth = Integer.valueOf(leaveBob.substring(0,2));
        int leaveBobDay = Integer.valueOf(leaveBob.substring(3,5));

        int stayAlice[] = {0,0};
        for (int i=0;i < arriveAliceMonth -1 ; i++) {
            stayAlice[0] += dpm[i];
        }
        stayAlice[0] = stayAlice[0] + arriveAliceDay;

        for (int i=0;i < leaveAliceMonth -1 ; i++) {
            stayAlice[1] = stayAlice[1] + dpm[i];
        }
        stayAlice[1] = stayAlice[1] + leaveAliceDay;

        int stayBob[] = {0,0};
        for (int i=0;i < arriveBobMonth -1 ; i++) {
            stayBob[0] = stayBob[0] + dpm[i];
        }
        stayBob[0] = stayBob[0] + arriveBobDay;

        for (int i=0;i < leaveBobMonth -1 ; i++) {
            stayBob[1] = stayBob[1] + dpm[i];
        }
        stayBob[1] = stayBob[1] + leaveBobDay;

        if (stayAlice[1] < stayBob[0] || stayBob[1] < stayAlice[0]) {
            return 0;
        }
        return  Math.min(stayAlice[1],stayBob[1]) - Math.max(stayBob[0], stayAlice[0]) + 1;
    }
}