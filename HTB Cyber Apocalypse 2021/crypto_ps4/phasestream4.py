from Crypto.Cipher import AES
from Crypto.Util import Counter
import os

KEY = os.urandom(16)


def encrypt(plaintext):
    cipher = AES.new(KEY, AES.MODE_CTR, counter=Counter.new(128))
    ciphertext = cipher.encrypt(plaintext)
    return ciphertext.hex()


with open('test_quote.txt', 'rb') as f:
    test_quote = f.read().strip()
print(encrypt(test_quote))

with open('flag.txt', 'rb') as f:
    flag = f.read().strip()
print(encrypt(flag))
