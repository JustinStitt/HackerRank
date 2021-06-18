class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        # store val:idx dict for list1, then check list2 and keep runnning min-sum
        lookup = {val:idx for idx, val in enumerate(list1)}
        
        smallest = [len(list1) + len(list2), []]
        
        for idx, val in enumerate(list2):
            if val not in lookup: continue
            index_sum = idx + lookup[val]
            if index_sum < smallest[0]:
                smallest = [index_sum, [val]]
            elif index_sum == smallest[0]:
                smallest[1].append(val)
        return smallest[1]
