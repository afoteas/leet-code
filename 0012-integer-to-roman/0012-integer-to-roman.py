class Solution:
    def intToRoman(self, num: int) -> str:
        returnStr = ""
        print("test")
        values = {"M":1000, "CM":900, "D":500, "CD":400, "C":100, "XC":90,
         "L":50, "XL":40, "X":10, "IX":9, "V":5, "IV":4, "I":1}
        for number in values:
            count = num // values[number]
            num = num - values[number]*count
            returnStr += number*count
        return returnStr