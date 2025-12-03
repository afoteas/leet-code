class Solution:
    def slope(self, p:List[List[int]]) -> int:
        if (p[1][0]-p[0][0]) == 0:
            return float('inf')
        return (p[1][1]-p[0][1])/(p[1][0]-p[0][0])
    
    def isTrapezoid(self, points:List[List[int]]) -> bool:
        lines = list(combinations(points, 2))
        slopes = {}

        for line in lines:
            sl = self.slope(line)
            if sl in slopes:
                slopes[sl]+=1
            else:
                slopes[sl] = 1
        for count in slopes.values():
            if count == 2:
                return True
        return False

    def countTrapezoidsSlow(self, points: List[List[int]]) -> int:
        rectangles = list(combinations(points, 4))
        ret = 0
        for rectangle in rectangles:
            if self.isTrapezoid(rectangle):
                ret += 1
        return ret

    def countTrapezoids(self, points: List[List[int]]) -> int:
        n = len(points)
        inf = 10**9 + 7
        slope_to_intercept = defaultdict(list)
        mid_to_slope = defaultdict(list)
        ans = 0

        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx = x1 - x2
                dy = y1 - y2

                if x2 == x1:
                    k = inf
                    b = x1
                else:
                    k = (y2 - y1) / (x2 - x1)
                    b = (y1 * dx - x1 * dy) / dx

                mid = (x1 + x2) * 10000 + (y1 + y2)
                slope_to_intercept[k].append(b)
                mid_to_slope[mid].append(k)

        for sti in slope_to_intercept.values():
            if len(sti) == 1:
                continue

            cnt = defaultdict(int)
            for b_val in sti:
                cnt[b_val] += 1

            total_sum = 0
            for count in cnt.values():
                ans += total_sum * count
                total_sum += count

        for mts in mid_to_slope.values():
            if len(mts) == 1:
                continue

            cnt = defaultdict(int)
            for k_val in mts:
                cnt[k_val] += 1

            total_sum = 0
            for count in cnt.values():
                ans -= total_sum * count
                total_sum += count

        return ans

        