#!/usr/bin/python3

from sys import stdin
from keyword import iskeyword

if __name__ == "__main__":
    a = stdin.readline().rstrip()
    if a.islower():
        print("a")
    else:
        print("A")