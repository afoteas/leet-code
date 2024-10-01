int minBitFlips(int start, int goal) {
    int ret = 0;
    int xor = start ^ goal;
    while(xor > 0) {
        ret += xor & 1;
        xor >>=1;
    }
    return ret;
}
