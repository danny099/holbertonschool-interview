#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""
import sys


def formatPrint(size, myDict):
    """format de dictionary"""
    print("File size: {}".format(size))
    for key, value in sorted(statusDict.items()):
        if (value != 0):
            print("{}: {}".format(key, value))


if __name__ == "__main__":
    """init code to print the parsed data"""
    statusList = ["200", "301", "400", "401", "403", "404", "405", "500"]
    statusDict = {}
    size = 0
    i = 0
    try:
        for line in sys.stdin:
            i += 1
            if (len(line.split()) < 2):
                continue
            lineList = line.split()
            statusCode = lineList[-2]
            size = size + int(lineList[-1])
            if statusCode in statusList:
                try:
                    statusDict[statusCode] += 1
                except KeyError:
                    statusDict[statusCode] = 1
            if i % 10 == 0:
                formatPrint(size, statusDict)
        formatPrint(size, statusDict)
    except KeyboardInterrupt:
        formatPrint(size, statusDict)
        raise
