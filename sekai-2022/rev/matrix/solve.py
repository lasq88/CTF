from z3 import *

s = Solver()
flag = [BitVec("flag%s" % i, 8) for i in range(36)]

length = 6

def transform(var0, var1):
    var2 = []
    for i in range(var1):
        var2.append([])
        for j in range(var1):
            var2[i].append(None)
    for var3 in range(var1*var1):
        var2[var3 // var1][var3 % var1] = var0[var3]
    return var2

def encrypt(var0, var1):
    var2 = [None]*12
    var3 = 5
    var4 = 6
    for var5 in range(0,12,2):
        var2[var5] = var0[var3]
        var3 = var3 - 1
        var2[var5 + 1] = var0[var4]
        var4 = var4 + 1
    for var5 in range(12):
        var2[var5] = var2[var5] ^ var1
    return var2

def getArray(var0, var1, var2):
    var3 = [None]*12
    var4 = 0
    for var5 in range(6):
        var3[var4] = var0[var1][var5]
        var4 = var4 + 1
    for var5 in range(6):
        var3[var4] = var0[var2][6 - 1 - var5]
        var4 = var4 + 1
    return var3


var1 = transform(flag, length)

for var2 in range(4):
    for var3 in range(length - 2 * var2 - 1):
        var4 = var1[var2][var2 + var3]
        var1[var2][var2 + var3] = var1[length - 1 - var2 - var3][var2]
        var1[length - 1 - var2 - var3][var2] = var1[length - 1 - var2][length - 1 - var2 - var3]
        var1[length - 1 - var2][length - 1 - var2 - var3] = var1[var2 + var3][length - 1 - var2]
        var1[var2 + var3][length - 1 - var2] = var4

correct = [*"oz]{R]3l]]B#50es6O4tL23Etr3c10_F4TD2"]
encrypted = encrypt(getArray(var1, 0, 5), 2) + encrypt(getArray(var1, 1, 4), 1) + encrypt(getArray(var1, 2, 3), 0)

s.add([encrypted[i] == ord(correct[i]) for i in range(36)])
s.check()
m = s.model()
print("SEKAI{"+"".join([chr(m.eval(flag[i]).as_long()) for i in range(36)])+"}")