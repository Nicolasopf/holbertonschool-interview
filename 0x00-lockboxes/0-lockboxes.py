#!/usr/bin/python3
''' Check if all boxes can be openned '''


def canUnlockAll(boxes):
    ''' Return True if can unlock all, False if not '''
    nums = set(boxes[0])
    opened = {0}
    counter = 0

    while counter < len(opened):
        counter = len(opened)
        for num in nums:
            opened.update(boxes[num])
        nums.update(opened)

    for num in range(len(boxes)):
        if num not in opened:
            return False

    return True
