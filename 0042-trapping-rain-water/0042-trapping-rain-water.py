class Solution:
    def trap(self, height: List[int]) -> int:
        peaks = []
        if len(height) < 3:
            return 0
        monotony = -1
        previous = height[0]
        for i,h in enumerate(height):
            # print(f"previous={previous}, h={h}, monotony={monotony}")
            if h <= previous and monotony >= 0:
                peaks.append(i-1)
            if h > previous:
                monotony = 1
            elif h < previous:
                monotony = -1
            else:
                monotony = 0
            previous = h
        if height[-2] < height[-1]:
            peaks.append(len(height)-1)
        # print(peaks)
        # tmp = [peaks[0]]
        # for i in range(1,len(peaks)-1):
        #     if height[peaks[i]] <=  height[peaks[i-1]] and height[peaks[i]] <= height[peaks[i+1]]:
        #         continue
        #     tmp.append(peaks[i])
        # tmp.append(peaks[-1])
        tmp = list(peaks)
        peaks = []
        while tmp != peaks:
            peaks = list(tmp)
            tmp = [peaks[0]]
            for i in range(1,len(peaks)-1):
                if height[peaks[i]] <=  height[peaks[i-1]] and height[peaks[i]] <= height[peaks[i+1]]:
                    continue
                tmp.append(peaks[i])
            tmp.append(peaks[-1])
        # print(tmp)
        ret = 0
        for i in range(len(peaks)-1):
            l = peaks[i]
            r = peaks[i+1]
            h = min(height[l], height[r])
            for j in range(l,r+1):
                w = h - height[j]
                if w > 0:
                    ret+=w
        return ret

        