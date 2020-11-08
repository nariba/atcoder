#!/usr/bin/python

from sys import stdin
from keyword import iskeyword

if __name__ == "__main__":
    n = input()
    n_list = list(n)

    n_sum = 0
    finished = False
    for i in n_list:
        n_sum += int(i)
    if n_sum % 3 == 0:
        finished = True
        print(0)
    else:
        sum_remain = n_sum % 3
        # print('sum_remain:', sum_remain)
        for i in range(0, len(n_list)):
            for j in range(0, len(n_list)-i): # digit
                for k in range(0, len(n_list)): # start point
                    tmp = 0
                    for l in range(0, j):
                        # print(i, j, k, l)
                        tmp += int(n_list[k+l])
                    # print('tmp', tmp)
                    if int(tmp) % 3 == sum_remain:
                        print(j)
                        finished = True
                    if finished:
                        break
                if finished:
                    break
            if finished:
                break
    if finished == False:
        print(-1)
