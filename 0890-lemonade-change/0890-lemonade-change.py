class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        fives = 0
        tens = 0
        for bill in bills:
            print(f"fives={fives}, tens={tens}")
            if bill == 5:
                fives +=1
            elif bill == 10:
                if fives:
                    fives-=1
                    tens+=1
                else:
                    return False
            else:
                if tens:
                    tens-=1
                    if fives:
                        fives-=1
                    else:
                        return False
                else:
                    if fives > 2:
                        fives-=3
                    else:
                        return False
        return True
        