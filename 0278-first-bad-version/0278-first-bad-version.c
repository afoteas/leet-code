// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned int good = -1, bad = n, test;

    printf("%u\n",good);
    printf("%u\n",good+1);
    
    while (good+1 != bad){
        test = (good + bad)>>1u;
        if (isBadVersion(test)) bad = test;
        else good = test;
    }
    return bad;
}
