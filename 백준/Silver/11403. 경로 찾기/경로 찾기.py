# -*- coding: utf-8 -*-
"""
Created on Fri Jan 10 21:14:05 2020

@author: Meda
"""

import sys
sys.setrecursionlimit(1000000000) 

def chk(n, m):
    global visitCheck
    visitCheck[n] = 1
    if(node[n][m]):
        return 1;
    for i in range(N):
        if(node[n][i] == 1 and visitCheck[i] == 0):
            if(chk(i, m)):
                return 1;
    return 0;

N = int(input())
node = []

for i in range(N):
    node.append(list(map(int, input().split(" "))))

for n in range(N):
    for m in range(N):
        visitCheck = [0 for x in range(N)]
        print(str(chk(n, m)) + " ", end="")
    print("")