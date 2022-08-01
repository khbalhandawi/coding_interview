#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'processLogs' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING_ARRAY logs
#  2. INTEGER threshold
#

def processLogs(logs, threshold):
    # Write your code here
    """
    we have some logs
    usr1 usr2 amount
    """
    usrs = {}
    
    for log in logs:
        log_i = log.split(" ")
        if not log_i[0] in usrs:
            usrs[log_i[0]] = 1
        else:
            usrs[log_i[0]] += 1
        
        if log_i[0] != log_i[1]:  
            if not log_i[1] in usrs:
                usrs[log_i[1]] = 1
            else:
                usrs[log_i[1]] += 1
    
    filtered_usrs = {}
    for key,value in usrs.items():
        if value >= threshold:
            filtered_usrs[key] = value
        
                
    return sorted(filtered_usrs)
        

if __name__ == '__main__':
    fptr = open('out.txt', 'w')

    logs_count = int(input().strip())

    logs = []

    for _ in range(logs_count):
        logs_item = input()
        logs.append(logs_item)

    threshold = int(input().strip())

    result = processLogs(logs, threshold)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
