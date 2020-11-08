#!/usr/bin/python

from sys import stdin
from keyword import iskeyword

def gcd_num(num_list, n):
    ret = 0
    for i in num_list:
        if i % n == 0:
            ret += 1
    # print('n:' + str(n) + 'gcd_i:' + str(ret))
    return ret

if __name__ == "__main__":
    num_list = []
    n = int(input())
    a_list = list(map(int, input().split()))

    ret_gcd = 0
    for i in range(2, max(a_list)+1):
        gcd_i = gcd_num(a_list, i)
        if ret_gcd < gcd_i:
            ret = i
            ret_gcd = gcd_i
    print(ret)

