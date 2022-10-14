import z3

def shift(array):
    num = array[9] & 0x01
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


def find_username():
    solver = z3.Solver()
    array_LENGTH = 10 
    array = [z3.BitVec("c%d" % i, 32) for i in range(array_LENGTH)]
    for i in range(len(array)):
        solver.add(z3.And(array[i] > 32, array[i] <= 126))

    solver.add(z3.And(array[1] == 95, 9531 * array[0] - 6756 * array[1] + 8826 * array[2] - 7295 * array[3] - 4010 * array[4] - 9218 * array[5] + 1136 * array[6] - 77 * array[7] - 9947 * array[8] + 1072 * array[9] == -1722391, 2663 * array[0] - 2620 * array[1] + 1458 * array[2] - 4929 * array[3] - 1772 * array[4] - 5452 * array[5] + 5522 * array[6] + 5795 * array[7] - 5323 * array[8] - 580 * array[9] == -578655, 9576 * array[0] - 7249 * array[1] + 2094 * array[2] - 3690 * array[3] - 8522 * array[4] + 8008 * array[5] + 9082 * array[6] + 8300 * array[7] + 6611 * array[8] + 3141 * array[9] == 2808771, 7179 * array[0] - 5969 * array[1] - 4989 * array[2] - 5826 * array[3] - 4895 * array[4] - 7765 * array[5] - 9941 * array[6] + 3040 * array[7] - 2500 * array[8] + 3765 * array[9] == -2824381, 548 * array[0] - 5100 * array[1] - 2456 * array[2] - 2977 * array[3] - 6128 * array[4] - 5099 * array[5] + 888 * array[6] - 2505 * array[7] + 1132 * array[8] - 4455 * array[9] == -2775532, 1721 * array[0] - 1391 * array[1] - 7181 * array[2] - 8001 * array[3] + 3454 * array[4] - 2644 * array[5] + 845 * array[6] + 7635 * array[7] - 6953 * array[8] + 2635 * array[9] == -984357, 1399 * array[0] - 9992 * array[1] - 8259 * array[2] - 8339 * array[3] - 8954 * array[4] - 8975 * array[5] - 3898 * array[6] - 340 * array[7] - 5328 * array[8] + 1224 * array[9] == -5328888, 647 * array[0] - 7816 * array[1] + 7884 * array[2] - 7008 * array[3] - 8147 * array[4] - 8519 * array[5] + 994 * array[6] + 5833 * array[7] - 6726 * array[8] + 9292 * array[9] == -1430489, 7246 * array[0] - 100 * array[1] - 9831 * array[2] - 1981 * array[3] + 6913 * array[4] + 716 * array[5] + 748 * array[6] - 58 * array[7] + 8702 * array[8] + 7763 * array[9] == 2323434, 3113 * array[0] - 3520 * array[1] - 5650 * array[2] + 153 * array[3] - 9767 * array[4] + 4689 * array[5] - 7674 * array[6] + 400 * array[7] - 7529 * array[8] + 5219 * array[9] == -2081909))

    if solver.check() == z3.sat:
        username = "".join(chr(solver.model()[c].as_long()) for c in array)

    return username

def find_password(password):
    array = [101,89,94,110,36,119,248,172,4,92,123,202,44,121,115,190,252,13,135,171]
    shifted_pass = [ord(x) for x in password]
    for j in range(100):
        shifted_pass = shift(shifted_pass)

    passwd = ""
    for i in range(len(array)):
        passwd = passwd + chr(shifted_pass[0] ^ array[i])
        shifted_pass = shift(shifted_pass)

    return passwd

def main():
    username = find_username()
    print(username)
    password = find_password(username)
    print(password)

if __name__ == '__main__':
    main()