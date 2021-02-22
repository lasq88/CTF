import socket
import sys
import re

flag = 'flag{'

octets = [2,119,16,51]
byte = 0x11
ip = socket.gethostbyname('challenges.ctfd.io')
server_address = (ip, 30468)
c = 0

for i in range(32):
    for octet in octets:
        next_byte = octet ^ byte
        if next_byte in range(32,127):
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            print('connecting to %s port %s' % server_address, file=sys.stderr)
            sock.connect(server_address)
            try:
                amount_received = 0
                amount_expected = 85
                
                data = b''
                while amount_received < amount_expected:
                    data = data + sock.recv(16)
                    amount_received = len(data)
                
                print(data.decode("utf-8"))

                # Send data
                message = (flag+ chr(next_byte) +"\n").encode()
                print('sending "%s"' % message)
                sock.send(message)

                # Look for the response
                amount_received = 0
                amount_expected = 54
                
                data = b''
                while amount_received < amount_expected:
                    data = data + sock.recv(16)
                    amount_received = len(data)
                
                response = data.decode("utf-8")
                if 'Flag does not start with characters entered' in response:
                    print(response)
                    if c == 3:
                        exit()
                    else:
                        c = c+1
                elif 'You seem to know the first' in response:
                    c = 0
                    amount_expected = 162
                    while amount_received < amount_expected:
                        data = data + sock.recv(16)
                        amount_received = len(data)

                    response = data.decode("utf-8")
                    print(response)                    
                    flag = flag+chr(next_byte)
                    byte = int(re.findall("0x[0-9a-f]{1,2}",response)[0],16)
                    break
                else:
                    print(response)
                    print(flag+chr(next_byte))
                    exit()
        
            finally:
                sock.close()