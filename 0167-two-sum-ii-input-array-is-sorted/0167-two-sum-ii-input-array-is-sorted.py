class Solution:
    def twoSumSlow(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)-1):
            for j in range(i+1, len(numbers)):
                if numbers[i]+numbers[j]==target:
                    return [i+1,j+1]

    def twoSumMedium(self, numbers: List[int], target: int) -> List[int]:
        test=[]
        for number in numbers:
            test.append(number-target)
        ret = []
        for number in numbers:
            try:
                index = test.index(-number)
                print(ret)
                if (index+1) in ret:
                    return [index+1,index+2]
                else:
                    ret.append(index + 1)
            except ValueError:
                continue
        if len(ret) > 2:
            for i in range(len(ret)):
                 for j in range(i+1, len(ret)):
                    if numbers[ret[i]-1]+numbers[ret[j]-1]==target and ret[j] != ret[i]:
                        return [ret[j],ret[i]]
        return ret[::-1]

    def twoSumEven(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            if -(numbers[i] - target) in numbers[i+1:]:
                return [i+1,numbers[i+1:].index(-(numbers[i] - target))+2+i]

    def twoSumWhile(self, numbers: List[int], target: int) -> List[int]:
        i=0
        j=len(numbers)-1
        tar = numbers[i] + numbers[j]
        while tar != target:
            if tar < target:
                i+=1
            else:
                j-=1
            tar = numbers[i] + numbers[j]
        return [i+1,j+1]
    
    def twoSum(self, numbers: List[int], target: int, i=None, j=None) -> List[int]:
        i  = 0 if i is None else i
        j  = len(numbers) - 1 if j is None else j
        if numbers[i] + numbers[j] < target:
            return self.twoSum(numbers, target, i+1, j)
        elif numbers[i] + numbers[j] > target:
            return self.twoSum(numbers, target, i, j-1)
        else:
            return [i+1, j+1]