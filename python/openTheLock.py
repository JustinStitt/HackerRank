class Solution:
    def getNeighbours(self, vertex):
        # convert vertex to more workable type
        # '0000' -> ['0','0','0','0']
        neighbours = []
        vertex = [x for x in vertex]
        for i in range(len(vertex)):
            # simulate increase
            tmp = vertex[::]
            if tmp[i] == '9': tmp[i] = '0'
            else: tmp[i] = str(int(tmp[i]) + 1)
            neighbours.append(''.join(tmp))
            tmp = vertex[::]
            # simulate decrease
            if tmp[i] == '0': tmp[i] = '9'
            else: tmp[i] = str(int(tmp[i]) - 1)
            neighbours.append(''.join(tmp))
        return neighbours
    
    def bfs(self, start, target, bad):
        if start in bad: return -1 # edge case
        Q = [start]
        visited = set()
        dist = 0
        
        while len(Q) > 0:
            for _ in range(len(Q)):
                v = Q.pop(0) # pop front
                if v == target: return dist
                for neighbour in self.getNeighbours(v):
                    if neighbour in visited or neighbour in bad:
                        continue
                    Q.append(neighbour)
                    visited.add(neighbour)
            dist += 1
        return -1
        
    def openLock(self, deadends: List[str], target: str) -> int:
        start = '0000'
        bad = set([x for x in deadends])
        return self.bfs(start, target, bad)
