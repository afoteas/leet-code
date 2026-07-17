class Solution {

    public int gcd(int x, int y) { 
        return y == 0 ? x : gcd(y, x % y); 
    }

    public long gcdSum(int[] nums) {
        int[] vxi = new int[nums.length];
        int[] prefixGcd = new int[nums.length];
        long ret = 0;
        for(int i=0; i<nums.length; i++) {
            if(i==0) vxi[i] = nums[i]; 
            else vxi[i] = Math.max(vxi[i-1],nums[i]);
        }
        for(int i=0; i<nums.length; i++) {
            prefixGcd[i]=gcd(nums[i],vxi[i]);
        }
        Arrays.sort(prefixGcd);
        int x=0;
        int y=nums.length-1;
        while(y>x) {
            ret += gcd(prefixGcd[x++], prefixGcd[y--]);
        }
        return ret;
    }


}