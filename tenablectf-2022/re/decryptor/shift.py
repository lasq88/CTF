passwd = "p_atreides"
pass_array = [ord(x) for x in passwd]

def shift(array):
    num = array[9]shift & 0x01
    num2 = (array[9] & 0x4) >> 2
    num3 = (array[9] & 0x10) >> 4
    num4 = ((array[8] & 0x02) >> 1) ^ num3 ^ num2 ^ num
    num5 = 0
    for i in range(10):
        num6 = array[i] & 0x01
        array[i] = array[i] >> 1
        if i > 0:
            array[i] = array[i] | num5 << 7
        else:
            array[i] = array[i] | num4 << 7
        num5 = num6
    return array

for i in range(100):
    pass_array = shift(pass_array)

print(pass_array)