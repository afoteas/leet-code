class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
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


        