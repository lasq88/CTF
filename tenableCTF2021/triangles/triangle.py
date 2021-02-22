import itertools
import math


def heron(a,b,c):  
    s = (a + b + c) / 2   
    area = (s*(s-a) * (s-b)*(s-c)) ** 0.5        
    return area

def distance3d(x1,x2,y1,y2,z1,z2):    
    a=(x1-x2)**2+(y1-y2)**2 + (z1-z2)**2
    d= a ** 0.5  
    return d  

def areatriangle3d(x,y,z):  
    a=distance3d(y[0],z[0],y[1],z[1],y[2],z[2])  
    b=distance3d(x[0],z[0],x[1],z[1],x[2],z[2]) 
    c=distance3d(x[0],y[0],x[1],y[1],x[2],y[2])
    A = heron(a,b,c)  
    return A


# points is a list of 3D points
# ie: [[2, 9, -15], [0, 33, -20], ...]

def FindLargestTriangleArea(points):
    combinations = list(itertools.combinations(points,3))
    area = 0
    for combination in combinations:
        result = areatriangle3d(combination[0],combination[1],combination[2])
        if result > area:
            area = result
    return area

# Reading space delimited points from stdin
# and building list of 3D points
points_data = raw_input()
points = []
for point in points_data.split(' '):
  point_xyz = point.split(',')
  points.append([int(point_xyz[0]), int(point_xyz[1]), int(point_xyz[2])])

# Compute Largest Triangle and Print Area rounded to nearest whole number
area = FindLargestTriangleArea(points)
print int(round(area))