from Crypto.Cipher import AES
from Crypto.Util import Counter
import os
from randcrack import RandCrack

KEY = os.urandom(16)

#KEY = bytes([0]*16)

def encrypt(plaintext):
    cipher = AES.new(KEY, AES.MODE_CTR, counter=Counter.new(128))
    ciphertext = cipher.encrypt(plaintext)
    return ciphertext.hex()

def decrypt(ciphertext):
    cipher = AES.new(KEY, AES.MODE_CTR, counter=Counter.new(128))
    plaintext = cipher.decrypt(ciphertext)
    return plaintext.decode()


'''
test = b"No right of private conversation was enumerated in the Constitution. I don't suppose it occurred to anyone at the time that it could be prevented."
enc_test = encrypt(test)
print(enc_test)
'''

#enc_test = "464851522838603926f4422a4ca6d81b02f351b454e6f968a324fcc77da30cf979eec57c8675de3bb92f6c21730607066226780a8d4539fcf67f9f5589d150a6c7867140b5a63de2971dc209f480c270882194f288167ed910b64cf627ea6392456fa1b648afd0b239b59652baedc595d4f87634cf7ec4262f8c9581d7f56dc6f836cfe696518ce434ef4616431d4d1b361c"

dec_test = decrypt(bytearray.fromhex(enc_test))

print(dec_test)
