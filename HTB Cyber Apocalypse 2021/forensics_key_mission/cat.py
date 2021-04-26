newmap = {
    2: "Shift",
    4: "a",
    5: "b",
    6: "c",
    7: "d",
    8: "e",
    9: "f",
    10: "g",
    11: "h",
    12: "i",
    13: "j",
    14: "k",
    15: "l",
    16: "m",
    17: "n",
    18: "o",
    19: "p",
    20: "q",
    21: "r",
    22: "s",
    23: "t",
    24: "u",
    25: "v",
    26: "w",
    27: "x",
    28: "y",
    29: "z",
    30: "1",
    31: "2",
    32: "3",
    33: "4",
    34: "5",
    35: "6",
    36: "7",
    37: "8",
    38: "9",
    39: "0",
    40: "\n",
    41: "[esc]",
    43: "    ",
    44: " ",
    45: ["-","_"],
    46: ["=","+"],
    47: ["[","{"],
    48: ["]","}"],
    52: ["'",'"'],
    55: [".",">"],
    56: ["/","?"],
    57: "[CapsLock]",
    79: "[RightArrow]",
    80: "[LetfArrow]"
}
myKeys = open('data.txt')
output = []
for line in myKeys:
    bytesArray = bytearray.fromhex(line.strip())
    shiftVal = ord(bytesArray[:1])
    keyVal = ord(bytesArray[2:3])
    nextVal = ord(bytesArray[3:4])
    if keyVal != 0 and nextVal == 0:
        if keyVal in newmap:
            if shiftVal == 2:
                if keyVal in range(4,40):
                    output.append(newmap[keyVal].upper())
                elif keyVal in range(45,57):
                    output.append(newmap[keyVal][1])
                else:
                    output.append(newmap[keyVal])
            else:
                if keyVal in range(45,57):
                    output.append(newmap[keyVal][0])
                else:
                    output.append(newmap[keyVal])
        elif keyVal == 42:
            output.pop()
        else:
            print("No map found for this value: " + str(keyVal))
print(''.join(output))
#print(output)