import z3

def find_solution():
    solver = z3.Solver()
    array_LENGTH = 34
    array = [z3.BitVec("c%d" % i, 32) for i in range(array_LENGTH)]
    for i in range(len(array)):
        solver.add(z3.And(array[i] > 00, array[i] <= 0xff))

    #equation taken from x5
    solver.add(z3.And(array[7] + array[15] == 163, array[31] + array[13] == 172, array[23] + array[32] == 169, array[20] + array[17] == 151, array[27] + array[14] == 147, array[18] == 103, array[25] - array[12] == -13, array[11] * array[10] == 2805, array[5] - array[26] == -9, array[30] * array[9] == 8004, array[3] * array[0] == 9880, array[29] + array[22] == 167, array[24] - array[4] == -72, array[16] + array[1] == 203, array[8] == 49, array[28] - array[2] == 74, array[21] * array[6] == 11115, array[19] + array[33] == 192, array[7] - array[15] == 61, array[31] + array[13] == 172, array[23] - array[32] == 59, array[20] + array[17] == 151, array[27] - array[14] == 11, array[18] * array[25] == 9785, array[12] - array[11] == 53, array[10] - array[5] == -56, array[26] + array[30] == 185, array[9] - array[3] == 12, array[0] - array[29] == -24, array[22] == 48, array[24] * array[4] == 6625, array[16] == 108, array[1] == 95, array[8] + array[28] == 172, array[2] * array[21] == 4655, array[6] * array[19] == 11349, array[33] == 95, array[7] + array[15] == 163, array[31] == 72, array[13] - array[23] == -14, array[32] == 55, array[20] * array[17] == 4998, array[27] * array[14] == 5372, array[18] * array[25] == 9785, array[12] * array[11] == 5940, array[10] == 51, array[5] - array[26] == -9, array[30] * array[9] == 8004, array[3] == 104, array[0] + array[29] == 214, array[22] == 48, array[24] - array[4] == -72, array[16] + array[1] == 203, array[8] + array[28] == 172, array[2] + array[21] == 144, array[6] == 117, array[19] + array[33] == 192, array[7] == 112, array[15] + array[31] == 123, array[13] * array[23] == 11400, array[32] * array[20] == 2695, array[17] + array[27] == 181, array[14] + array[18] == 171, array[25] + array[12] == 203, array[11] * array[10] == 2805, array[5] - array[26] == -9, array[30] - array[9] == -47, array[3] * array[0] == 9880, array[4] == 125))

    if solver.check() == z3.sat:
        solution = "".join(chr(solver.model()[c].as_long()) for c in array)

    return solution

def main():
    solution = find_solution()
    pre = '1234{abcdefghijklmnopqrstuvwxyzAB}'
    pre_arr = [ord(x) for x in pre]
    #this below part is taken from the debugger after x4
    post_arr = [ 121, 114, 119, 98, 125, 115, 65, 112, 111, 105, 120, 66, 50, 118, 117, 102, 101, 49, 52, 51, 116, 100, 99, 110, 109, 104, 103, 122, 123, 97, 107, 106, 113, 108]

    shifted_flag = solution
    flag = ""

    for i in range(34):
        flag = flag + shifted_flag[post_arr.index(pre_arr[i])]
    print(flag)

if __name__ == '__main__':
    main()