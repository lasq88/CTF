import ecdsa
import random
from Crypto.Cipher import AES
import binascii

def pad(m):
    return m+chr(16-len(m)%16)*(16-len(m)%16)

gen = ecdsa.NIST256p.generator
order = gen.order()
secret = random.randrange(1,order)
 
pub_key = ecdsa.ecdsa.Public_key(gen, gen * secret)
priv_key = ecdsa.ecdsa.Private_key(pub_key, secret)
 
nonce1 = random.randrange(1, 2**127)
nonce2 = nonce1
 
# randomly generate hash value
hash1 = random.randrange(1, order)
hash2 = random.randrange(1, order)
 
sig1 = priv_key.sign(hash1, nonce1)
sig2 = priv_key.sign(hash2, nonce2)

s1 = sig1.s
s2 = sig2.s

print("r: " + str(sig1.r))
print("s1: " + str(s1))
print("s2: " + str(s2))
print("")
print("hashes:")
print(hash1)
print(hash2)
print("")
print("order: " + str(order))
print("")

aes_key = secret.to_bytes(64, byteorder='little')[0:16]

ptxt =  pad("flag{example}")
IV = b'\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0'
cipher = AES.new(aes_key, AES.MODE_CBC, IV)
ctxt = cipher.encrypt(ptxt.encode('utf-8'))

print("Encrypted Flag:")
print(binascii.hexlify(ctxt))