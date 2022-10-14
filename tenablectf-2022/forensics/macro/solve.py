import binascii

f1= open("ciphertext.txt")
f2= open("key.txt")

ct_lines = f1.read().splitlines()
key_lines = f2.read().splitlines()

f1.close()
f2.close()

def xor(ct,key):
    pt = ""
    for i in range(len(ct)):
        pt = pt + chr(ct[i] ^ ord(key[i]))
    return pt

plaintext = ""

for i in range(len(ct_lines)):
    plaintext = plaintext + xor(binascii.unhexlify(ct_lines[i]),key_lines[i])

print(plaintext)