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


"""
The difference in performance between checking membership in a list (like obstacles1) and 
checking membership in a set (like obstacles2) comes down to the underlying data structures 
and their time complexities for membership tests.

Lists vs. Sets

Lists:
When you check if an element is in a list using if [nx, ny] in obstacles1, Python has to iterate through
the entire list until it finds a match or reaches the end. This results in a time complexity of O(n),
where n is the number of elements in the list. In the worst case, it may have to check every single element.

Sets:
On the other hand, when you check if an element is in a set using if (nx, ny) in obstacles2, 
Python uses a hash table under the hood. This allows for average-case constant time complexity O(1)
for membership tests. The set checks the hash of the element to quickly determine if it exists, making it
significantly faster than searching through a list.

Summary
Membership Test in List: O(n)
Membership Test in Set: O(1) (average case)

This is why using a set for membership testing is generally much faster than using a list,
especially as the size of the collection grows. If you have a large number of obstacles and
need to frequently check for their presence, using a set is the more efficient choice.
"""