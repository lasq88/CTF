import random

flag = open('flag.txt').read()

def encrypt(text):
    out = ""
    for char in text:
        out += "{:02x}".format(ord(char)^random.randint(13,37))
    return out
 

for i in range(100):
    print(encrypt(flag))