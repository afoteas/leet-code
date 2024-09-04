class Solution:
    # def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
    #     obstacles=set(map(tuple,obstacles))
    #     cindex = 0
    #     position = [0, 0]
    #     # n, e, s, w
    #     orientation = [[0,1],[1,0],[0,-1],[-1,0]]
    #     maxEuclidean = 0
    #     pointer = 0
    #     x,y=0,0
    #     while cindex < len(commands):
    #         command = commands[cindex]
    #         if command < 0:
    #             if command == -1:
    #                 pointer = (pointer + 1)%4
    #             else:
    #                 pointer = (pointer - 1)%4
    #             cindex+=1
    #         elif command > 0:
    #             nx = x+ orientation[pointer][0]
    #             ny = y+ orientation[pointer][1]
    #             if (nx,ny) in obstacles:
    #                 cindex+=1
    #             else:
    #                 x,y=nx,ny

    #                 maxEuclidean = max(maxEuclidean,x*x+y*y)
    #                 commands[cindex]-=1
    #         else:
    #             cindex+=1
    #     return maxEuclidean
        
    def robotSim(self,commands,obstacles):
        x,y,d=0,0,0
        direction=[(0,1),(1,0),(0,-1),(-1,0)]
        max_distance=0
        obstacles=set(map(tuple,obstacles))
        
        for cmd in commands:
            if cmd==-1:
                d=(d+1)%4
            elif cmd==-2:
                d=(d-1)%4
            else:
                for _ in range(cmd):
                    nx,ny=x+direction[d][0],y+direction[d][1]
                    if (nx,ny) in obstacles:
                        break
                    x,y=nx,ny
                    max_distance=max(max_distance,x*x+y*y)
        
        return max_distance



        