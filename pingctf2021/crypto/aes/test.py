from hashlib import md5
from base64 import b64decode
from base64 import b64encode
import json
import math

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

def _pad(text, block_size):
    """
    Performs padding on the given plaintext to ensure that it is a multiple
    of the given block_size value in the parameter. Uses the PKCS7 standard
    for performing padding.
    """
    no_of_blocks = math.ceil(len(text)/float(block_size))
    pad_value = int(no_of_blocks * block_size - len(text))
    if pad_value == 0:
        return text + chr(block_size) * block_size
    else:
        return text + chr(pad_value) * pad_value

def xor(data, key): 
    return bytearray(a^b for a, b in zip(*map(bytearray, [data, key]))) 

class AESCipher:
    def __init__(self, key, iv):
        self.key = key
        self.iv = iv

    def encrypt(self, data):
        self.cipher = AES.new(self.key, AES.MODE_CBC, self.iv)
        return b64encode(self.cipher.encrypt(pad(data.encode('utf-8'), AES.block_size)))

    def decrypt(self, data):
        raw = b64decode(data)
        self.cipher = AES.new(self.key, AES.MODE_CBC, self.iv)
        return unpad(self.cipher.decrypt(raw), AES.block_size).decode("utf-8", "ignore")
        #return self.cipher.decrypt(raw)


aes = AESCipher(get_random_bytes(AES.block_size), get_random_bytes(AES.block_size))


pt = 'xxxxxxxxxaaaaaaaaaaaaaaaa0000000flag'
json_pt = json.dumps({"m": pt})
print(json_pt)
#encrypted = aes.encrypt(json_pt)
encrypted = "NEnsa/EWjetf/I2ENERbqNW/GcW6ra14qL6SGlbwRbAAAmA29smkBTETb0XqRrIP"
new_pt = '","m":"'
enc_b64 = b64decode(encrypted)
print("encrypted: ", str(encrypted))
#modbyte = (ord(pt[32]) ^ enc_b64[16]) ^ ord('s')
#modified = xor(xor(pt[0:16].encode("utf-8"),encrypted[0:16]),new_pt.encode("utf-8")) + enc_b64[16:]
mods = xor(xor(json_pt[32:39].encode("utf-8"),enc_b64[16:23]),new_pt.encode("utf-8"))
print(json_pt[0:16],",",json_pt[16:23],",",json_pt[23:32],",",json_pt[32:39],",",json_pt[39:])
modified = enc_b64[0:16] + mods + enc_b64[23:]
print("original: ", enc_b64.hex())
print("modified: ", modified.hex())
print("mod base64: ", b64encode(modified))
decrypted = aes.decrypt(b64encode(modified))
print("decrypted: ", decrypted)
print(json.loads(decrypted)["m"])


{'m': 'xxxxxxxxxaaaaaaaaaaaaaaaa0000000flag'}