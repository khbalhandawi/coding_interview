#!/bin/python3

import math
import os
import random
import re
import sys

from pyparsing import empty



#
# Complete the 'countGroups' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING_ARRAY related as parameter.
#

def countGroups(related):
    # Write your code here
    
    people = set(range(len(related)))
    groups = set()
    print(len(related))
    while not people:
        print(row)
        for j,value in enumerate(list(row[:])):
            if i == j:
                continue
            if value == '1':
                groups.add((i,j))
                people.discard(i)
                people.discard(j)

                
                
    return len(groups)


if __name__ == '__main__':
    fptr = open('out.txt', 'w')

    # related_count = int(input().strip())

    # related = []

    # for _ in range(related_count):
    #     related_item = input()
    #     related.append(related_item)

    related = [
        '11001101',
        '11101101',
        '10001101',
        '01011001',
        '00001000',
        '00000100',
        '00000010',
        '00000001',
    ]

    result = countGroups(related)

    fptr.write(str(result) + '\n')

    fptr.close()
