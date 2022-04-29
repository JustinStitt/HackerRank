def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    d = dict()
    
    for word in strs:
        sorted_word = ''.join(sorted(word))
        if d.get(sorted_word, None) is None:
            d[sorted_word] = list([word])
        else:
            d[sorted_word].append(word)
    
    return d.values()

