#!/usr/bin/python3

"""
Function to unlocked box of lists
"""


def canUnlockAll(boxes):
    box_unloked = [0]

    for box_index, in_box in enumerate(boxes):
        if not in_box:
            continue

        for value in in_box:
            if value < len(boxes) and value not in box_unloked:
                if value != box_index:
                    box_unloked.append(value)

    if len(box_unloked) == len(boxes):
        return True
    return False