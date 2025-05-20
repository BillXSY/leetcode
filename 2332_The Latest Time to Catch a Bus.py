
class Solution:
    def latestTimeCatchTheBus(self, buses, passengers, capacity: int) -> int:
        buses.sort()
        passengers.sort()
        passengers_cnt = len(passengers)
        p_idx = 0

        for bus in buses:
            remain_cap = capacity
            for cnt in range(capacity):
                if p_idx < passengers_cnt and passengers[p_idx] <= bus:
                    p_idx += 1
                    remain_cap -= 1
            else:
                break
        
        p_idx -= 1

        # 如果最后一班车坐满了，则需要在最后一班车的最后一个人之前到达
        # 如果最后一班车没坐满，只需要在发车之前到就行
        if remain_cap > 0:
            latest_time = buses[-1]
        elif remain_cap == 0:
            latest_time = passengers[p_idx]

        while p_idx >= 0:
            if latest_time == passengers[p_idx]:
                latest_time -= 1
                p_idx -= 1
            else:
                break
            
        return latest_time
        
# print(Solution().latestTimeCatchTheBus([3], [2,3],2))
print(Solution().latestTimeCatchTheBus([2], [2], 2))

# print(Solution().latestTimeCatchTheBus([10, 20], [2,17,18,19],2))
# print(Solution().latestTimeCatchTheBus([30, 10, 20], [19,13,26,4,25,11,21],2))
