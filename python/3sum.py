class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = set()
        
        # divide nums into negative, zero, and positive lists
        n, z, p = [], [], []
        for x in nums:
            if x < 0: n.append(x)
            elif x > 0: p.append(x)
            else: z.append(x)
        
        N, P = set(n), set(p)
        
        # case 1: if three 0's in z, then add (0,0,0) to res
        if len(z) > 2: res.add((0,0,0))
        
        # case 2: if one 0 in z, then find x and -x in p and n, respectively
        if len(z) > 0:
            for x in p:
                if -x in N:
                    res.add((-x, 0, x))
        
        # case 3: x + y = z where x, y are in p and z in n
        for x in range(len(p)):
            for y in range(x + 1, len(p)):
                comp = -1 * (p[x] + p[y])
                if comp in N:
                    res.add(tuple(sorted([comp, p[x], p[y]])))
        
        # case 4: x + y = z where x, y are in n and z in p
        for x in range(len(n)):
            for y in range(x + 1, len(n)):
                comp = -1 * (n[x] + n[y])
                if comp in P:
                    res.add(tuple(sorted([comp, n[x], n[y]])))
        return res
