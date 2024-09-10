class Solution:
    def solveNQueensSlow(self, n: int) -> List[List[str]]:
        board = [["."]*n for _ in range(n)]
        self.ret = []

        def is_safe(board, row, col, N):
            # Check this column on upper side
            for i in range(row):
                if board[i][col] == "Q":
                    return False

            # Check upper diagonal on left side
            for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
                if board[i][j] == "Q":
                    return False

            # Check upper diagonal on right side
            for i, j in zip(range(row, -1, -1), range(col, N)):
                if board[i][j] == "Q":
                    return False

            return True

        def solve_n_queens_util(board, row, N):
            if row >= N:
                self.ret.append(["".join(c) for c in board])
                return

            for col in range(N):
                if is_safe(board, row, col, N):
                    board[row][col] = "Q"  # Place queen

                    # Recur to place the rest of the queens
                    solve_n_queens_util(board, row + 1, N)

                    # Backtrack
                    board[row][col] = "."  # Remove queen
        
        solve_n_queens_util(board, 0, n)
        return self.ret


    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        cols = [0] * n
        diags_l = [0] * (2*n - 1)
        diags_r = [0] * (2*n - 1)
        curr_config = []

        def backtrack(row:int):
            if row == n:
                result.append(["".join(['Q' if c == curr_config[r] else '.' for c in range(n)]) for r in range(n)])
                return
            
            for i in range(n):
                if cols[i] or diags_l[row + i] or diags_r[row + n - i - 1]:
                    continue

                cols[i] = 1
                diags_l[row + i] = 1
                diags_r[row + n - i - 1] = 1
                curr_config.append(i)

                backtrack(row + 1)

                cols[i] = 0
                diags_l[row + i] = 0
                diags_r[row + n - i - 1] = 0
                curr_config.pop()
            
        backtrack(0)

        return result
        