class Solution:
    def trap(self, height: List[int]) -> int:
        peaks = []
        if len(height) < 3:
            return 0
        monotony = -1
        previous = height[0]
        for i,h in enumerate(height):
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
        # tmp = []
        # while tmp != peaks:
        #     tmp = list(peaks)
        #     peaks = [tmp[0]]
        #     for i in range(1,len(tmp)-1):
        #         if height[tmp[i]] <=  height[tmp[i-1]] and height[tmp[i]] <= height[tmp[i+1]]:
        #             continue
        #         peaks.append(tmp[i])
        #     peaks.append(tmp[-1])
        m = 1
        n = len(peaks)-1
        # print(peaks)
        # print(m)
        # print(n)
        while m <= n-1:
            # print("mpeos")
            if height[peaks[m]] <= height[peaks[m-1]] and height[peaks[m]] <= height[peaks[m+1]]:
                # print("peos")
                del peaks[m]
                n-=1
                m=1
            else:
                m+=1
        # print(peaks)
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

        