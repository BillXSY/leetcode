class Solution:
    def findRedundantConnection(self, edges) :
        n = len(edges)
        parents = list(range(n+1))

        def find(node):
            if parents[node] != node:
                parents[node] = find(parents[node])
            return parents[node]

        def union(node1, node2):
            parents[find(node1)] = find(parents[node2])
            

        for node1, node2 in edges:
            if find(node1) != find(node2):
                union(node1, node2)
            else:
                return [node1, node2]
            
        return []