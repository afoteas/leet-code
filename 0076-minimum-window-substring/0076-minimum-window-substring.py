class Solution:
    def minWindowSlow(self, s: str, t: str) -> str:
        sar = list(s)
        si = 0
        ei = 0
        i = 0
        ml = None
        while i < len(sar):
            if sar[i] in t:
                print(f"sar[{i}]={sar[i]}")
                tt = t
                j = i
                tsi = i
                while j < len(sar):
                    if sar[j] in tt:
                        tt=tt.replace(sar[j],"",1)
                    if len(tt) == 0:
                        tei = j
                        print(f"apply tsi={tsi}, tei={tei}")
                        # inverse
                        tt = t
                        while j >= i :
                            if sar[j] in tt:
                                tt=tt.replace(sar[j],"",1)
                            if len(tt) == 0:
                                tsi = j
                                print(f"reverse tsi={tsi}, tei={tei}")
                                i = j
                                break
                            j -=1
                        # inverse end    
                        break
                    j +=1
                if len(tt) > 0:
                    print (f"return 1 tt={tt}")
                    if ml == None:
                        return ""
                    else:
                        break
                print(f"tsi={tsi}, tei={tei}")        
                if ml == None or ml > tei - tsi:
                    ei = tei
                    si = tsi
                    ml = tei - tsi
                    print(f"ml={ml}")

            i += 1
        print("return 2")
        if ml == None:
            return ""
        return "".join(sar[si:ei+1])    

    def minWindowherman(self, s: str, t: str) -> str:
        ret = ""
        vi = {}
        tt = t
        ts = list(set(t))
        for k, v in enumerate(s):
            first = False
            if v in ts:
                first = v not in vi
                if v in vi:
                    if v in tt:
                        print("if")
                        vi[v].append(k)
                        first = True
                    else:
                        print("else")
                        vi[v][vi[v].index(min(vi[v]))] = k
                else:
                    vi[v] = [k]       
                tt=tt.replace(v,"",1)        
            if len(vi.values()) == 0:
                continue 
            tmp_ret = s[min(sum(vi.values(), [])):k+1]
            if (len(tmp_ret) < len(ret)) or first:
                ret = tmp_ret

        if len(tt) > 0:
            return ""       
        print("peos")       
        return ret

    def minWindowO(self, s: str, t: str) -> str:
        ret = ""
        vi = {}
        tc = {}
        na = True
        for v in t:
            if v in tc:
                tc[v] += 1
            else:
                tc[v] = 1    
        tt = t
        ts = list(set(t))
        for k, v in enumerate(s):
            first = False
            if v in ts:
                e = False
                first = v not in vi
                if v in vi:
                    if tc[v] > 0:
                        vi[v].append(k)
                        first = True
                    else:
                        vi[v][vi[v].index(min(vi[v]))] = k
                else:
                    vi[v] = [k]  
                if tc[v] > 0:
                    tc[v] -= 1     
            if na:
                continue 
            tmp_ret = s[min(sum(vi.values(), [])):k+1]
            if (len(tmp_ret) < len(ret)) or first:
                ret = tmp_ret

        if sum(tc.values()) > 0:
            return ""          
        return ret

    def minWindow(self, s: str, t: str) -> str:
        ret = ""
        left = 0
        right = 0
        tc = [0] * 128  # character count array for t

        for char in t:
            tc[ord(char)] += 1

        count = len(t)  # number of characters remaining to be found in the window

        while right < len(s):
            if tc[ord(s[right])] > 0:
                count -= 1
            tc[ord(s[right])] -= 1

            while count == 0:
                if not ret or right - left + 1 < len(ret):
                    ret = s[left:right + 1]

                tc[ord(s[left])] += 1
                if tc[ord(s[left])] > 0:
                    count += 1
                left += 1

            right += 1

        return ret    