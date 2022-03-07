from hashlib import md5
from base64 import b64decode
from base64 import b64encode
import json
import string

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad


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
        
        


aes = AESCipher(get_random_bytes(AES.block_size), get_random_bytes(AES.block_size))

while True:
    print('''Chose option:
1. Encrypt your message
2. Talk to me (I accept only encrypted messages)''')
    option = input();
    
    if option == "1": 
        print("Type message you want to encrypt: ")
        message = input()
        if message == "flag":
            print("Im sorry you cant encrypt this message")
            continue
        print("Your encrypted message: ", str(aes.encrypt(json.dumps({"m": message}))))
        
    
    if option == "2":
        print("Send me encrypted message: ")
        
        try:
            message = json.loads(aes.decrypt(input()))
            print("Your message: ", message)
            
            if message["m"] == "hi":
                print("Hello")
                
            if message["m"] == "ping":
                print("pong")
            
            if message["m"] == "flag":
                print("[REDACTED]")
                
        except Exception as e:
            print("There was an error while reading your message :(")
            continue
        