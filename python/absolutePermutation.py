# link = https://www.hackerrank.com/challenges/absolute-permutation/problem

import math
import os
import random
import re
import sys

# Complete the absolutePermutation function below.
def absolutePermutation(n, k):
    no = [-1]
    if k == 0: return [x for x in range(1,n+1)]    
    if n & 1: return no
    
    res = [0] * n
    for x in range(n):
        bad_options = 0
        if (x-k < 0) or (x-k >= 0 and res[x-k] != 0): bad_options += 1
        if (x+k > n-1) or (x+k < n and res[x+k] != 0): bad_options += 1
        if bad_options == 2: return no
        if (x-k >= 0 and res[x-k] == 0):
            res[x-k] = x + 1
        elif (x+k < n and res[x+k] == 0):
            res[x+k] = x + 1
        else:
            return no
    return res
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        result = absolutePermutation(n, k)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
