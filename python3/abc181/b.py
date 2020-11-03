#!/usr/bin/python

from sys import stdin
from keyword import iskeyword

if __name__ == "__main__":
    num_list = []
    n = int(input())
    for i in range(n):
        num_list.append(list(map(int,input().split())))

    s = 0
    for i in num_list:
        n = i[1] - i[0] + 1
        s += int(n * (i[0] + i[1]) / 2)
    print(s)

