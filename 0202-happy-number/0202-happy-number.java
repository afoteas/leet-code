import java.util.HashSet;


class Solution {
    // public boolean isHappySlow(int n) {
    //     Set<Integer> seenSet = new HashSet<>();
    //     while (n != 1 && !seenSet.contains(n)){
    //         seenSet.add(n);
    //         char[] charArray = String.valueOf(n).toCharArray();
            
    //         // Convert the char array to an IntStream of the integer values
    //         IntStream intStream = new String(charArray).chars().map(Character::getNumericValue);
        
    //         // Calculate the sum of squares using the IntStream
    //         n = intStream.map(i -> i * i).sum();
            
    //     }

    //     return n == 1;
    // }

    public boolean isHappy(int n) {
        Set<Integer> seenSet = new HashSet<>();
        while (n != 1 && !seenSet.contains(n)){
            seenSet.add(n);
            int sum = 0;
            for (char ch : String.valueOf(n).toCharArray()) {
                int digit = ch - '0'; // Convert char to int (assuming the char represents a digit)
                sum += digit * digit; // Square the digit and add to the sum
            }
            n = sum;
            
        }

        return n == 1;
    }
}