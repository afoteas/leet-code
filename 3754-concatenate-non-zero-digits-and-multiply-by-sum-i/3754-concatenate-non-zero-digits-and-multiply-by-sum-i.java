class Solution {
    public long sumAndMultiply(int n) {
        int x = 0;
        int s = 0;
        int i = 0;
        while(n>0) {
            if(n%10 >0) {
                x+= (n%10)*Math.pow(10,i++);
                s+= n%10;
            }
            n/=10;
        }
        return (long)x*s;
    }
}