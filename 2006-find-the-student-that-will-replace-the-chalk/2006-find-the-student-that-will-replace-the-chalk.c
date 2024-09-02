int chalkReplacer(int* chalk, int chalkSize, int k) {
    long long sum=0;
    for(int i=0; i<chalkSize; ++i) {
        sum+=chalk[i];
    }
    k=k%sum;
    int j=0;
    while(k>0) {
        if (k >= chalk[j]) {
            k-= chalk[j];
        } else {
            return j;
        }
        j=(j+1)%chalkSize;
    }
    return j;
}

