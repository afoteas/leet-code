import math
class Solution:
    def isPalindromeString(self, x: int) -> bool:
        return str(x) == str(x)[::-1]

    def isPalindrome(self, x: int) -> bool:
        if x < 0 :
            return False
        elif x <10:
            return True    
        else:
            l = int(math.log10(x))+1
            for i in range(int(l/2)):
                if (x // pow(10,l-i-1) % 10) != ((x % pow(10,i+1)) // pow(10,i)):
                    return False
            return True         
