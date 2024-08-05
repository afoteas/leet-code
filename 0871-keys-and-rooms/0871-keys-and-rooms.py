class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        locked = [1] * n
        locked[0] = 0
        def dfs(room) -> bool:
            print(room)
            for r in room:
                if locked[r]:
                    locked[r] = 0
                    dfs(rooms[r])
        dfs(rooms[0])
        print(f"locked = {locked}")
        if 1 in locked:
            return False
        else:
            return True

        