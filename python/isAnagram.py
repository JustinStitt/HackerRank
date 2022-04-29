def isAnagram(self, s: str, t: str) -> bool:
    sd, td = ({}, {})
    for c in s:
        sd[c] = sd.get(c, 0) + 1
    for c in t:
        td[c] = td.get(c, 0) + 1
    
    smaller = td if len(sd) > len(td) else sd
    larger = sd if len(sd) > len(td) else td
    
    for c in larger.keys():
        if smaller.get(c, None) is None: return False
        if smaller[c] != larger[c]: return False
    return True

