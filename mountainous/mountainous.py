# An array is Mountainous if it is strictly increasing, then strictly decreasing. Note that Mountainous arrays must therefore be of length three or greater.

# A Subarray is defined as an array that can be attained by deleting some prefix and suffix (possibly empty) from the original array.

# An array or subarray is a Palindrome if it is the same sequence forwards and backwards.

# Given an array of integers, compute the length of the longest Subarray that is both Mountainous and a Palindrome.

# Input
# The first line of input contains an integer  which is the number of integers in the array.

# Each of the next lines contains a single integer 
# These values form the array. They are given in order.

# Output
# Output a single integer, which is the length of the longest Mountainous Palindromic Subarray, or 
# -1 if no such array exists.

cases = int(input())
# print(cases)
# We set count to default -1 for the case where no mountainous subarray can be found
count = -1
arr = []
for i in range(cases):
    n = int(input())
    arr.append(n)
# print(arr)
# minimum length has to be 3 for a mountainous subarray, so the idea here is the branch out from the middle element and
# check the left and right side of the middle elements to determine mountainous subarray
for i in range(cases):
    offset = 1
    while i - offset >= 0 and i + offset < cases:
        # We check here if the left and right side of the middle element is equal, and check if the element at (i-offset) index is
        # greater or equal to the element directly on its direct right, if so,
        # we break out of the loop as it is not a mountainous subarray
        if (arr[i - offset] != arr[i + offset]) or (arr[i-offset] >= arr[i-offset+1]):
            break
        else:
            offset += 1
        # offset would be the difference from the current index to the middle element, hence we take (offset * 2) -1
        # to get the length of the subarray as we double counted the middle element when we multiplied offset by 2.
        count = max(count, offset * 2 - 1)
print(count)