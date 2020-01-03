#최소비용 구하기

import sys
#sys.stdin = open("input.txt", "rt")

n = int(input()) #도시개수
m = int(input()) #버스개수
plist = [[] for _ in range(n+1)] #경로리스트
cnt = 0 #최소비용

for _ in range(m):
    start, end, p = map(int, input().split())
    plist[start].append([end,p])

s, e = map(int, input().split()) #출발, 도착지점

for i in range(s, e+1): #다익스트라
    target = plist[i][0][1]
    for j in range(1,len(plist[i])):
        cnt = plist[i][j][1]

        if target > cnt:
            cnt
        else:
            continue

print(cnt)

