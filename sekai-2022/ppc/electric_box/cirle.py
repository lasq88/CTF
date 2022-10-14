import math

x1 = 5000
y1 = 250
r1 = 100

x2 = 5000
y2 = 150

d = math.sqrt(math.pow(x1 - x2, 2) + math.pow(y1 - y2, 2)) - r1
print(d > 0)