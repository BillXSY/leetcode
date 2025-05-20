class Solution:
    def get_rook_pos(self, position, obstacle=None):
        if not obstacle:
            # rook_pos = [(position[0], i) for i in range(1,9)] + [(i, position[1]) for i in range(1,9)]
            rook_pos = []
            for i, j in [(0,1),(0,-1),(-1,0),(1,0)]:
                curr_pos = tuple(position)
                while curr_pos[0] >= 1 and curr_pos[1] >= 1 and curr_pos[0] <= 8 and curr_pos[1] <= 8:
                    rook_pos.append(curr_pos)
                    curr_pos = (curr_pos[0] + i, curr_pos[1] + j)            
            return set(rook_pos)
        else:
            block_cnt = 0
            delta = (- position[0] + obstacle[0], - position[1] + obstacle[1])
            if delta[0] == 0 or delta[1] == 0:
                step_cnt = abs(sum(delta))
                i, j = delta[0] / step_cnt, delta[1] / step_cnt
                max_step_cnt = 0
                curr_pos = tuple(position)
                while curr_pos[0] >= 1 and curr_pos[1] >= 1 and curr_pos[0] <= 8 and curr_pos[1] <= 8:
                    max_step_cnt += 1
                    curr_pos = (curr_pos[0] + i, curr_pos[1] + j)      

                block_cnt = max_step_cnt - step_cnt
            print(f'rook: {block_cnt=}')
            return block_cnt
            


    def get_bishop_pos(self, position, obstacle=None):
        if not obstacle:
            bishop_pos = []
            for i, j in [(1,1),(1,-1),(-1,1),(-1,-1)]:
                curr_pos = tuple(position)
                while curr_pos[0] >= 1 and curr_pos[1] >= 1 and curr_pos[0] <= 8 and curr_pos[1] <= 8:
                    bishop_pos.append(curr_pos)
                    curr_pos = (curr_pos[0] + i, curr_pos[1] + j)
            return set(bishop_pos)
        else:
            block_cnt = 0
            delta = (- position[0] + obstacle[0], - position[1] + obstacle[1])
            if abs(delta[0]) == abs(delta[1]):
                step_cnt = abs(delta[0])
                i, j = delta[0] / step_cnt, delta[1] / step_cnt
                max_step_cnt = 0
                curr_pos = tuple(position)
                while curr_pos[0] >= 1 and curr_pos[1] >= 1 and curr_pos[0] <= 8 and curr_pos[1] <= 8:
                    max_step_cnt += 1
                    curr_pos = (curr_pos[0] + i, curr_pos[1] + j)      
                block_cnt = max_step_cnt - step_cnt 
            print(f'bishop: {block_cnt=}')
            return block_cnt

    def get_queen_pos(self, position, obstacle=None):
        if not obstacle:
            return self.get_rook_pos(position).union(self.get_bishop_pos(position))
        else:
            return self.get_rook_pos(position, obstacle) + self.get_bishop_pos(position, obstacle)

    def get_dist(self, pos1, pos2):
        delta = (- pos1[0] + pos2[0], - pos1[1] + pos2[1])
        if abs(delta[0]) == abs(delta[1]):
            dist = abs(delta[0])
        elif delta[0] == 0 or delta[1] == 0:
            dist = abs(sum(delta))           

        return dist

    def countCombinations(self, pieces, positions) -> int:
        n = len(pieces)
        piece_positions = []
        for piece, pos in zip(pieces, positions):
            # print(f'{piece} at {pos}')
            if piece == 'rook':
                piece_positions.append(self.get_rook_pos(pos))
            elif piece == 'bishop':
                piece_positions.append(self.get_bishop_pos(pos))
            elif piece == 'queen':
                piece_positions.append(self.get_queen_pos(pos))
            else:
                raise Exception(f'{piece} is not leagle')

        if n == 1:
            return len(piece_positions[0])

        tot_combination = 1
        illeagle_cnt = 0

        for i in range(n):
            tot_combination *= len(piece_positions[i])
            print(f'{tot_combination=}')
            for j in range(i+1, n):
                print(f'{i=}, {j=}')
                conflict_positions = piece_positions[i].intersection(piece_positions[j])
                
                print(f'{conflict_positions=}')

                if not len(conflict_positions):
                    continue

                for cpos in conflict_positions:
                    print(f'current comflict position: {cpos}')
                    # check which piece is farther to the conflit position
                    dist_i = self.get_dist(positions[i], cpos)
                    dist_j = self.get_dist(positions[j], cpos)

                    print(f'{dist_i=}, {dist_j=}')

                    if dist_i == dist_j:
                        illeagle_cnt += 1
                    else:
                        slower_idx = i if dist_i > dist_j else j

                        if pieces[slower_idx] == 'rook':
                            illeagle_cnt += self.get_rook_pos(positions[slower_idx], cpos)
                        elif pieces[slower_idx] == 'bishop':
                            illeagle_cnt += self.get_bishop_pos(positions[slower_idx], cpos)
                        elif pieces[slower_idx] == 'queen':
                            illeagle_cnt += self.get_queen_pos(positions[slower_idx], cpos)

        print(f'{illeagle_cnt=}')
        return tot_combination - illeagle_cnt






# print(Solution().get_rook_pos([1,1]))
# print(Solution().get_bishop_pos([4,3]))
# print(Solution().get_queen_pos_cnt([1,1]))

# print(Solution().countCombinations(pieces = ["bishop"], positions = [[4,3]]))
# print(Solution().countCombinations(pieces = ["queen"], positions = [[1,1]]))

# print(Solution().countCombinations(pieces = ["queen","bishop"], positions = [[5,7],[3,4]]))
# print(Solution().countCombinations(pieces = ["rook","rook"], positions = [[1,1],[8,8]]))
print(Solution().countCombinations(pieces = ["bishop","rook"], positions = [[8,5],[7,7]]))
