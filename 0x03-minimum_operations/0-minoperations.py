#!/usr/bin/python3
"""
comment
"""


def minOperations(n):
    count = 0
    res = 0
    op = 0

    if n <= 0:
        return 0

    count = 1
    while count != n:
        if n % count == 0:
            res = count
            op += 1
        count = count + res
        op += 1
    return op
