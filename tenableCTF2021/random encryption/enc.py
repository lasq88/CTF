import random
flag = "flag{n0t_that_r4ndom}"
seeds = []
for i in range(0,len(flag)):
    seeds.append(random.randint(0,10000))

res = []
for i in range(0, len(flag)):
    random.seed(seeds[i])
    rands = []
    for j in range(0,4):
        rands.append(random.randint(0,255))

    res.append(ord(flag[i]) ^ rands[i%4])
    del rands[i%4]
    print(str(rands))

print(res)
print(seeds)