from z3 import *

encoded = [0x56,0x3b,0x6e,0x19]
LENGTH = len(encoded)

s = Solver()
flag = [BitVec("flag%s" % i, 8) for i in range(LENGTH)]

s.add([flag[i] < 127 for i in range(LENGTH)])
s.add([flag[i] > 0 for i in range(LENGTH)])


for i in range(LENGTH):
    if i > 0:
        flag[i] ^= flag[i-1]
    flag[i] ^= flag[i] >> 1
    flag[i] ^= flag[i] >> 2
    flag[i] ^= flag[i] >> 3
    flag[i] ^= flag[i] >> 4

s.add([flag[i] == encoded[i] for i in range(LENGTH)])
if s.check() == sat:
    m = s.model()
    print("".join([chr(c.as_long()) for (_,c) in sorted ([(d, m[d]) for d in m], key = lambda x: str(x[0]))]))
