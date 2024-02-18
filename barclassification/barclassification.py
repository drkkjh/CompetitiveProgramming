totalOnes = 0
maxRow = 0
maxCol = 0
arr = []
arrT = []
N = int(input())
for i in range(N):
    row = [int(x) for x in input()]
    arr.append(row)
# print(arr)
for i in range(N):
    transposedRow = []
    for j in range(N):
        transposedRow.append(arr[j][i])
    arrT.append(transposedRow)

# print(arrT)

totalOnes = sum(sum(x) for x in arr)    

maxRow = max(sum(x) for x in arr)

maxCol = max(sum(x) for x in arrT)

# print(total, maxRow, maxCol)

verticalCheck = (N - maxCol) + (totalOnes - maxCol) <= N

horizontalCheck = (N - maxRow) +(totalOnes - maxRow) <= N

if verticalCheck and horizontalCheck:
    print("+")
elif verticalCheck:
    print("|")
else:
    print("-")