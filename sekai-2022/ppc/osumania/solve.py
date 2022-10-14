import sys
n = sys.stdin.readline()

previous = [" "]*4
c = 0

for l in range(int(n)):
    line = sys.stdin.readline()
    for i in range(4):
        if line[i+1] == "-" and (previous[i] == " " or previous[i] == "-"):
            c = c +1
    previous = line[1:5]

print(c)