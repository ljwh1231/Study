#해시
#섬의 갯수

import sys
sys.stdin = open("input.txt", "rt")

w, h = map(int, input().split())
land = dict()
cnt = 0

while h != 0:
    for i in range(h):

        n = input().split()
        h -= 1

        for j in range(w):
            for k in n:
                land[j] = k

print(land)





