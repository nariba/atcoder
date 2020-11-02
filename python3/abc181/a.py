#!/usr/bin/python

from sys import stdin
from keyword import iskeyword

if __name__ == "__main__":
    n = input()
    if int(n) % 2 == 0:
        ret = 'White'
    else:
        ret = 'Black'
    print(ret)

