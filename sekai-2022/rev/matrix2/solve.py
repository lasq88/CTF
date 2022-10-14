import numpy
import matlab.engine
from z3 import *

engine = matlab.engine.start_matlab()
s = Solver()
flag = [BitVec("flag%s" % i, 32) for i in range(16)]

A = [i ^ 42 for i in flag]
B = numpy.array([A[i:i + 4] for i in range(0, len(A), 4)])
X = [list(map(int, i)) for i in engine.magic(4)]
Y = [list(map(int, i)) for i in engine.pascal(4)]
C = [[None for _ in range(len(X))] for _ in range(len(X))]
for i in range(len(X)):
    for j in range(len(X[i])):
        C[i][j] = X[i][j] + Y[i][j]

C = numpy.array(C)


correct = (numpy.matmul(C,numpy.rot90(numpy.matrix.transpose(B), 1337)))
encrypted = [[2094, 2962, 1014, 2102], [2172, 3955, 1174, 3266], [3186, 4188, 1462, 3936], [3583, 5995, 1859, 5150]]

s.add([flag[i] < 127 for i in range(16)])
s.add([flag[i] > 0 for i in range(16)])

for i in range(4):
    for j in range(4):
        s.add(correct[i][j] == encrypted[i][j])

s.check()
m = s.model()

print("SEKAI{"+"".join([chr(m.eval(flag[i]).as_long()) for i in range(16)])+"}")