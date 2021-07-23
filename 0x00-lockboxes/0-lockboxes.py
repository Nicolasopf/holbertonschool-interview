#!/usr/bin/python3
''' Check if all boxes can be openned '''


def canUnlockAll(boxes):
    ''' Return True if can unlock all, False if not '''
    nums = set(boxes[0])
    opened = {0}
    counter = 0
    boxes_len = len(boxes)

    while counter < len(opened):
        counter = len(opened)
        for num in nums:
            try:
                opened.update(boxes[num])
            except:
                continue
        nums.update(opened)

    if len(opened) != len(boxes):
        return False

    return True
