Provided pcap file included two things. First was a HTTP communication containing a "pseudo-RFC" document describing implementation of a custom encrypted file transfer protocol using ICMP. See rfc.txt for the dump of RFC (https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/iftpp/rfc.txt)

In short, protocol first performed shared key exchange and then sent a requested file encrypted with XOR using this key.

The goal was to first recover 2 halves of the key and then calculate the session key using provided algorithm.  Keys could be recovered for 3rd and 4th echo packets (first two were session initiation), it was 16 bytes from 5th to 20th byte:

![bytes](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/iftpp/keys.PNG)

Later it was just about using tshark to dump ICMP data and decrypting using provided key.

`tshark -r iftpp_challenge.pcap -Y "icmp && frame.len > 500" -e data.data -Tfields > data.txt`

One thing not mentioned in RFC was that shorter, initial packets used first 3 bytes for session ID and next 1 byte for data length. Longer packets actually used 2 bytes for data length. Got stuck on this one for a while, but overall managed to get the first blood :)

![first blood](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/iftpp/first_blood.png)

Full script to recover the flag is in decode.py and below:

```python
import base64, hashlib
from itertools import cycle

key1 = "4f163f5f0f9a621d729566c74d10037c" #from pcap
key2 = "52fdfc072182654f163f5f0f9a621d72" #from pcap

key1_2 = [int(key1[i:i+2],16) for i in range(0, len(key1), 2)] + [int(key2[i:i+2],16) for i in range(0, len(key2), 2)] # concat keys

key1_2.sort(reverse=True) #sort in descending order

key_bytes = b''.join([i.to_bytes(1,'big') for i in key1_2]) #convert to bytes

key = base64.b64encode(hashlib.sha1(key_bytes).digest()) #sha1 to base64: hYrXBk2CPiFITJ3t9NCVuXNojLo=


#get chunked data from pcap file using tshark:
#tshark -r iftpp_challenge.pcap -Y "icmp && frame.len > 500" -e data.data -Tfields > data.txt

f = open("data.txt", "r")
chunks = f.readlines()

output = b''

#decrypt data chunk by chunk
#first 5 bytes are session id (3 bytes) and length (1 or 2 bytes debending on length) - this is a little bit unclear in RFC
#last 12 bytes is checksum + flag, 1 byte for newline character put by thsark

for chunk in chunks:
    message = bytearray.fromhex(chunk[5*2:-12*2-1:])
    output = output + b''.join((c^k).to_bytes(1,'big') for c,k in zip(message, cycle(key)))

#write decrypted file

fo = open("flag.jpg", "wb")
fo.write(output)
fo.close()
f.close()
```
