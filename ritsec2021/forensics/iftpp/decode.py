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

#profit!
#RS{P1nG_me_d4T_n0ic3_jp3g_hom1e}