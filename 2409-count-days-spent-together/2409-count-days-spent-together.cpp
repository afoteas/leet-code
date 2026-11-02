class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int dpm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int arriveAliceMonth = stoi(arriveAlice.substr(0,2));
        int arriveAliceDay = stoi(arriveAlice.substr(3,2));
        int leaveAliceMonth = stoi(leaveAlice.substr(0,2));
        int leaveAliceDay = stoi(leaveAlice.substr(3,2));
        int arriveBobMonth = stoi(arriveBob.substr(0,2));
        int arriveBobDay = stoi(arriveBob.substr(3,2));
        int leaveBobMonth = stoi(leaveBob.substr(0,2));
        int leaveBobDay = stoi(leaveBob.substr(3,2));

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


        return  min(stayAlice[1],stayBob[1]) - max(stayBob[0], stayAlice[0]) + 1;
    }
};