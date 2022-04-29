def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    buckets = [set() for _ in nums]
    freq_map = dict()
    for num in nums:
        freq_map[num] = freq_map.get(num, 0) + 1
    
    for (i, v) in freq_map.items():
        buckets[v-1].add(i)
    
    buckets = [x for x in buckets if len(x)]
    ret = []
    while len(ret) < k:
        ret.extend(list(buckets[-1]))
        del buckets[-1]
    
    return ret
    
