class Solution:
    def destCity(self, paths ) -> str:
        pile = set()
        removed = set()
        for city1, city2 in paths:
            if city1 in pile:
                pile.remove(city1)
            removed.add(city1)
            if city2 not in removed:
                pile.add(city2)
            # print(pile)
        return pile.pop()
    
print(Solution().destCity([["B","C"],["D","B"],["C","A"]]))