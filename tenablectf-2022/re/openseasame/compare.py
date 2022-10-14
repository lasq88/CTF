pre = '1234{abcdefghijklmnopqrstuvwxyzAB}'
pre_arr = [ord(x) for x in pre]
post_arr = [ 121, 114, 119, 98, 125, 115, 65, 112, 111, 105, 120, 66, 50, 118, 117, 102, 101, 49, 52, 51, 116, 100, 99, 110, 109, 104, 103, 122, 123, 97, 107, 106, 113, 108]

shifted_flag = "__1h}kup1t37ldD3lfga1_0r5_tO{wEH7_"
flag = ""

for i in range(34):
    flag = flag + shifted_flag[post_arr.index(pre_arr[i])]
print(flag)



