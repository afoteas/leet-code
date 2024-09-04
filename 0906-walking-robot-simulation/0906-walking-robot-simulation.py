class Solution:
    def robotSimSlow(self, commands: List[int], obstacles: List[List[int]]) -> int:
        cindex = 0
        position = [0, 0]
        # n, e, s, w
        orientation = [[0,1],[1,0],[0,-1],[-1,0]]
        maxEuclidean = 0
        pointer = 0
        while cindex < len(commands):
            command = commands[cindex]
            if command < 0:
                if command == -1:
                    pointer = (pointer + 1)%4
                else:
                    pointer = (pointer - 1)%4
                cindex+=1
            elif command > 0:
                nextPosition = [a + b for a, b in zip(position, orientation[pointer])]
                if nextPosition in obstacles:
                    cindex+=1
                else:
                    position=nextPosition
                    
                    maxEuclidean = max(maxEuclidean,sum(x**2 for x in position))
                    commands[cindex]-=1
            else:
                cindex+=1
        return maxEuclidean
        
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obstacles=set(map(tuple,obstacles))
        # obstacles=set(map(tuple,obstacles))
        cindex = 0
        position = [0, 0]
        # n, e, s, w
        orientation = [[0,1],[1,0],[0,-1],[-1,0]]
        maxEuclidean = 0
        pointer = 0
        x,y=0,0
        while cindex < len(commands):
            command = commands[cindex]
            if command < 0:
                if command == -1:
                    pointer = (pointer + 1)%4
                else:
                    pointer = (pointer - 1)%4
                cindex+=1
            elif command > 0:
                nx = x+ orientation[pointer][0]
                ny = y+ orientation[pointer][1]
                # if [nx,ny] in obstacles:
                if (nx,ny) in obstacles:
                    cindex+=1
                else:
                    x,y=nx,ny
                    maxEuclidean = max(maxEuclidean,x*x+y*y)
                    commands[cindex]-=1
            else:
                cindex+=1
        return maxEuclidean

        