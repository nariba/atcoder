#!/bin/env python3

def main():
    a = int(input())
    b, c = map(int, input().split())
    s = input()
    print(str(a + b + c) + ' ' + s)

if __name__ == '__main__':
    main()