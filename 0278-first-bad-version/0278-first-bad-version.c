// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned int good = -2, bad = n, test;

    printf("%d\n",good);
    printf("%d\n",good+1);
    
    while (good+1 != bad){
        test = (good + bad)>>1;
        if (isBadVersion(test)) bad = test;
        else good = test;
    }
    return bad;
}
