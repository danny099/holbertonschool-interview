#!/usr/bin/python3

""" Lockboxes """


def canUnlockAll(boxes):
    """
        Lockboxes
    """
    if not boxes:
        return False

    opened = {}
    queue = [0]

    while queue:
        boxNumber = queue.pop(0)
        opened[boxNumber] = 1
        for key in boxes[boxNumber]:
            if key >= 0 and key < len(boxes) and not opened.get(key)\
                    and (key not in queue):
                queue.append(key)

    return True if (len(opened) == len(boxes)) else False
