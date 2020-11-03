#!/usr/bin/python

from sys import stdin
from keyword import iskeyword

if __name__ == "__main__":
    num_list = []
    n = int(input())
    for i in range(n):
        num_list.append(list(map(int,input().split())))

    ret = False
    for i in range(0, n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if (num_list[k][1] - num_list[i][1]) * (num_list[j][0] - num_list[i][0]) \
                    == (num_list[j][1] - num_list[i][1]) * (num_list[k][0] - num_list[i][0]):
                    ret = True
                    break
    if ret:
        ans = 'Yes'
    else:
        ans = 'No'
    print(ans)

