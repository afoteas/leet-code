class Solution:
    def fillDictBoard(self, dict_board: dict, pos: str, i: int, j:int, val:str) -> bool:
        if pos in dict_board:
            if val in dict_board[pos] and val != ".":
                return False
            else:
                dict_board[pos].append(val)
        else:
            dict_board[pos] = [val]
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        dict_board = {}
        for i in range(0,9):
            for j in range(0,9):
                if not self.fillDictBoard(dict_board, f"l{i}", i, j, board[i][j]):
                    return False
                if not self.fillDictBoard(dict_board, f"r{j}", i, j, board[i][j]):
                    return False
                if i < 3 and j < 3:
                    if not self.fillDictBoard(dict_board, "b11", i, j, board[i][j]):
                        return False
                if i > 2 and i < 6 and j < 3:
                    if not self.fillDictBoard(dict_board,"b12",i, j, board[i][j]):
                        return False
                if i > 5 and i < 9 and j < 3:
                    if not self.fillDictBoard(dict_board,"b13",i,j, board[i][j]):
                        return False
                if i < 3 and j > 2 and j < 6:
                    if not self.fillDictBoard(dict_board,"b21",i,j, board[i][j]):
                        return False
                if i > 2 and i < 6 and j > 2 and j < 6:
                    if not self.fillDictBoard(dict_board,"b22",i,j, board[i][j]):
                        return False
                if i > 5 and i < 9 and j > 2 and j < 6:
                    if not self.fillDictBoard(dict_board,"b23",i,j, board[i][j]):
                        return False
                if i < 3 and j > 5 and j < 9:
                    if not self.fillDictBoard(dict_board,"b31",i,j, board[i][j]):
                        return False
                if i > 2 and i < 6 and j > 5 and j < 9:
                    if not self.fillDictBoard(dict_board,"b32",i,j, board[i][j]):
                        return False
                if i > 5 and i < 9 and j > 5 and j < 9:
                    if not self.fillDictBoard(dict_board,"b33",i,j, board[i][j]):
                        return False
        return True
                