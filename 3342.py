import numpy as np

class Solution:
    def dijkstra(self, moveTime):
        n = len(moveTime)
        m = len(moveTime[0])

        dist = [[(np.inf,np.inf) for _ in range(m)] for _ in range(n)]
        dist[0][0] = (0,0)

        to_visit = [(0,0)]
        visited = set()

        dirs = [(0,1),(0,-1),(1,0),(-1,0)]

        while to_visit:
            curr_x, curr_y = to_visit[0]
            minDist = dist[curr_x][curr_y]

            for x, y in to_visit[1:]:
                if dist[x][y] < minDist:
                    curr_x = x
                    curr_y = y
                    minDist = dist[x][y]

            to_visit.remove((curr_x, curr_y))

            visited.add((curr_x, curr_y))

            for dx, dy in dirs:
                next_x, next_y = curr_x + dx, curr_y + dy
                if 0 <= next_x < n and 0 <= next_y < m:
                    _, step_cnt = dist[curr_x][curr_y]

                    new_dist = max(dist[curr_x][curr_y][0], moveTime[next_x][next_y]) + 1 + step_cnt % 2

                    if dist[next_x][next_y][0] > new_dist: 
                        dist[next_x][next_y] = (new_dist, step_cnt + 1)

                    if (next_x, next_y) not in visited and (next_x, next_y) not in to_visit:
                        to_visit.append((next_x, next_y))

        return dist[n-1][m-1][0]

    def minTimeToReach(self, moveTime ) -> int:
        return self.dijkstra(moveTime)
        


print(Solution().minTimeToReach([[0,4],[4,4]])) # 7
print(Solution().minTimeToReach([[0,0,0,0],[0,0,0,0]])) # 6
print(Solution().minTimeToReach([[0,1],[1,2]])) # 4
