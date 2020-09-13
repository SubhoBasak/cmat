
# import math
# import os
# import random
# import re
# import sys


# def nonDivisibleSubset(k, s, n):
#     cur_max = 1
#     for i in range(n-1):
#         if n-i <= cur_max:
#             break
#         x = find_max(s[i+1], s[i+2:], [s[i]], 1, n-i-2, k)
#         if x > cur_max:
#             cur_max = x
#     return cur_max


# def find_max(cur, rest, selected, sel_len, res_len, k):
#     for m in selected:
#         if (cur+m) % k == 0:
#             return sel_len

#     selected += [cur]
#     sel_len += 1

#     if res_len:
#         return sel_len

#     cur_max = sel_len

#     for i in range(res_len):
#         print('\t\t\t\t', )
#         if res_len-i <= cur_max:
#             break
#         x = find_max(rest[i], rest[i+1:], selected, sel_len, res_len-i-1, k)
#         if x > cur_max:
#             cur_max = x
#     return cur_max


# if __name__ == '__main__':
#     n, k, s = 4, 3, [1, 7, 2, 4]
#     result = nonDivisibleSubset(k, s, n)
#     print(result)


sta