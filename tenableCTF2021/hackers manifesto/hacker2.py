import sys

f = open('hacker_manifesto.txt','rb')

byte_list = f.read()

sol = []

for i in range(0,len(byte_list))[::3]:
    sol.append((int(byte_list[i]) + int(byte_list[i+1]),chr(int(byte_list[i+2]))))

print(sol)

'''

sorted_by_first = sorted(sol, key=lambda tup: tup[0])

print(''.join([x for _,x in sorted_by_first]))

lolo = {}

for x in sol:
    if x[2] in lolo:
        lolo[x[2]].append(x)
    else:
        lolo[x[2]] = [x]

for l in lolo:
    lolo[l].sort(key=lambda tup: tup[0])
    test = [x for _,_,x in lolo[l]]
    print(''.join(test))

for x in sol:
    if x[2] in "flag{}":
        print(x)

for key in sorted(lolo):
    print("%s: %s" % (key, lolo[key]))

'''