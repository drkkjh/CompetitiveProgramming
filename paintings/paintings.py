#  Input
#  The first line of input contains an integer T denoting the number of test cases that follow.
#
#  The first line of each test case contains one integer N where N is the number of colors/vertical strips 
#  Catherine wants her painting to have. On the second line are 
#  colors ordered in (strictly) decreasing order of preference, where each color is a string of between 1 and 20 lowercase 
#  lowercase letters (a–z). The third line contains a positive integer M
#  indicating the number of pairs of colors that follow. Each of the next 
#  lines contains two space-separated colors Ci and Cj
#  such that Catherine does not like seeing color Ci next to color Cj. No pair of colors will appear on more than one line.
                
cases = int(input())
for i in range(cases):
    colors = []
    visited = set()
    dictionary = {}
    validCount = 0
    current = []
    numColors = int(input())
    inputColors = input().split()
    for i in range(len(inputColors)):
        colors.append(inputColors[i])
    numPairs = int(input())
    for i in range(numPairs):
        colorPairings = input().split()
        color1 = colorPairings[0]
        color2 = colorPairings[1]
        if color1 not in dictionary:
            dictionary[color1] = set()
        if color2 not in dictionary:
            dictionary[color2] = set()
        dictionary[color1].add(color2)
        dictionary[color2].add(color1)

    def backtrack(colors, prevColour, count):
        # Base case of recursion    
        if (count == len(colors)):
            global validCount
            validCount += 1
            return
        for color in colors:
            if (color not in visited):
                if (color in dictionary) and (prevColour in dictionary[color]):
                    continue
                visited.add(color)
                if (validCount == 0):
                    current.append(color)
                backtrack(colors, color, count + 1)
                visited.remove(color)
                if (validCount == 0):
                    current.remove(color)
    # print(dict)
    backtrack(colors, '', 0)
    print(validCount)
    print(*current)
