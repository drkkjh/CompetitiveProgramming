idx1 = 0
idx2 = 0
count = 0
set1 = set()
string = input()
N = len(string)

while idx1 < N:
    idx2 = string.find(string[idx1], idx1 + 1)
    if idx2 != -1:  
        set1 = set(string[idx1 + 1: idx2])  
        count += len(set1)
        idx1 += 1
    else:
        set1 = set(string[idx1 + 1:])
        count += len(set1)
        idx1 += 1

print(count)    