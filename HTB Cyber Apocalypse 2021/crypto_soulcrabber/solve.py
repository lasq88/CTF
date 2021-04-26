f1 = open("keys.txt","r")
keys = f1.readlines()
f2 = open("out.txt","r")
ciphertext=f2.read()

flag = ""

for i in range(0,len(keys)):
    flag = flag + chr(int(ciphertext[i*2]+ciphertext[i*2+1],16) ^ int(keys[i],16))

print(flag)