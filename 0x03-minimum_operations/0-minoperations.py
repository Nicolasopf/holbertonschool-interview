#!/usr/bin/python3
''' Get the min of operations. (like minimum comun divisor) '''


def minOperations(n):
    total = 0
    div = 2
    while n >= div:
        while n % div != 0:
            div += 1
        total += div
        n = n / div
    return total
