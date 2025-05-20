class Solution:
    def finalPositionOfSnake(self, n: int, commands ) -> int:
        position = [0, 0]

        for com in commands:
            if com == "UP":
                position[0] -= 1
            elif com == "RIGHT":
                position[1] += 1
            elif com == "DOWN":
                position[0] += 1
            elif com == "LEFT":
                position[1] -= 1
        
        return position[0] * n + position[1]
        