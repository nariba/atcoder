#!/usr/bin/python

from sys import stdin
from keyword import iskeyword

num_list = [112, 128, 136, 144, 152, 168, 176, 184, 192, 216,
            224, 232, 248, 256, 264, 272, 288, 296, 312, 328,
            336, 344, 352, 368, 376, 384, 392, 416, 424, 432,
            448, 456, 464, 472, 488, 496, 512, 528, 536, 544,
            552, 568, 576, 584, 592, 616, 624, 632, 648, 656,
            664, 672, 688, 696, 712, 728, 736, 744, 752, 768,
            776, 784, 792, 816, 824, 832, 848, 856, 864, 872,
            888, 896, 912, 928, 936, 944, 952, 968, 976, 984, 992]

def is_divided_by8(n):
    if n % 8 == 0:
        ret = True
    else:
        ret = False
    return ret

def contains_number(s, n):
    dict = {1: 0,
            2: 0,
            3: 0,
            4: 0,
            5: 0,
            6: 0,
            7: 0,
            8: 0,
            9: 0}
    for i in range(1, 10):
        dict[i] = n.count(str(i))

    ret = True
    for i in range(1, 10):
        if s.count(str(i)) < dict[i]:
            ret = False
    return ret

if __name__ == "__main__":
    n = input()

    if int(n) < 100:
        n_rev_list = list(reversed(n))
        n_rev = ''.join(n_rev_list)
        ret = is_divided_by8(int(n)) or is_divided_by8(int(n_rev))
    else:
        ret = False
        for i in num_list:
            ret = contains_number(n, str(i))
            if ret:
                break
        
    if ret:
        ans = 'Yes'
    else:
        ans = 'No'
    print(ans)
