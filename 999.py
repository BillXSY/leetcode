
class Solution:
    def numRookCaptures(self, board) -> int:
        available_p_cnt = 0

        p_pos, b_pos = [], []
        for i, row in enumerate(board):
            for j, piece in enumerate(row):
                if piece == 'p':
                    p_pos.append((i,j))
                elif piece == 'R':
                    R_pos = (i, j)
                elif piece == 'B':
                    b_pos.append((i, j))

        for direct in [[0,1],[0,-1],[1,0],[-1,0]]:
            for step in range(8):
                targ_pos = (R_pos[0] + step * direct[0], R_pos[1] + step * direct[1])
                if targ_pos in b_pos:
                    break
                if targ_pos in p_pos:
                    available_p_cnt += 1
                    break

        return available_p_cnt

print(Solution().numRookCaptures([[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]))
        