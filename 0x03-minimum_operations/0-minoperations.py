#!/usr/bin/python3

'''
Method that calculates the fewest number of operations needed
to result in exactly n H characters in the file
'''


def minOperations(n):
    '''
    Min operations to get n Hs
    '''
    if n < 2:
        return 0

    result = 0
    index = 2

    while (index < n + 1):
        while n % index == 0:
            result += index
            n = n / index
        index = index + 1
    return result
