class Solution:
    def maxDistanceTimeout(self, arrays: List[List[int]]) -> int:
        maxes = []
        for i in range(len(arrays)):
            tempMax = 0
            for j in range(len(arrays)):
                if i != j:
                    tempMax = max(tempMax, abs(arrays[i][0] - arrays[j][-1]))
            maxes.append(tempMax)
        return max(maxes)

    def maxDistance(self, arrays: List[List[int]]) -> int:
        low = arrays[0][0]
        high = arrays[0][-1]
        ret = 0
        for arr in arrays[1:]:
            temp_low = min(low, arr[0])
            temp_high = max(high,arr[-1])
            if temp_low != low and temp_high != high:
                ret = max(high - temp_low, temp_high - low)
            else:

                t_low = arr[0]
                t_high = arr[-1]
                ret = max(ret, max(high - t_low, t_high - low))

            low = temp_low
            high = temp_high
            print(f"ret={ret}, low={low}, high={high}")
        return ret



        