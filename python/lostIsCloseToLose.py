import sys
import math


def isAlpha(c):
    if ord(c) >= ord('a') and ord(c) <= ord('z'):
        return True
    if ord(c) in (ord(' '), ord('\n')):
        return True
    return False

words = set()

for line in sys.stdin:
    line = line.rstrip()
    line = line.lower()

    line = [c for c in line if isAlpha(c)]
    for word in ''.join(line).split(' '): words.add(word)

size_map = dict()

largest_word = max([len(w) for w in words])

for x in range(largest_word+1):
    size_map[x] = set()

for word in words:
    size_map[len(word)].add(word)

mispelled = dict()

for word in words:
    mispelled[word] = set()

def isOneRemoved(w):
    global size_map
    if len(w) < 1: return
    for word in size_map[len(w)-1]:
        for i in range(len(w)):
            if w[:i] + w[i+1:] == word:
                mispelled[w].add(word)
                mispelled[word].add(w)
 
def isReplaced(w):
    global mispelled
    for word in size_map[len(w)]:
        mismatch = 0
        for i in range(len(w)):
            if w[i] != word[i]: 
                mismatch += 1
        if mismatch == 1:
            mispelled[w].add(word)
            mispelled[word].add(w)

def swap(s, u, v):
    s = list(s)
    s[u], s[v] = (s[v], s[u])
    return ''.join(s)


def isTransposed(w):
    global mispelled
    for word in size_map[len(w)]:
        for i in range(len(word)-1):
            if swap(word, i, i+1) == w and word != w:
                mispelled[w].add(word)
                mispelled[word].add(w)


for word in words:
    isOneRemoved(word)
    isReplaced(word)
    isTransposed(word)


for k, v in mispelled.items():
    if len(v) > 0:
        print(f'{k}: {v}')

