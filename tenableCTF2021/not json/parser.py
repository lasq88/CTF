import sys
import base64

encoded = "wAAAAAIwAB4AAABhYmNkZWZnaGppa2xtbm9wcXJzdHV2d3h5el97fQAEMQCTAAAAEDAABQAAABAxAAsAAAAQMgAAAAAAEDMABgAAABA0ABsAAAAQNQASAAAAEDYADgAAABA3AA0AAAAQOAAaAAAAEDkADgAAABAxMAAFAAAAEDExABoAAAAQMTIAAAAAABAxMwAaAAAAEDE0AAEAAAAQMTUAEgAAABAxNgAOAAAAEDE3AA0AAAAQMTgAHAAAAAAA"

decoded = base64.b64decode(encoded)

translator = {}
header = 0xB
alphabet = 0x1D
junk= 0x8

for x in range(alphabet):
    translator[x] = chr(decoded[header+x])

flag=[None]*19
for i in range(header+alphabet+junk,len(decoded)):
    if decoded[i] == 0x10:
        if decoded[i+2] == 0:
             flag[int(chr(decoded[i+1]))] = translator[decoded[i+3]]
        else:
            flag[int(chr(decoded[i+1]) + chr(decoded[i+2]))] = translator[decoded[i+4]]

print(''.join(flag))
        