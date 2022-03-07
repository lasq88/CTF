import random
import string
flag = open("flag.txt", "r").readline()
encs= []
my_keys = [random.randint(0, 128) for i in range(7)]
enc = ""
for i in range(len(flag)):
	enc += str(hex(ord(flag[i]) ^ my_keys[i%7])) + " "
encs.append(enc)
with open("encoded.txt", "w+") as f:
	f.write("\n".join(encs))