class Solution:
    def canCompleteCircuitSlow(self, gas: List[int], cost: List[int]) -> int:
        ns = len(gas)       
        for j in range(0,ns):
            fuel=gas[j]
            # print(f'start at station {j} and filled {fuel}')
            for i in range(j,ns+j):
                fuel -=cost[i%ns]
                # print(f'travelled to station {(i+1)%ns} with remaining fuel {fuel}')

                if fuel < 0:
                    # print(f'did not make it, break')
                    break
                else:
                    fuel += gas[(i+1)%ns]
                    # print(f'make it... filled with fuel: {gas[(i+1)%ns]}, ready to travel with fuel {fuel}')

            if fuel > 0:
                return j
        
        return -1
        

    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        ns = len(gas)
        gas = [x - y for x, y in zip(gas, cost)]
        if sum(gas) < 0:
            return -1
        fuel = 0
        ret = 0
        for i in range(0,ns):
            fuel+=gas[i]
            if fuel <0:
                fuel=0
                ret=i+1

        
        return ret


        