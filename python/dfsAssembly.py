from collections import defaultdict
dump = open('./dump.nasm.txt')

def where_next(amnt, _from):
    return _from + amnt * 106

def calculate_paths(curr):
    NORTH = -51; EAST = 1; SOUTH = 51; WEST = -1
    dirs = {1: NORTH, 2: WEST, 3: EAST, 4: SOUTH}
    paths = []
    for (_dir, amnt) in dirs.items():
        paths.append([_dir, where_next(amnt, curr)])
    return paths

kSTARTING_NODE = 4313904
GOAL = 4229952
mappings = dict() 

for line in dump.readlines():
    line = line.strip()
    if 'nop' in line: continue 
    colon_idx = line.find(':')
    key = line[:colon_idx]
    key = int(key, 16)
    value = line[colon_idx+1:]
    value = value.strip()
    if key == GOAL:
        mappings[key] = 1 # goal state
        print('there exists a goal!')
    elif 'xor' in value: 
        mappings[key] = 0 # dead end
    elif 'BYTE' in value:
        mappings[key] = calculate_paths(key)
    else:
        mappings[key] = 0

solved = False
def dfs(address, visited, path = []):
    global solved
    if address in visited: return
    visited.add(address)
    if mappings[address] == 1: solved = True; return path
    if mappings[address] == 0: return
    for (direction, neighbour) in mappings[address]:
        ans = dfs(neighbour, visited, path[:]+[direction])
        if ans != None and len(ans) > 0: return ans

_visited = set()
answer = dfs(kSTARTING_NODE, _visited)
print(f'{solved=}')
#print(answer)
fa = ''
for e in answer: fa += str(e)
print(fa)
