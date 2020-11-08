#!/usr/bin/python

from sys import stdin
from keyword import iskeyword

if __name__ == "__main__":
    a, b = input().split()
    max_follow = 2 * int(a) + 100
    print(max_follow - int(b))

