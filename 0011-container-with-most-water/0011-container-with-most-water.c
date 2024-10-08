int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxArea(int* height, int heightSize) {
    int ret = 0;
    int l = 0;
    int r = heightSize - 1;
    while (l != r) {
        int h = min(height[l],height[r]);
        int a = (r-l)*h;
        ret = max(ret, a);
        if (height[l] > height[r]) {
            r--;
        }
        else {
            l++;
        }
    }
    return ret;
}